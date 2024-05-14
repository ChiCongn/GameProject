
#include"GameObject.h"
#include<string>

void GameObject::initializeGame() {
    std::cout << "start init SDL\n";
    initSDL(window, renderer);
    std::cout << "ok init window and renderer\n";
    std::cout << " start init properties Game\n";

    gameState = GameState::Intro;
    menu->initMenuGame(renderer);
    map = loadImage(MAP_PATH, renderer);

    time = new Texture(920, 315, 50, 35);
    time->setText("0", BLACK_COLOR, FONT_PATH, renderer);
    pause = new Texture(SCREEN_WIDTH/2-PAUSE_WIDTH/2, SCREEN_HEIGHT/2-PAUSE_HEIGHT/2, PAUSE_WIDTH, PAUSE_HEIGHT);
    pause->setImageTexture(IMAGE_PAUSE_GAME_PATH, renderer);
    highScore = takeHighScore();
    HighScore = new Texture(880, 140, 80, 40);
    HighScore->setText(std::to_string(highScore), RED_COLOR, FONT_PATH, renderer);
    std::cout << "ok init time...\n";

    tower = new Structure(2, renderer);
    std::cout << "ok init structure->init player*\n";
    boss = new BossMonster(renderer);
    boss->animation->setCoordinates(600, 300);
    player = new PlayerObject(renderer);
    std::cout << "ok init player* -> start init obstacle*\n";
   
    std::cout << "start init audio\n";
    gameDefeatAudio = loadAudio(AUDIO_GAME_DEFEAT_PATH);
    gameVictoryAudio = loadAudio(AUDIO_GAME_VICTORY_PATH);
    gameIntroAudio = loadAudio(AUDIO_GAME_INTRO_PATH);
    std::cout << "ok initGame\n";
}

GameObject::GameObject() {
    initializeGame();
}

GameObject::~GameObject() {
    std::cout << "start destructor gameObject\n";
    SDL_DestroyTexture(map);
    std::cout << "ok delete map-> start delete player*\n";
    delete player;
    std::cout << "ok delete player*->delete bossMonster*\n";
    std::cout << " Destroy SDL\n";
    quitSDL(window, renderer);
    std::cout << "ok ~Game\n";
}

void GameObject::renderGame() {
    SDL_RenderClear(renderer);
    if (gameState == GameState::Play) {
        //std::cout << "start renderGame\n";
        SDL_RenderCopy(renderer, map, NULL, NULL);
        renderHighScore();

        tower->render(renderer);
        player->renderPlayer(renderer);
        boss->showRender(renderer);
        time->render(renderer);
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
                player->handleMoveAction();
                player->move();
                tower->handleTakeDamage(player->slashSword->coordinates, DAMAGE_PLAYER);
            }
            else if (e.type == SDL_MOUSEBUTTONDOWN) {
                player->handleSkill(e);
                tower->handleTakeDamage(player->fireBall->skill->coordinates, DAMAGE_SKILL);
                int x, y;
                SDL_GetMouseState(&x, &y);
                if (x >= SCREEN_WIDTH - 50 && x <= SCREEN_WIDTH && y >= 0 && y <= 50) {      
                    gameState = GameState::Pause;
                    pauseGame();
                }
            }
        } 
        GameObject::updateTime();

        player->takeDamage(tower->damageAttack(player->animation->coordinates));
        player->handleAttackMovement();
        player->cooldown();

        tower->handleAttack(player->animation->coordinates);
        tower->handleTakeDamage(player->fireBall->skill->coordinates, DAMAGE_SKILL);
        tower->handleMonsterMovement(player->posX, player->posY);
        tower->regeneration();
        tower->cooldown();
        
        boss->move(player->posX, player->posY);
        boss->attack(player->posX, player->posY);
        boss->blackHole(player->posX, player->posY);
        boss->countdown();

        renderGame();

        /*if (player->isDead()) {
            gameState = GameState::Defeat;
            GameObject::newTurn();
        }*/
    }     
}

void GameObject::gameIntro() {
    std::cout << "Game Intro\n";
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
                if (x >= 205 && x <= 4500) {
                    if (y >= 70 && y <= 140) {
                        gameState = GameState::Play;
                        std::cout << "Play\n";
                        return;
                    }
                    else if (y >= 210 && y <= 275) {
                        gameState = GameState::Instruction;
                        std::cout << "Game instruction\n";
                        break;
                    }
                    else if (y >= 345 && y <= 410) {
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
                    if (x >= SCREEN_WIDTH-50 && x <= SCREEN_WIDTH && y >= 0 && y <= 50) {
                        gameState = GameState::Intro;
                        break;
                    }
                }
            }
            renderGame();
        }
    }
    std::cout << "ok game intro\n";
}

void GameObject::gameOver() {
    while (gameState == GameState::Victory || gameState == GameState::Defeat) {
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

//bool GameObject::isOver() {
//    if (boss->isDead()) {
//        gameState = GameState::Victory;
//        return true;
//        //break;
//    }
//    if (player->isDead()) {
//        gameState = GameState::Defeat;
//        return true;
//    }
//    return false;
//}

void GameObject::pauseGame(){
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
                if (x >= 445 && x <= 505 && y >= 335 && y <= 390) {
                    //newTurn();
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

void GameObject::newTurn() {
    player->setUpNewTurn();
    tower->newTurn();
}

void GameObject::updateTime() {
    currentTime = SDL_GetTicks() / 1000;
    if (currentTime != startTime) {
        time->setText(std::to_string(currentTime), BLACK_COLOR, FONT_PATH, renderer);
        startTime = currentTime;
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
    HighScore->render(renderer);
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
