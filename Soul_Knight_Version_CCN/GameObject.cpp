
#include"GameObject.h"
#include<string>

void GameObject::initializeGame() {
    std::cout << "start Game init SDL\n";
    initSDL(window, renderer);

    gameState = GameState::Intro;
    menu = new MenuGame(renderer);
    map = new Map(MAP_PATH, renderer);

    time = new Texture(1095, 450, 50, 35);
    time->setText("0", BLACK_COLOR, FONT_PATH, renderer);
    pause = new Texture(SCREEN_WIDTH/2-PAUSE_WIDTH/2, SCREEN_HEIGHT/2-PAUSE_HEIGHT/2, PAUSE_WIDTH, PAUSE_HEIGHT);
    pause->setImageTexture(PAUSE_GAME_PATH, renderer);
    std::cout << "ok init time...\n";

    tower = new Structure * [AMOUNT_STRUCTURE];
    for (int i = 0; i < AMOUNT_STRUCTURE; i++) {
        tower[i] = new Structure(2, POS_X_STRUCTURE[i], POS_Y_STRUCTURE[i], renderer);
    }
    std::cout << "ok init structure->init player*\n";
    boss = new BossMonster(renderer);
    player = new PlayerObject(renderer);
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
    std::cout << "ok delete boss -> delete structure\n";
    delete[] tower;
    std::cout << " Destroy SDL\n";
    quitSDL(window, renderer);
    std::cout << "ok ~Game\n";
}

void GameObject::renderGame() {
    SDL_RenderClear(renderer);
   
    //std::cout << "start renderGame\n";
    map->render(renderer);
    for (int i = 0; i < AMOUNT_STRUCTURE; i++) {
        tower[i]->render(renderer);
    }
    boss->showRender(renderer);
    menu->renderMenuGame(renderer, gameState);
    player->renderPlayer(renderer);
    time->render(renderer);
   
    SDL_RenderPresent(renderer);
    SDL_Delay(20);
}

void GameObject::gamePlay() {
    startTime = SDL_GetTicks() / 1000;
    std::cout << "Game play bla bla\n";
    while (gameState==GameState::Play) {    
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                gameState = GameState::Quit;
                break;
            }
            else if (e.type == SDL_KEYDOWN) { 
                player->handleSlash();
                GameObject::hadleMovement();
                for (int i = 0; i < AMOUNT_STRUCTURE; i++) {
                    tower[i]->handleTakeDamage(player->getCoordinatesSkill("slash_sword"), 1, DAMAGE_PLAYER);
                }
                if (checkCollision(player->getCoordinatesSkill("slash_sword"), boss->getCoordinates())) {
                    boss->takeDamage(DAMAGE_PLAYER);
                }
            }
            else if (e.type == SDL_MOUSEBUTTONDOWN) {
                GameObject::pauseGame();
                player->handleSkill(e);
            }
        } 
        GameObject::updateTime();
        GameObject::handlePlayer();
        GameObject::handleBossMonster();
        GameObject::handleStructures();

        renderGame();
        if (isOver()) {
            GameObject::gameOver();
            GameObject::newTurn();
        }
    }     
}

void GameObject::gameIntro() {
    menu->gameIntro(gameState, e, renderer);
}

void GameObject::gameOver() {
    menu->gameOver(gameState, e, renderer);
}

void GameObject::Running() {
    std::cout << startTime << std::endl;
    while (gameState != GameState::Quit) {
        gameIntro();
        gamePlay();
        gameOver();
    } 
}

bool GameObject::isOver() {
    if (boss->isDied()) {
        gameState = GameState::Victory;
        return true;
        //break;
    }
    if (player->isDied()) {
        gameState = GameState::Defeat;
        return true;
    }
    return false;
}


void GameObject::hadleMovement() {
    player->handleMoveAction();
    SDL_Point pos = player->getPosition();
    SDL_Point delta = player->getDeltaPosition();
    if (pos.x + delta.x < 96 || pos.x + delta.x + PLAYER_WIDTH > 904) {
        int none = 0;
        map->move(delta.x, none);
        boss->moveFollowMap(delta.x, 0);
        for (int i = 0; i < AMOUNT_STRUCTURE; i++) {
            tower[i]->moveFollowMap(delta.x, 0);
        }
        player->setDeltaPosionsion(0, -1);
    }
    if (pos.y + delta.y < 96 || pos.y + delta.y > 480-PLAYER_HEIGHT) {
        int none = 0;
        map->move(none, delta.y);
        boss->moveFollowMap(0, delta.y);
        for (int i = 0; i < AMOUNT_STRUCTURE; i++) {
            tower[i]->moveFollowMap(0, delta.y);
        }
        player->setDeltaPosionsion(-1, 0);
    }
    player->move();
}

