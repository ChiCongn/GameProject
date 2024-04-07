
#include"GameObject.h"
#include<string>

void GameObject::initializeGame(SDL_Renderer* renderer) {
    std::cout << " start initGame\n";
    gameState = GameState::Intro;
    map = loadImage(MAP_PATH, renderer);
    menu->initMenuGame(renderer);
    std::cout << "ok init map*->init player*\n";
    player-> initPlayer(renderer);
    std::cout << "ok init player* -> start init obstacle*\n";
    for (int i = 0; i < 12; i++) {
        obstacle[i].initializeObstacle(obstaclePos[i], renderer);
    }
    std::cout << "ok init obstacle-> start init normalMonster*\n";
    for (int i = 0; i < AMOUNT_NORMAL_MONSTER; i++) {
        normalMonster[i].initNormalMonster(PosXListNormalMonster[i],PosYListNormalMonster[i], IMAGE_BULLET_NORMAL_MONSTER_PATH, renderer);
    }
    std::cout << "ok init normalMonster* -> start init lazerMonster*\n";
    for (int i = 0; i < AMOUNT_LAZER_MONSTER; i++) {
        lazerMonster[i].initLazerMonster(PosXListLazerMonster[i], PosYListLazerMonster[i], renderer);
    }
    std::cout << "ok init lazerMonster*-> start init bossMonster*\n";
    boss->initBossMonster(900, 300, IMAGE_BULLET_BOSS_MONSTER_PATH, renderer);
    std::cout << "start init audio\n";
    gameDefeatAudio = loadAudio(AUDIO_GAME_DEFEAT_PATH);
    gameVictoryAudio = loadAudio(AUDIO_GAME_VICTORY_PATH);
    gameIntroAudio = loadAudio(AUDIO_GAME_INTRO_PATH);
    chibichibiAudio = loadAudio(AUDIO_CHIBI_CHIBI_PATH);
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
    std::cout << "ok delete map-> start delete player*\n";
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
    delete player;
    std::cout << "ok delete player*->delete bossMonster*\n";
    delete boss;      
    std::cout << "ok delete player* -> delete normalMonster*[]\n";
    delete[] normalMonster;
    delete[] lazerMonster;   
    delete[] obstacle;       
    std::cout << "ok ~Game";
}

void GameObject::renderGame(SDL_Renderer* renderer) {
    SDL_RenderClear(renderer);
    if (gameState == GameState::Play) {
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
    } 
    else {
        //std::cout << "Render menuGame\n";
        menu->renderMenuGame(renderer, gameState);
    }
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
                //std::cout << "gameState== GameState::Play => PLAY\n";
                player->playerMove(e, obstaclePos);
                player->attackThreat(e);
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
        for (int i = 0; i < AMOUNT_LAZER_MONSTER; i++) {
            lazerMonster[i].lazerMonsterMove();
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
            gameState = GameState::Defeat;
        }
        /*for (int i = 0; i < AMOUNT_LAZER_MONSTER; i++) {
            lazerMonster[i].render(renderer);
        }*/
        renderGame(renderer);
        SDL_Delay(50);
    }     
}

void GameObject::gameIntro(SDL_Event& e, SDL_Renderer* renderer) {
    while (gameState == GameState::Intro) {
        playAudio(gameIntroAudio);
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                std::cout << "e.type==Quit\n";
                gameState = GameState::Quit;
                break;
            }
            else if (e.type == SDL_MOUSEBUTTONDOWN) {
                int x, y;
                SDL_GetMouseState(&x, &y);
                if (x >= 420 && x <= 770) {
                    if (y >= 100 && y <= 195) {
                        gameState = GameState::Play;
                        break;
                    }
                    else if (y >= 270 && y <= 360) {
                        gameState = GameState::Instruction;
                        break;
                    }
                    else if (y >= 440 && y <= 535) {
                        gameState = GameState::Quit;
                        break;
                    }
                    else {
                        ;
                    }
                }
            }
            else {
                ;
            }
        }
        renderGame(renderer);
        while (gameState == GameState::Instruction) {
            while (SDL_PollEvent(&e) != 0) {
                if (e.type == SDL_QUIT) {
                    std::cout << "e.type==Quit\n";
                    gameState = GameState::Quit;
                    break;
                }
                else if (e.type == SDL_MOUSEBUTTONDOWN) {
                    int x, y;
                    SDL_GetMouseState(&x, &y);
                    if (x >= 1100 && x <= SCREEN_WIDTH && y >= 0 && y <= 100) {
                        gameState = GameState::Intro;
                        break;
                    }
                }
            }
            renderGame(renderer);
        }
    }
      
}

void GameObject::gameOver(SDL_Event& e, SDL_Renderer* renderer) {
    while (gameState == GameState::Victory || gameState == GameState::Defeat) {
        playAudio(chibichibiAudio);
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                std::cout << "e.type==Quit\n";
                gameState = GameState::Quit;
                break;
            }
            else if (e.type == SDL_MOUSEBUTTONDOWN) {
                int x, y;
                SDL_GetMouseState(&x, &y);
                if (x >= 370 && x <= 740 && y >= 300 && y <= 400) {
                    gameState = GameState::Play;
                    break;
                }
                else if (x>=370 && x<=740 && y>=470 && y<=570){
                    gameState = GameState::Quit;
                    break;
                }
            }
        }
        renderGame(renderer);
    }   
}

void GameObject::Running(SDL_Event& e, SDL_Renderer* renderer) {
    gameIntro(e, renderer);
    gamePlay(e, renderer);
    gameOver(e, renderer);
}