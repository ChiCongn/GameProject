
#include"Monster.h"

//Monster* MonsterFactory::createMonster(const std::string& type, SDL_Renderer* renderer) {
//    if (type == "NormalMonster") {
//        return new NormalMonster(renderer);
//    }
//    else if (type == "AlienMonster") {
//        return new AlienMonster(renderer);
//    }
//    else if (type == "WaterMonster") {
//        return new WaterMonster(renderer);
//    }
//    else if (type == "KnightMonster") {
//        return new KnightMonster(renderer);
//    }
//    else if (type == "BossMonster") {
//        return new BossMonster(renderer);
//    }
//    else {
//        std::cerr << "nguvcll: invalid_argument->Unknown monster type" << std::endl;;
//    }
//}

Monster::Monster (const int width, const int height, const int health, const int clips[][4], const int frames,
const std::string& imageLeft, const std::string& imageRight, SDL_Renderer* renderer){
    speed = 3;
    direction = Direction::West;
    hp = health;
    animation = new Animation(imageLeft, imageRight, width, height, frames, clips, renderer);
    Hp = new Texture(animation->coordinates.x , animation->coordinates.y - 15, 18, 18);
    Hp->setText(std::to_string(hp), RED_COLOR, FONT_PATH, renderer);
}

Monster::~Monster() {
    delete animation;
}

void Monster::render(SDL_Renderer* renderer) {
    //std::cout << "render Monster\n";
    if (hp <= 0) return;
    animation->renderAnimation(renderer, direction);
    Hp->setCoordinates(animation->coordinates.x + 10, animation->coordinates.y - 15);
    Hp->setText(std::to_string(hp), BLACK_COLOR, FONT_PATH, renderer);
    Hp->render(renderer);
    if (time_attack) {
        skill->renderEx(renderer, angle);
    }
}

void Monster::defenceStructure(const SDL_Rect& position) {
    if (hp <= 0) return;
    int deltaX = animation->coordinates.x + animation->coordinates.w / 2 - position.x;
    int deltaY = animation->coordinates.y + animation->coordinates.h / 2 - position.y;
    float distance = sqrt(deltaX * deltaX + deltaY * deltaY);
    if (defence) {
        deltaX = static_cast<int>((deltaX / distance) * speed);
        deltaY = static_cast<int>((deltaY / distance) * speed);

        animation->coordinates.x -= deltaX;
        animation->coordinates.y -= deltaY;
    }
    if (distance >= 100) {
        defence = true;
    }
    if (distance <= attackDistance / 2) {
        defence = false;
    }
}

void Monster::takeDamage(int damage) {
    if (time_undead == 0) {
        hp -= damage;
        //std::cout << "monsters take damage\n";
        time_undead = TIME_UNDEAD_MONSTER;
    }
}

void Monster::cooldown() {
    if (time_undead > 0) {
        time_undead--;
    }
    if (time_wait_attack > 0) {
        time_wait_attack--;
    }
    if (time_attack > 0) {
        time_attack--;
    }
}


// NORMAL MONSTER ======================================================================================================================================

NormalMonster::NormalMonster(SDL_Renderer* renderer) : Monster(NORMAL_MONSTER_WIDTH, NORMAL_MONSTER_HEIGHT, HP_NORMAL_MONSTER, NORMAL_MONSTER_CLIPS,
    NORMAL_MONSTER_FRAMES, IMAGE_NORMAL_MONSTER_LEFT_PATH, IMAGE_NORMAL_MONSTER_RIGHT_PATH, renderer) {
    attackDistance = ATTACK_DISTANCE_NORMAL_MONSTER;
    skill = nullptr;
}


void NormalMonster::move(int x, int y) {
    if (hp <= 0) return;

    int deltaX = animation->coordinates.x + animation->coordinates.w / 2 - x;
    if (deltaX > 0) direction = Direction::West;
    else {
        direction = Direction::East;
    }
    int deltaY = animation->coordinates.y + animation->coordinates.h / 2 - y;
    float distance = sqrt(deltaX * deltaX + deltaY * deltaY);
    if (distance == 0) return;
    if (distance <= attackDistance) {
        deltaX = static_cast<int>((deltaX / distance) * speed);
        deltaY = static_cast<int>((deltaY / distance) * speed);

        animation->coordinates.x -= deltaX;
        animation->coordinates.y -= deltaY;
    }
}

