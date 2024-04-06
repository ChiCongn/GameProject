
#include"GameObject.h"
#include<string>

void GameObject::initializeGame(SDL_Renderer* renderer) {
    std::cout << " start initGame\n";
    gameState = GameState::Play;
    map = loadImage(MAP_PATH, renderer);
    player->initializePlayer(renderer);
    for (int i = 0; i < 12; i++) {
        obstacle[i].initializeObstacle(obstaclePos[i], renderer);
    }
    for (int i = 0; i < AMOUNT_NORMAL_MONSTER; i++) {
        normalMonster[i].initNormalMonster(PosXListNormalMonster[i],PosYListNormalMonster[i],BULLET_NORMAL_MONSTER_PATH, renderer);
    }
    for (int i = 0; i < AMOUNT_LAZER_MONSTER; i++) {
        lazerMonster[i].initLazerMonster(PosXListLazerMonster[i], PosYListLazerMonster[i], renderer);
    }
    boss->initBossMonster(900, 300, BULLET_BOSS_MONSTER_PATH, renderer);
    std::cout << "ok initGame\n";
}

GameObject::GameObject(SDL_Renderer* renderer) {
    initializeGame(renderer);
}

GameObject::~GameObject() {
    std::cout << "start destructor gameObject\n";
    if (map != nullptr) {
        SDL_DestroyTexture(map);
        map = nullptr;
    }
    /*player->~PlayerObject();
    std::cout << "ok~player-> start ~boss\n";   
    boss->~BossMonster();    
    std::cout << "ok ~boss-> ~ start normalMonster\n";
   
    for (int i = 0; i < AMOUNT_NORMAL_MONSTER; i++) {
        normalMonster[i].~NormalMonster();
    }    
    std::cout << "ok~normalMonster-> start~ lazerMonster\n";
      
    
    for (int i = 0; i < AMOUNT_LAZER_MONSTER; i++) {
        lazerMonster[i].~LazerMonster();
    }   */
    delete boss;
    delete player;
    delete[] normalMonster;
    delete[] lazerMonster;   
    delete[] obstacle;       
    std::cout << "ok ~Game";
}

void GameObject::renderGame(SDL_Renderer* renderer) {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, map, NULL, NULL);
    //std::cout << "start renderGame\n";
    player->renderPlayer(renderer);
    boss->renderBossMonster(renderer);
    for (int j = 0; j < AMOUNT_BULLET_BOSS_MONSTER; j++) {
        boss->bulletBossMonster[j].renderBullet(renderer);
    }
    for (int i = 0; i < AMOUNT_NORMAL_MONSTER; i++) {       
        normalMonster[i].render(renderer);
    }
    for (int i = 0; i < AMOUNT_LAZER_MONSTER; i++) {
        lazerMonster[i].render(renderer);
    }
    
    /*for (int i = 0; i < 12; i++) {
        obstacle[i].renderObstacle(renderer);
    }*/
    //std::cout << "ok renderGame\n";
    SDL_RenderPresent(renderer);
}

void GameObject::gamePlay(SDL_Event& e, SDL_Renderer* renderer) {
    Uint32 preTime = SDL_GetTicks() / 1000;
    while (gameState==GameState::Play) {       
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                std::cout << "e.type==Quit\n";
                gameState = GameState::Quit;
                break;
            }
            else if (e.type == SDL_KEYDOWN) {
                //std::cout << "start gamePlay\n";
                player->playerMove(e, obstaclePos);
            }
            else {
                ;
            }
        }    
        Uint32 curTime = SDL_GetTicks() / 1000;
        for (int i = 0; i < AMOUNT_NORMAL_MONSTER; i++) {
            if (!normalMonster[i].isDead()) {                
                normalMonster[i].normalMonsterMove(obstaclePos);
                if (checkCollision(player->getCoordinates(), normalMonster[i].getCoordinates())) {
                    player->getDamge(DAMAGE_NORMAL_MONSTER);
                    normalMonster[i].getDamage(DEFAUT_DAMAGE_PLAYER);
                    
                }
                for (int j = 0; j < AMOUNT_BULLET_NORMAL_MONSTER; j++) {
                    normalMonster[i].normalMonsterBullet[j].BulletMove();
                    if (checkCollision(player->getCoordinates(), normalMonster[i].normalMonsterBullet[j].getCoordinates())) {
                        player->getDamge(DAMAGE_NORMAL_MONSTER);
                        normalMonster[i].normalMonsterBullet[j].setCoordinates(-50,-100);
                    }
                }
            }     
            else {
                normalMonster[i].setCoordinates(-50, -50);
            }
        }
               
        boss->BossMove();   
        if (checkCollision(player->getCoordinates(), boss->getCoordinates())) {
            player->getDamge(DAMAGE_BOSS_MONSTER);
        }
        for (int j = 0; j < AMOUNT_BULLET_BOSS_MONSTER; j++) {
            boss->bulletBossMonster[j].BulletMove();
            if (checkCollision(player->getCoordinates(), boss->bulletBossMonster[j].getCoordinates())) {
                player->getDamge(DAMAGE_BOSS_MONSTER);
                boss->bulletBossMonster[j].setCoordinates(-50,-100);
            }
        }       
        if (curTime - preTime >= 4) {
            for (int i = 0; i < AMOUNT_NORMAL_MONSTER; i++) {
                normalMonster[i].setNewTurnBullet();
            }
            for (int j = 0; j < AMOUNT_BULLET_BOSS_MONSTER; j++) {
                boss->setNewTurnBullet();
            }
            preTime = curTime;
        }
        if (player->isDead()) {
            gameState = GameState::GameOver;
        }
        /*for (int i = 0; i < AMOUNT_LAZER_MONSTER; i++) {
            lazerMonster[i].render(renderer);
        }*/
        renderGame(renderer);
        SDL_Delay(50);
    }     
}