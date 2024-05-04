
#include"GameObject.h"
#include<string>

void GameObject::initializeGame() {
    std::cout << "start init SDL\n";
    initSDL(window, renderer);
    std::cout << "ok init window and renderer\n";
    std::cout << " start init properties Game\n";

    startTime = SDL_GetTicks()/1000;
    gameState = GameState::Intro;
    map = new Map(renderer);
    menu->initMenuGame(renderer);
    pause = new Texture(SCREEN_WIDTH/2-PAUSE_WIDTH/2, SCREEN_HEIGHT/2-PAUSE_HEIGHT/2, PAUSE_WIDTH, PAUSE_HEIGHT);
    pause->setImageTexture(IMAGE_PAUSE_GAME_PATH, renderer);
    highScore = takeHighScore();
    HighScore = new Texture(SCREEN_WIDTH/2 - 80, 0, 80, 50);
    HighScore->setText(std::to_string(highScore), RED_COLOR, FONT_PATH, renderer);

    std::cout << "ok init map*->init player*\n";
    player = new PlayerObject(renderer);
    std::cout << "ok init player* -> start init obstacle*\n";
   
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
    delete map;
    std::cout << "ok delete map-> start delete player*\n";
    delete player;
    std::cout << "ok delete player*->delete bossMonster*\n";
    delete boss;      
    std::cout << "ok delete player* -> delete normalMonster*[]\n";
    delete[] normalMonster;
    delete[] lazerMonster;      

    std::cout << " Destroy SDL\n";
    quitSDL(window, renderer);
    std::cout << "ok ~Game\n";
}

void GameObject::renderGame() {
    SDL_RenderClear(renderer);
    if (gameState == GameState::Play) {
        map->renderMap(renderer);
        //std::cout << "start renderGame\n";
        renderHighScore();

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
    SDL_Delay(20);
}

void GameObject::gamePlay() {
    while (gameState==GameState::Play) {       
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                std::cout << "e.type==Quit\n";
                gameState = GameState::Quit;
                break;
            }
            else if (e.type == SDL_KEYDOWN) {                
                player->handleMoveAction(map);
                player->attackThreat(e);
                //map->updateCamera(player->getCoordinates());
            }
            else if (e.type == SDL_MOUSEBUTTONDOWN) {
                int x, y;
                SDL_GetMouseState(&x, &y);
                if (x >= SCREEN_WIDTH - 50 && x <= SCREEN_WIDTH && y >= 0 && y <= 50) {      
                    pause->render(50, renderer);
                    gameState = GameState::Pause;
                    pauseGame();
                }
            }
        }        
        handleNormalMonster();
        handleLazerMonster();
        handleBossMonster();       
        nextTurnMonsterAttack();

        if (isOver())
            newTurn();

        renderGame();
        SDL_Delay(50);
    }     
}

void GameObject::gameIntro() {
    while (gameState == GameState::Intro) {
        //playAudio(gameIntroAudio);
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
        //playAudio(chibichibiAudio);
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
    std::cout << startTime << std::endl;
    while (gameState != GameState::Quit) {
        gameIntro();
        gamePlay();
        gameOver();
    } 
}

void GameObject::handleNormalMonster() {
    for (int i = 0; i < AMOUNT_NORMAL_MONSTER; i++) {
        if (normalMonster[i].isDead()) {
            if (normalMonster[i].isCount) {
                player->updateScore(POINT_NORMAL_MONSTER, renderer);
                normalMonster[i].isCount = false;
            }
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
                    normalMonster[i].normalMonsterBullet[j].setCoordinates(-100, -100);
                }
                if (checkCollision(player->getCoordinatesAnimation(), normalMonster[i].normalMonsterBullet[j].getCoordinates())) {
                    normalMonster[i].normalMonsterBullet[j].setCoordinates(-100, -100);
                }
            }
            if (checkCollision(player->getCoordinatesAnimation(), normalMonster[i].getCoordinates())) {
                normalMonster[i].getDamage(DEFAUT_DAMAGE_PLAYER);
                player->playerSkill->setCoordinates(-100, -100);
                std::cout << "slash slash ok\n";
            }
        }
    }
}

void GameObject::handleLazerMonster() {
    for (int i = 0; i < AMOUNT_LAZER_MONSTER; i++) {
        if (lazerMonster[i].isDead()) {
            if (lazerMonster[i].isCount) {
                player->updateScore(POINT_LAZER_MONSTER, renderer);
                lazerMonster[i].isCount = false;
            }
            lazerMonster[i].setCoordinates(-100, -100);
            //player->updateScore(POINT_LAZER_MONSTER, renderer);
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
            if (checkCollision(player->getCoordinatesAnimation(), lazerMonster[i].getCoordinates())) {
                lazerMonster[i].getDamage(DEFAUT_DAMAGE_PLAYER);
                player->playerSkill->setCoordinates(-100, -100);
                std::cout << "slash slash ok\n";
            }
        }
    }
}