void NormalMonster::attack(int x, int y) {
    ;
}

int NormalMonster::damageAttack(const SDL_Rect& player) {
    int damage = 0;
    if (checkCollision(player, animation->coordinates)) {
        damage++;
    }
    return damage;
}

void NormalMonster::newTurn() {
    hp = HP_NORMAL_MONSTER;
    //animation->setCoordinates(rand() % 600 + 50, rand() % 400 + 50);
}


// ALIEN MONSTER =======================================================================================================================================

AlienMonster::AlienMonster(SDL_Renderer* renderer) : Monster(ALIEN_WIDTH, ALIEN_HEIGHT, HP_ALIEN_MONSTER, ALIEN_CLIPS, ALIEN_FRAMES,
    IMAGE_ALIEN_MONSTER_LEFT, IMAGE_ALIEN_MONSTER_RIGHT, renderer) {
    attackDistance = ATTACK_DISTANCE_ALIEN_MONSTER;
    skill = new Texture(0, 0, 30, 10);
    skill->setImageTexture(LASER_PATH, renderer);
}


void AlienMonster::move(int x, int y) {
    if (hp <= 0) return;

    int deltaX = animation->coordinates.x + animation->coordinates.w / 2 - x - PLAYER_WIDTH / 2;
    int deltaY = animation->coordinates.y + animation->coordinates.h / 2 - y - PLAYER_HEIGHT / 2;
    float distance = sqrt(deltaX * deltaX + deltaY * deltaY);
    if (deltaX > 0) direction = Direction::West;
    else {
        direction = Direction::East;
    }
    if (distance == 0) return;
    deltaX = static_cast<int>((deltaX / distance) * speed);
    deltaY = static_cast<int>((deltaY / distance) * speed);
    if (distance <= attackDistance && distance >= attackDistance - 50) {
        animation->coordinates.x -= deltaX;
        animation->coordinates.y -= deltaY;
    }
    if (distance < attackDistance - 50) {
        animation->coordinates.x += deltaX;
        animation->coordinates.y += deltaY;
    }
    if (animation->coordinates.x < 0 || animation->coordinates.x + ALIEN_WIDTH > SCREEN_WIDTH)
        animation->coordinates.x -= deltaX;
    if (animation->coordinates.y < 0 || animation->coordinates.y + ALIEN_HEIGHT > SCREEN_HEIGHT)
        animation->coordinates.y -= deltaY;
}

void AlienMonster::attack(int x, int y) {
    if (time_wait_attack > 0 || hp <= 0) return;
    
    int deltaX = animation->coordinates.x + ALIEN_WIDTH/2 - x;
    int deltaY = animation->coordinates.y + ALIEN_HEIGHT/2 - y;
    float distance = sqrt(deltaX * deltaX + deltaY * deltaY);

    if (distance > attackDistance) {
        //std::cout << " out of range attack alien monster\n";
        return;
    }
    angle = std::atan2(deltaY, deltaX) * 180.0 / M_PI - 90;
    skill->setWidth(distance);
    if (deltaX < 0) {
        skill->setCoordinates(animation->coordinates.x, animation->coordinates.y + 8);
    }
    else {
        angle = -angle;
        skill->setCoordinates(animation->coordinates.x - deltaX, animation->coordinates.y + 8);
    }
    time_wait_attack = TIME_WAIT_ATTACK;
    time_attack = TIME_ATTACK;
}

int AlienMonster::damageAttack(const SDL_Rect& player) {
    int damage = 0;
    if (checkCollision(player, animation->coordinates)) {
        damage++;
    }
    if (time_attack > 0 && checkCollision(player, skill->coordinates)) {
        damage += DAMAGE_ALIEN_MONSTER;
    }
    return damage;
}


void AlienMonster::newTurn() {
    hp = HP_ALIEN;
    //animation->setCoordinates(rand() % 600 + 50, rand() % 400 + 50);
}


// POISON MONSTER=======================================================================================================================================