void GameObject::handlePlayer() {
    SDL_Rect position = player->getCoordinates();
    player->takeDamage(boss->damageAttack(position));
    for (int i = 0; i < AMOUNT_STRUCTURE; i++) {
        player->takeDamage(tower[i]->damageAttack(position));
    }
    player->cooldown();
    for (int i = 0; i < AMOUNT_STRUCTURE; i++) {
        player->getScore(tower[i]->calculateScore());
    }
    player->getScore(boss->calculateScore());
    player->updateScore(renderer);
}

void GameObject::handleBossMonster() {
    if (player->getTimeActiveSkill("tornado") > 0 && checkCollision(player->getCoordinatesSkill("tornado"), boss->getCoordinates())) {
        boss->takeDamage(DAMAGE_PLAYER);
    }
    if (player->getTimeActiveSkill("turbulent_slash") > 0 && checkCollision(player->getCoordinatesSkill("turbulent_slash"), boss->getCoordinates())) {
        boss->takeDamage(DAMAGE_TURBULENT_SLASH);
    }
    SDL_Point pos = player->getPosition();
    boss->move(pos.x, pos.y);
    boss->attack(pos.x, pos.y);
    boss->countdown();
}

void GameObject::handleStructures() {
    for (int i = 0; i < AMOUNT_STRUCTURE; i++) {
        tower[i]->handleAttack(player->getCoordinates());
        tower[i]->handleTakeDamage(player->getCoordinatesSkill("turbulent_slash"), player->getTimeActiveSkill("turbulent_slash"), DAMAGE_TURBULENT_SLASH);
        tower[i]->handleTakeDamage(player->getCoordinatesSkill("tornado"), player->getTimeActiveSkill("tornado"), DAMAGE_TORNADO);
        tower[i]->handleMonsterMovement(player->getPosition());
        tower[i]->regeneration();
        tower[i]->cooldown();
    } 
}

void GameObject::pauseGame(){
    int x, y;
    SDL_GetMouseState(&x, &y);
    //std::cout << x << " " << y << std::endl;
    if (x < SCREEN_WIDTH - 50 || y > 50) return;
    gameState = GameState::Pause;
    pause->render(renderer);
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
                if (x >= 450 && x <= 510 && y >= 300 && y <= 360) {
                    GameObject::newTurn();
                    gameState = GameState::Intro;                   
                }
                else if (x >= 565 && x <= 625 && y >= 300 && y <= 360) {
                    gameState = GameState::Play;
                    countdown();
                }
                else if (x >= 690 && x <= 750 && y >= 300 && y <= 360) {
                    gameState = GameState::Quit;
                }
            }
        }        
    }
    
}

void GameObject::newTurn() {
    map->newTurn();
    player->saveHighScore();
    player->newTurn();
    for (int i = 0; i < AMOUNT_STRUCTURE; i++) {
        tower[i]->setCoordinates(POS_X_STRUCTURE[i], POS_Y_STRUCTURE[i]);
        tower[i]->newTurn();
    }
    boss->newTurn();
    boss->setCoordinates(2430, 1760);
}

void GameObject::updateTime() {
    currentTime = SDL_GetTicks() / 1000;
    if (currentTime != startTime) {
        time->setText(std::to_string(currentTime), BLACK_COLOR, FONT_PATH, renderer);
        startTime = currentTime;
    }
}


void GameObject::countdown() {   
    int countDown = 3;
    Texture countdownTexture(SCREEN_WIDTH/2-80, SCREEN_HEIGHT/2-80, 80, 80);
    while (countDown >= 0) {
        SDL_RenderClear(renderer);
        renderGame();
        countdownTexture.setText(std::to_string(countDown), LIGHT_BLUE_COLOR, FONT_PATH, renderer);
        countdownTexture.render(renderer);
        SDL_RenderPresent(renderer);
        SDL_Delay(1000);
        countDown--;
    }    
}