void GameObject::handleBossMonster() {
    boss->BossMove();
    if (checkCollision(player->getCoordinates(), boss->getCoordinates())) {
        player->getDamge(DAMAGE_BOSS_MONSTER);
    }
    if (checkCollision(player->getCoordinatesAnimation(), boss->getCoordinates())) {
        boss->getDamage(DEFAUT_DAMAGE_PLAYER);
        player->playerSkill->setCoordinates(-100, -100);
    }
    for (int j = 0; j < AMOUNT_BULLET_BOSS_MONSTER; j++) {
        boss->bulletBossMonster[j].BulletMove();
        if (checkCollision(player->getCoordinates(), boss->bulletBossMonster[j].getCoordinates())) {
            player->getDamge(DAMAGE_BOSS_MONSTER);
            boss->bulletBossMonster[j].setCoordinates(-50, -100);
        }
        if (checkCollision(player->getCoordinatesAnimation(), boss->bulletBossMonster[j].getCoordinates())) {
            boss->bulletBossMonster[j].setCoordinates(-50, -100);
        }
    }
}

void GameObject::newTurn() {
    player->setUpNewTurn();
    for (int i = 0; i < AMOUNT_NORMAL_MONSTER; i++) {
        normalMonster[i].setUpNewTurn(HP_NORMAL_MONSTER, PosXListNormalMonster[i], PosYListNormalMonster[i]);
    }
    for (int i = 0; i < AMOUNT_LAZER_MONSTER; i++) {
        lazerMonster[i].setUpNewTurn(HP_LAZER_MONSTER, PosXListLazerMonster[i], PosYListLazerMonster[i]);
    }
    boss->setUpNewTurn(HP_BOSS_MONSTER, 900, 300);
   
}

void GameObject::nextTurnMonsterAttack() {
    Uint32 currentTime = SDL_GetTicks()/1000;
    if (currentTime - startTime >= 4) {
        for (int i = 0; i < AMOUNT_NORMAL_MONSTER; i++) {
            normalMonster[i].setNewTurnBullet();
        }
        for (int j = 0; j < AMOUNT_BULLET_BOSS_MONSTER; j++) {
            boss->setNewTurnBullet();
        }
        startTime = currentTime;
    }
}

bool GameObject::isOver() {
    if (boss->isDead()) {
        gameState = GameState::Victory;
        return true;
        //break;
    }
    if (player->isDead()) {
        gameState = GameState::Defeat;
        return true;
    }
    return false;
}

void GameObject::pauseGame(){
    pause->render(PAUSE_WIDTH, renderer);
    SDL_RenderPresent(renderer);
    while (gameState == GameState::Pause) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                gameState = GameState::Quit;
                break;
            }
            else if (e.type == SDL_MOUSEBUTTONDOWN) {
                int x, y;
                SDL_GetMouseState(&x, &y);
                if (x >= 445 && x <= 505 && y >= 335 && y <= 390) {
                    newTurn();
                    gameState = GameState::Intro;                   
                }
                else if (x >= SCREEN_WIDTH/2 - PAUSE_WIDTH/2 && x <= SCREEN_WIDTH/2 + PAUSE_WIDTH/2 && y >= 0 && y <= 590) {
                    gameState = GameState::Play;
                    countdown();
                }
                else if (x >= 690 && x <= 750 && y >= 335 && y <= 390) {
                    gameState = GameState::Quit;
                }
            }
        }        
    }
    
}

int GameObject::takeHighScore() {
    std::ifstream inFile("HighScore.txt");
    int getScore;
    while (!inFile.eof()) {
        inFile >> getScore;
    }
    inFile.close();
    return getScore;
}

void GameObject::renderHighScore() {
    HighScore->setText(std::to_string(highScore), RED_COLOR, FONT_PATH, renderer);
    HighScore->render(80, renderer);
}

void GameObject::countdown() {   
    int countDown = 3;
    Texture countdownTexture(SCREEN_WIDTH/2-80, SCREEN_HEIGHT/2-80, 80, 80);
    while (countDown >= 0) {
        SDL_RenderClear(renderer);
        renderGame();
        countdownTexture.setText(std::to_string(countDown), LIGHT_BLUE_COLOR, FONT_PATH, renderer);
        countdownTexture.render(80, renderer);
        SDL_RenderPresent(renderer);
        SDL_Delay(1000);
        countDown--;
    }    
}