PoisonMonster::PoisonMonster(SDL_Renderer* renderer) : Monster(POISON_MONSTER_WIDTH, POISON_MONSTER_HEIGHT, HP_POISON_MONSTER,
    POISON_MONSTER_CLIPS, POISON_MONSTER_FRAMES, IMAGE_POISON_MONSTER_LEFT_PATH, IMAGE_POISON_MONSTER_RIGHT_PATH, renderer) {
    /*skill = new Texture(60, 60, 60, 60);
    skill->setImageTexture(IMAGE_WATER_MOSTER_SKILL, renderer);*/
}

void PoisonMonster::move(int x, int y) {
    if (direction == Direction::West) {
        animation->coordinates.x -= speed;
        if (animation->coordinates.x < 0) {
            direction = Direction::East;
            return;
        }      
    }
    else {
        animation->coordinates.x += speed;
        if (animation->coordinates.x + animation->coordinates.w> SCREEN_WIDTH) {
            direction = Direction::West;
            return;
        }
        /*for (auto it : obstacles) {
            if (checkCollision(animation->coordinates, it)) {
                direction = Direction::West;
            }
        }*/
    }
}

void PoisonMonster::attack(int x, int y) {
    ;
}

void PoisonMonster::newTurn() {
    hp = HP_POISON_MONSTER;
    //animation->setCoordinates(rand() % 600 + 50, rand() % 400 + 50);
}



// KNIGHT MONSTER ======================================================================================================================================

KnightMonster::KnightMonster(SDL_Renderer* renderer) : Monster(KNIGHT_MONSTER_WIDTH, KNIGHT_MONSTER_HEIGHT, HP_KNIGHT_MONSTER, 
    KNIGHT_MONSTER_CLIPS, KNIGHT_MONSTER_FRAMES, IMAGE_KNIGHT_MONSTER_LEFT, IMAGE_KNIGHT_MONSTER_RIGHT, renderer) {
    attackDistance = ATTACK_DISTANCE_KNIGHT_MONSTER;
    skill = new Texture(0, 0, DUAL_SWORDS_WIDTH, DUAL_SWORDS_HEIGHT);
    skill->setImageTexture(DUAL_SWORDS_PATH, renderer);
    //std::cout << "ok constructor knight monster\n";
}

void KnightMonster::move(int x, int y) {
    if (hp <= 0) return;    
    if (time_teleport > 0) time_teleport--;

    int deltaX = animation->coordinates.x + animation->coordinates.w / 2 - x;
    int deltaY = animation->coordinates.y + animation->coordinates.h / 2 - y;
    if (deltaX > 0) direction = Direction::West;
    else {
        direction = Direction::East;
    }
    float distance = sqrt(deltaX * deltaX + deltaY * deltaY);
    if (distance == 0) return;
    if (distance <= attackDistance) {
        if (time_teleport <= 0) {
            animation->setCoordinates(x, y);
            time_teleport = TIME_TELEPORT;
            return;
        }
        deltaX = static_cast<int>((deltaX / distance) * speed);
        deltaY = static_cast<int>((deltaY / distance) * speed);

        animation->coordinates.x -= deltaX;
        animation->coordinates.y -= deltaY;
    }
}

void KnightMonster::attack(int x, int y) {
    if (time_wait_attack > 0 || hp <= 0) return;

    int deltaX = animation->coordinates.x + ALIEN_WIDTH / 2 - x;
    int deltaY = animation->coordinates.y + ALIEN_HEIGHT / 2 - y;
    float distance = sqrt(deltaX * deltaX + deltaY * deltaY);

    if (distance > 20) return;

    if (time_wait_attack == 0) {
        skill->setCoordinates(animation->coordinates.x - 15, animation->coordinates.y - 10);
        time_wait_attack = TIME_WAIT_ATTACK;
        time_attack = TIME_ATTACK;
    }
}

int KnightMonster::damageAttack(const SDL_Rect& player) {
    int damage = 0;
    if (checkCollision(player, animation->coordinates)) {
        damage++;
    }
    if (time_attack > 0 && checkCollision(player, skill->coordinates)) {
        damage += DAMAGE_KNIGHT_MONSTER;
    }
    return damage;
}

void KnightMonster::newTurn() {
    hp = HP_KNIGHT_MONSTER;
    //animation->setCoordinates(rand() % 600 + 50, rand() % 400 + 50);
}



// BOSS MONSTER ========================================================================================================================================

