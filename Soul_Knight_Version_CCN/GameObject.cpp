
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
    std::cout << "ok initGame\n";
}

GameObject::GameObject(SDL_Renderer* renderer) {
    initializeGame(renderer);
}

GameObject::~GameObject() {
    if (map != nullptr) {
        SDL_DestroyTexture(map);
        map = nullptr;
    }
    player->~PlayerObject();
    delete[] player;
    for (int i = 0; i < AMOUNT_NORMAL_MONSTER; i++) {
        normalMonster[i].~NormalMonster();
    }
    delete[] normalMonster;
    for (int i = 0; i < AMOUNT_LAZER_MONSTER; i++) {
        lazerMonster[i].~LazerMonster();
    }
    delete[] lazerMonster;
    std::cout << "ok ~Game";
}

void GameObject::renderGame(SDL_Renderer* renderer) {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, map, NULL, NULL);
    //std::cout << "start renderGame\n";
    player->renderPlayer(renderer);
    for (int i = 0; i < AMOUNT_NORMAL_MONSTER; i++) {
        for (int j = 0; j < AMOUNT_BULLET_NORMAL_MONSTER; j++) {
            normalMonster[i].normalMonsterBullet[j].BulletMove();
        }
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
    while (!player->isDead()) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
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
        for (int i = 0; i < AMOUNT_NORMAL_MONSTER; i++) {
            normalMonster[i].normalMonsterMove(obstaclePos);
        }
        /*for (int i = 0; i < AMOUNT_LAZER_MONSTER; i++) {
            lazerMonster[i].render(renderer);
        }*/
        renderGame(renderer);
        SDL_Delay(20);
    }     
}