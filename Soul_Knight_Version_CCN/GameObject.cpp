
#include"GameObject.h"
#include<string>

void GameObject::initializeGame() {
    std::cout << "start init SDL\n";
    initSDL(window, renderer);
    std::cout << "ok init window and renderer\n";
    std::cout << " start init properties Game\n";
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

GameObject::GameObject() {
    initializeGame();
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

    std::cout << " Destroy SDL\n";
    quitSDL(window, renderer);
    std::cout << "ok ~Game\n";
}

void GameObject::renderGame() {
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

void GameObject::gamePlay() {
    Uint32 preTime = SDL_GetTicks() / 1000;
   /* Uint32 preTimeCollisionNormalMonster = SDL_GetTicks() / 100;
    Uint32 preTimeCollisionBossMonster, preTimeCollisionLazerMonster;
    preTimeCollisionBossMonster = preTimeCollisionLazerMonster = preTimeCollisionNormalMonster;*/
   // Uint32 preTimeCollision
    while (gameState==GameState::Play) {       
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                std::cout << "e.type==Quit\n";
                gameState = GameState::Quit;
                break;
            }
            else if (e.type == SDL_KEYDOWN) {
                //std::cout << "gameState== GameState::Play => PLAY\n";
                player->playerMove(e,obstaclePos);
                player->attackThreat(e);
            }
            else {
                ;
            }
        }    
        Uint32 currentTime = SDL_GetTicks() / 1000;
        for (int i = 0; i < AMOUNT_NORMAL_MONSTER; i++) {
            if (normalMonster[i].isDead()) {
                normalMonster[i].setCoordinates(-50, -50);
            }
            else {                
                normalMonster[i].normalMonsterMove(obstaclePos);
                if (checkCollision(player->getCoordinates(), normalMonster[i].getCoordinates())) {        
                    normalMonster[i].updateCurrentTime();
                    if (normalMonster[i].isReadyCauseDamage()) {
                        player->getDamge(DAMAGE_NORMAL_MONSTER);
                        //normalMonster[i].getDamage(DEFAUT_DAMAGE_PLAYER);
                        std::cout << "collision player and Normal Monster\n";
                        normalMonster[i].updatePreTimeCollision();
                    }
                    
                }
                for (int j = 0; j < AMOUNT_BULLET_NORMAL_MONSTER; j++) {
                    normalMonster[i].normalMonsterBullet[j].BulletMove();
                    if (checkCollision(player->getCoordinates(), normalMonster[i].normalMonsterBullet[j].getCoordinates())) {
                        player->getDamge(DAMAGE_NORMAL_MONSTER);
                        normalMonster[i].normalMonsterBullet[j].setCoordinates(-100,-100);
                    }
                    if (checkCollision(player->getCoordinatesAnimatedSprite(), normalMonster[i].normalMonsterBullet[j].getCoordinates())) {
                        normalMonster[i].normalMonsterBullet[j].setCoordinates(-100, -100);
                    }
                }
                if (checkCollision(player->getCoordinatesAnimatedSprite(), normalMonster[i].getCoordinates())) {
                    normalMonster[i].getDamage(DEFAUT_DAMAGE_PLAYER);
                    std::cout << "slash slash ok\n";
                }
            }                
        }
        for (int i = 0; i < AMOUNT_LAZER_MONSTER; i++) {
            if (lazerMonster[i].isDead()) {
                lazerMonster[i].setCoordinates(-100, -100);
            }
            else {
                lazerMonster[i].lazerMonsterMove();
                if (checkCollision(player->getCoordinates(), lazerMonster[i].getCoordinates())) {
                    lazerMonster[i].updateCurrentTime();
                    if (lazerMonster[i].isReadyCauseDamage()) {
                        player->getDamge(DAMAGE_LAZER_MONSTER);
                        //normalMonster[i].getDamage(DEFAUT_DAMAGE_PLAYER);
                        std::cout << "collision player and Normal Monster\n";
                        lazerMonster[i].updatePreTimeCollision();
                    }
                }
                if (checkCollision(player->getCoordinatesAnimatedSprite(), lazerMonster[i].getCoordinates())) {
                    lazerMonster[i].getDamage(DEFAUT_DAMAGE_PLAYER);
                    std::cout << "slash slash ok\n";
                }
            }            
        }

        boss->BossMove();   
        if (checkCollision(player->getCoordinates(), boss->getCoordinates())) {
            player->getDamge(DAMAGE_BOSS_MONSTER);
        }
        if (checkCollision(player->getCoordinatesAnimatedSprite(), boss->getCoordinates())) {
            boss->getDamage(DEFAUT_DAMAGE_PLAYER);
        }
        for (int j = 0; j < AMOUNT_BULLET_BOSS_MONSTER; j++) {
            boss->bulletBossMonster[j].BulletMove();
            if (checkCollision(player->getCoordinates(), boss->bulletBossMonster[j].getCoordinates())) {
                player->getDamge(DAMAGE_BOSS_MONSTER);
                boss->bulletBossMonster[j].setCoordinates(-50,-100);
            }
            if (checkCollision(player->getCoordinatesAnimatedSprite(), boss->bulletBossMonster[j].getCoordinates())) {
                boss->bulletBossMonster[j].setCoordinates(-50, -100);
            }
        }       
        if (currentTime - preTime >= 4) {
            for (int i = 0; i < AMOUNT_NORMAL_MONSTER; i++) {
                normalMonster[i].setNewTurnBullet();
            }
            for (int j = 0; j < AMOUNT_BULLET_BOSS_MONSTER; j++) {
                boss->setNewTurnBullet();
            }
            preTime = currentTime;
        }

        if (boss->isDead()) {
            gameState = GameState::Victory;
            //break;
        }
        if (player->isDead()) {
            gameState = GameState::Defeat;            
        }
        if (gameState == GameState::Defeat || gameState == GameState::Victory) {
            player->setUpNewTurn();
            for (int i = 0; i < AMOUNT_NORMAL_MONSTER; i++) {
                normalMonster[i].setUpNewTurn(HP_NORMAL_MONSTER, PosXListNormalMonster[i], PosYListNormalMonster[i]);
            }
            for (int i = 0; i < AMOUNT_LAZER_MONSTER; i++) {
                lazerMonster[i].setUpNewTurn(HP_LAZER_MONSTER, PosXListLazerMonster[i], PosYListLazerMonster[i]);
            }
            boss->setUpNewTurn(HP_BOSS_MONSTER, 900, 300);
        }
        /*for (int i = 0; i < AMOUNT_LAZER_MONSTER; i++) {
            lazerMonster[i].render(renderer);
        }*/
        renderGame();
        SDL_Delay(50);
    }     
}

void GameObject::gameIntro() {
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
        renderGame();
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
            renderGame();
        }
    }
      
}

void GameObject::gameOver() {
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
        renderGame();
    }   
}

void GameObject::Running() {
    while (gameState != GameState::Quit) {
        gameIntro();
        gamePlay();
        gameOver();
    } 
}