BossMonster::BossMonster(SDL_Renderer* renderer) : Monster(BOSS_MONSTER_WIDTH, BOSS_MONSTER_HEIGHT, HP_BOSS_MONSTER,
    BOSS_MONSTER_CLIPS, BOSS_MONSTER_FRAMES, IMAGE_BOSS_MONSTER_LEFT_PATH, IMAGE_BOSS_MONSTER_RIGHT_PATH, renderer) {
    attackDistance = 200;
    skill = new Texture(0, 0, DUAL_SWORDS_WIDTH, DUAL_SWORDS_HEIGHT);
    skill->setImageTexture(DUAL_SWORDS_PATH, renderer);
    black_hole = new Skill(IMAGE_BLACK_HOLE_PATH, BLACK_HOLE_WIDTH, BLACK_HOLE_HEIGHT, BLACK_HOLE_FRAMES, BLACK_HOLE_CLIPS, renderer);
    fire_explodesion = new Skill(FIRE_EXPLODESION_PATH, FIRE_EXPLODESION_WIDTH, FIRE_EXPLODESION_HEIGHT, 
        FIRE_EXPLODESION_FRAMES, FIRE_EXPLODESION_CLIPS, renderer);
}

void BossMonster::showRender(SDL_Renderer* renderer) {
    BossMonster::render(renderer);
    fire_explodesion->render(renderer);
    black_hole->render(renderer);
}

void BossMonster::move(int x, int y) {
    int deltaX = animation->coordinates.x + animation->coordinates.w / 2 - x;
    int deltaY = animation->coordinates.y + animation->coordinates.h / 2 - y;
    if (deltaX > 0) direction = Direction::West;
    else {
        direction = Direction::East;
    }
    float distance = sqrt(deltaX * deltaX + deltaY * deltaY);
    if (distance == 0) return;

    if (distance <= attackDistance) {
        if (time_teleport <= 0) {
            animation->setCoordinates(x, y);
            time_teleport = TIME_TELEPORT;
            return;
        }
        deltaX = static_cast<int>((deltaX / distance) * speed);
        deltaY = static_cast<int>((deltaY / distance) * speed);

        animation->coordinates.x -= deltaX;
        animation->coordinates.y -= deltaY;
    }
}

void BossMonster::blackHole(int& x, int& y) {
    int deltaX = animation->coordinates.x + animation->coordinates.w / 2 - x;
    int deltaY = animation->coordinates.y + animation->coordinates.h / 2 - y;
    float distance = sqrt(deltaX * deltaX + deltaY * deltaY);
    if (distance == 0) return;
    if (black_hole->time_wait<=0 && distance<=attackDistance) {       
        deltaX = static_cast<int>((deltaX / distance) * speed);
        deltaY = static_cast<int>((deltaY / distance) * speed);

        x -= deltaX;
        y -= deltaY;
        black_hole->setTime(TIME_WAIT_BLACK_HOLE, TIME_ACTIVE_BLACK_HOLE);
    }
}

void BossMonster::attack(int x, int y) {
    int deltaX = animation->coordinates.x + animation->coordinates.w / 2 - x;
    int deltaY = animation->coordinates.y + animation->coordinates.h / 2 - y;
    float distance = sqrt(deltaX * deltaX + deltaY * deltaY);

    if (distance <= 10 && fire_explodesion->time_wait<=0) {
        fire_explodesion->setCoordinates(animation->coordinates.x - 10, animation->coordinates.y - 30);
        fire_explodesion->setTime(TIME_WAIT_FIRE_EXPLODESION, TIME_ACTIVE_FIRE_EXPLODESION);
    }
}

int BossMonster::damageAttack(const SDL_Rect& player) {
    int damage = 0;
    if (checkCollision(animation->coordinates, player)) {
        damage++;
    }
    if (checkCollision(player, fire_explodesion->skill->coordinates) && fire_explodesion->skill->getCurrentFrame() >= 5) {
        damage += DAMAGE_FIRE_EXPLODESION;
    }
    return damage;
}

void BossMonster::newTurn() {
    hp = HP_BOSS_MONSTER;
    //animation->setCoordinates(rand() % 600 + 50, rand() % 400 + 50);
}

void BossMonster::countdown() {
    cooldown();
    fire_explodesion->cooldown();
    black_hole->cooldown();
    if (time_teleport>0)
        time_teleport--;   
}