
#include"Monster.h"

Monster* MonsterFactory::createMonster(const std::string& type, SDL_Renderer* renderer) {
    if (type == "NormalMonster") {
        return new NormalMonster(renderer);
    }
    else if (type == "AlienMonster") {
        return new AlienMonster(renderer);
    }
    else if (type == "PoisonMonster") {
        return new PoisonMonster(renderer);
    }
    else if (type == "KnightMonster") {
        return new KnightMonster(renderer);
    }
    else if (type == "BossMonster") {
        return new BossMonster(renderer);
    }
    else {
        std::cerr << "nguvcll: invalid_argument->Unknown monster type" << std::endl;
        return nullptr;
    }
}

Monster::Monster (const int width, const int height, const int health, const int clips[][4], const int frames,
        const std::string& imageLeft, const std::string& imageRight, SDL_Renderer* renderer){
    speed = 3;
    direction = Direction::West;
    hp = health;
    animation = new Animation(imageLeft, imageRight, width, height, frames, clips, renderer);
    SDL_Point pos = animation->getPosition();
    Hp = new Texture(pos.x , pos.y - 15, 22, 18);
    Hp->setText(std::to_string(hp), RED_COLOR, FONT_PATH, renderer);
    skill = nullptr;
    type = TypeMonster::None;
}

Monster::~Monster() {
    std::cout << "destructor function of monster\n";
}

void Monster::render(SDL_Renderer* renderer) {
    //std::cout << "render Monster\n";
    SDL_Point pos = animation->getPosition();
    if (hp <= 0|| pos.x < 0 || pos.x > 800 ||
        pos.y<0 || pos.y >SCREEN_HEIGHT) return;
    
    animation->renderAnimation(renderer, direction);
    Hp->setCoordinates(pos.x + 10, pos.y - 15);
    Hp->setText(std::to_string(hp), BLACK_COLOR, FONT_PATH, renderer);
    Hp->render(renderer);
    skill->render(renderer);
}

void Monster::setCoordinates(int x, int y) {
    //std::cout << "set coordinates monster\n";
    animation->setCoordinates(x, y);
}

void Monster::defenceStructure(const SDL_Rect& position) {
    if (hp <= 0) return;
    SDL_Rect pos = animation->getCoordinates();
    int deltaX = pos.x + pos.w / 2 - position.x;
    int deltaY = pos.y + pos.h / 2 - position.y;
    float distance = std::sqrt(deltaX * deltaX + deltaY * deltaY);
    if (defence) {
        deltaX = static_cast<int>((deltaX / distance) * speed);
        deltaY = static_cast<int>((deltaY / distance) * speed);

        animation->move(deltaX, deltaY);
    }
    if (distance >= attack_distance * 1.5) {
        defence = true;
    }
    if (distance <= attack_distance / 2) {
        defence = false;
    }
}

void Monster::takeDamage(int damage) {
    if (time_immortality > 0 || damage == 0) return;
    hp -= damage;
    //std::cout << "monsters take damage\n";
    time_immortality = TIME_IMMORTALITY_MONSTER;
}

void Monster::cooldown() {
    if (time_immortality > 0) {
        time_immortality--;
    }
    skill->cooldown();
}

void Monster::moveFollowMap(int x, int y) {
    if (hp <= 0) return;
    animation->move(x, y);
}

void Monster::newTurn() {
    is_calculate = false;
    switch (type)
    {
    case TypeMonster::Normal:
        hp = HP_NORMAL_MONSTER;
        break;
    case TypeMonster::Poison:
        hp = HP_POISON_MONSTER;
        break;
    case TypeMonster::Alien:
        hp = HP_ALIEN_MONSTER;
        break;
    case TypeMonster::Knight:
        hp = HP_KNIGHT_MONSTER;
        break;
    case TypeMonster::Boss:
        hp = HP_BOSS_MONSTER;
        break;
    default:
        break;
    }
}

int Monster::calculateScore() {
    if (hp <= 0) {
        if (!is_calculate) {
            is_calculate = true;
            switch (type)
            {
            case TypeMonster::Normal:
                return SCORE_NORMAL_MONSTER;
            case TypeMonster::Poison:
                return SCORE_POISON_MONSTER;
            case TypeMonster::Alien:
                return SCORE_ALIEN_MONSTER;
            case TypeMonster::Knight:
                return SCORE_KNIGHT_MONSTER;
            case TypeMonster::Boss:
                return SCORE_BOSS_MONSTER;
                break;
            default:
                break;
            }
        }
    }
    return 0;
}


// NORMAL MONSTER ======================================================================================================================================

NormalMonster::NormalMonster(SDL_Renderer* renderer) : Monster(NORMAL_MONSTER_WIDTH, NORMAL_MONSTER_HEIGHT, HP_NORMAL_MONSTER, NORMAL_MONSTER_CLIPS,
        NORMAL_MONSTER_FRAMES, IMAGE_NORMAL_MONSTER_LEFT_PATH, IMAGE_NORMAL_MONSTER_RIGHT_PATH, renderer) {
    type = TypeMonster::Normal;
    attack_distance = ATTACK_DISTANCE_NORMAL_MONSTER;
    skill = new Skill(IMAGE_SKILL_MONSTER_PATH, EXPLODESION_PATH, EXPLODESION_WIDTH, EXPLODESION_HEIGHT, 
        EXPLODESION_FRAMES, EXPLODESION_CLIPS, renderer);
}

NormalMonster::~NormalMonster() {
    delete animation;
    delete Hp;
    delete skill;
}

void NormalMonster::move(int x, int y) {
    if (hp <= 0) return;
    SDL_Rect pos = animation->getCoordinates();
    int deltaX = pos.x + pos.w / 2 - x;
    if (deltaX > 0) direction = Direction::West;
    else {
        direction = Direction::East;
    }
    int deltaY = pos.y + pos.h / 2 - y;
    float distance = std::sqrt(deltaX * deltaX + deltaY * deltaY);
    if (distance == 0) return;
    if (distance <= attack_distance) {
        deltaX = static_cast<int>((deltaX / distance) * speed);
        deltaY = static_cast<int>((deltaY / distance) * speed);

        animation->move(deltaX, deltaY);        
    }
}

void NormalMonster::attack(int x, int y) {
    if (skill->getTimeWait() > 0 || hp <= 0) return;
    SDL_Point pos = animation->getPosition();
    int deltaX = pos.x + NORMAL_MONSTER_WIDTH / 2 - x;
    int deltaY = pos.y + NORMAL_MONSTER_HEIGHT / 2 - y;
    float distance = std::sqrt(deltaX * deltaX + deltaY * deltaY);

    if (distance > attack_distance) {
        return;
    }
    if (distance < 10) {
        skill->setCoordinates(x - 10, y - 10);
        skill->setTime(TIME_WAIT_EXPLODESION, TIME_ACTIVE_EXPLODESION);
    }
}

int NormalMonster::damageAttack(const SDL_Rect& player) {
    int damage = 0;
    if (checkCollision(player, animation->getCoordinates())) {
        damage++;
    }
    if (skill->getTimeActive() > 0 && checkCollision(player, skill->getCoordinates())) {
        damage += DAMAGE_EXPLODESION;
    }
    return damage;
}



// ALIEN MONSTER =======================================================================================================================================

AlienMonster::AlienMonster(SDL_Renderer* renderer) : Monster(ALIEN_WIDTH, ALIEN_HEIGHT, HP_ALIEN_MONSTER, ALIEN_CLIPS, ALIEN_FRAMES,
        IMAGE_ALIEN_MONSTER_LEFT, IMAGE_ALIEN_MONSTER_RIGHT, renderer) {
    type = TypeMonster::Alien;
    attack_distance = ATTACK_DISTANCE_ALIEN_MONSTER;
    skill = new Skill(IMAGE_SKILL_MONSTER_PATH, LIGHTNING_PATH, LIGHTNING_WIDTH, LIGHTNING_HEIGHT,
        LIGHTNING_FRAMES, LIGHTNING_CLIPS, renderer);
}

AlienMonster::~AlienMonster() {
    delete animation;
    delete skill;
    delete Hp;
}

void AlienMonster::move(int x, int y) {
    if (hp <= 0) return;
    SDL_Point pos = animation->getPosition();
    int deltaX = pos.x + ALIEN_WIDTH / 2 - x - PLAYER_WIDTH / 2;
    int deltaY =pos.y + ALIEN_HEIGHT / 2 - y - PLAYER_HEIGHT / 2;
    float distance = std::sqrt(deltaX * deltaX + deltaY * deltaY);
    if (deltaX > 0) direction = Direction::West;
    else {
        direction = Direction::East;
    }
    if (distance == 0) return;
    deltaX = static_cast<int>((deltaX / distance) * speed);
    deltaY = static_cast<int>((deltaY / distance) * speed);
    if (distance <= attack_distance && distance >= attack_distance - 50) {
        animation->move(deltaX, deltaY);
    }
    if (distance < attack_distance - 50) {
        animation->move(-deltaX, -deltaY);
    }
    if (pos.x < 0 || pos.x + ALIEN_WIDTH > SCREEN_WIDTH) {
        animation->move(deltaX, 0);
    }
    if (pos.y < 0 || pos.y + ALIEN_HEIGHT > SCREEN_HEIGHT) {
        animation->move(0, deltaY);
    }
}

void AlienMonster::attack(int x, int y) {
    if (skill->getTimeWait() > 0 || hp <= 0) return;
    SDL_Point pos = animation->getPosition();
    int deltaX = pos.x + ALIEN_WIDTH/2 - x;
    int deltaY = pos.y + ALIEN_HEIGHT/2 - y;
    float distance = std::sqrt(deltaX * deltaX + deltaY * deltaY);

    if (distance > attack_distance) {
        //std::cout << " out of range attack alien monster\n";
        return;
    }
    skill->setCoordinates(x - 10, y - 10);
    skill->setTime(TIME_WAIT_LIGHTNING, TIME_ACTIVE_LIGHTNING);
}

int AlienMonster::damageAttack(const SDL_Rect& player) {
    int damage = 0;
    if (checkCollision(player, animation->getCoordinates())) {
        damage++;
    }
    if (skill->getTimeActive() > 0 && checkCollision(player, skill->getCoordinates())) {
        damage += DAMAGE_LIGHTNING;
    }
    return damage;
}




// POISON MONSTER=======================================================================================================================================

PoisonMonster::PoisonMonster(SDL_Renderer* renderer) : Monster(POISON_MONSTER_WIDTH, POISON_MONSTER_HEIGHT, HP_POISON_MONSTER,
        POISON_MONSTER_CLIPS, POISON_MONSTER_FRAMES, IMAGE_POISON_MONSTER_LEFT_PATH, IMAGE_POISON_MONSTER_RIGHT_PATH, renderer) {
    type = TypeMonster::Poison;
    skill = nullptr;
}

PoisonMonster::~PoisonMonster() {
    delete animation;
    //delete skill;
    delete Hp;
}

void PoisonMonster::move(int x, int y) {
    ;
}

void PoisonMonster::attack(int x, int y) {
    ;
}

int PoisonMonster::damageAttack(const SDL_Rect& player) {
    return 0;
}


// KNIGHT MONSTER ======================================================================================================================================

KnightMonster::KnightMonster(SDL_Renderer* renderer) : Monster(KNIGHT_MONSTER_WIDTH, KNIGHT_MONSTER_HEIGHT, HP_KNIGHT_MONSTER, 
        KNIGHT_MONSTER_CLIPS, KNIGHT_MONSTER_FRAMES, IMAGE_KNIGHT_MONSTER_LEFT, IMAGE_KNIGHT_MONSTER_RIGHT, renderer) {
    type = TypeMonster::Knight;
    attack_distance = ATTACK_DISTANCE_KNIGHT_MONSTER;
    skill = new Skill(IMAGE_SKILL_MONSTER_PATH, FIRE_SWORD_PATH, FIRE_SWORD_WIDTH, FIRE_SWORD_HEIGHT, 
        FIRE_SWORD_FRAMES, FIRE_SWORD_CLIPS, renderer);
}

KnightMonster::~KnightMonster() {
    delete animation;
    delete skill;
    delete Hp;
}

void KnightMonster::move(int x, int y) {
    if (hp <= 0) return;    
    if (time_teleport > 0) time_teleport--;
    SDL_Point pos = animation->getPosition();
    int deltaX = pos.x + KNIGHT_MONSTER_WIDTH / 2 - x;
    int deltaY = pos.y + KNIGHT_MONSTER_HEIGHT / 2 - y;
    if (deltaX > 0) direction = Direction::West;
    else {
        direction = Direction::East;
    }
    float distance = sqrt(deltaX * deltaX + deltaY * deltaY);
    if (distance == 0) return;
    if (distance <= attack_distance) {
        if (time_teleport <= 0) {
            animation->setCoordinates(x, y);
            time_teleport = TIME_TELEPORT;
            return;
        }
        deltaX = static_cast<int>((deltaX / distance) * speed);
        deltaY = static_cast<int>((deltaY / distance) * speed);

        animation->move(deltaX, deltaY);
    }
}

void KnightMonster::attack(int x, int y) {
    if (skill->getTimeWait() > 0 || hp <= 0) return;

    SDL_Point pos = animation->getPosition();
    int deltaX = pos.x + KNIGHT_MONSTER_WIDTH / 2 - x;
    int deltaY = pos.y + KNIGHT_MONSTER_HEIGHT / 2 - y;
    float distance = std::sqrt(deltaX * deltaX + deltaY * deltaY);

    if (distance > attack_distance) return;
    skill->setCoordinates(pos.x - 10, pos.y - 10);
    skill->setTime(TIME_WAIT_FIRE_SWORD, TIME_ACTIVE_FIRE_SWORD);
    
}

int KnightMonster::damageAttack(const SDL_Rect& player) {
    int damage = 0;
    if (checkCollision(player, animation->getCoordinates())) {
        damage++;
    }
    if (skill->getTimeActive() > 0 && checkCollision(player, skill->getCoordinates())) {
        damage += DAMAGE_KNIGHT_MONSTER;
    }
    return damage;
}




// BOSS MONSTER ========================================================================================================================================

BossMonster::BossMonster(SDL_Renderer* renderer) : Monster(BOSS_MONSTER_WIDTH, BOSS_MONSTER_HEIGHT, HP_BOSS_MONSTER,
        BOSS_MONSTER_CLIPS, BOSS_MONSTER_FRAMES, IMAGE_BOSS_MONSTER_LEFT_PATH, IMAGE_BOSS_MONSTER_RIGHT_PATH, renderer) {
    type = TypeMonster::Boss;
    attack_distance = ATTACK_DISTANCE_BOSS_MONSTER;
    animation->setCoordinates(2430, 1760);
    skill = new Skill(IMAGE_SKILL_MONSTER_PATH, ELECTRIC_SHIELD_PATH, ELECTRIC_SHIELD_WIDTH, ELECTRIC_SHIELD_HEIGHT,
        ELECTRIC_SHIELD_FRAMES, ELECTRIC_SHIELD_CLIPS, renderer);
    black_hole = new Skill(IMAGE_SKILL_MONSTER_PATH, IMAGE_BLACK_HOLE_PATH, BLACK_HOLE_WIDTH, BLACK_HOLE_HEIGHT,
        BLACK_HOLE_FRAMES, BLACK_HOLE_CLIPS, renderer);
    fire_explodesion = new Skill(IMAGE_SKILL_MONSTER_PATH, FIRE_EXPLODESION_PATH, FIRE_EXPLODESION_WIDTH, FIRE_EXPLODESION_HEIGHT,
        FIRE_EXPLODESION_FRAMES, FIRE_EXPLODESION_CLIPS, renderer);
}

BossMonster::~BossMonster() {
    delete animation;
    delete skill;
    delete Hp;
    delete black_hole;
    delete fire_explodesion;
}

void BossMonster::showRender(SDL_Renderer* renderer) {
    if (hp <= 0) return;
    BossMonster::render(renderer);
    skill->render(renderer);
    fire_explodesion->render(renderer);
    black_hole->render(renderer);
}

void BossMonster::move(int x, int y) {
    if (hp <= 0) return;
    SDL_Point pos = animation->getPosition();
    int deltaX = pos.x + BOSS_MONSTER_WIDTH / 2 - x;
    int deltaY = pos.y + BOSS_MONSTER_HEIGHT / 2 - y;
    if (deltaX > 0) direction = Direction::West;
    else {
        direction = Direction::East;
    }
    float distance = std::sqrt(deltaX * deltaX + deltaY * deltaY);
    if (distance == 0) return;

    if (distance <= attack_distance) {
        if (time_teleport <= 0) {
            animation->setCoordinates(x, y);
            time_teleport = TIME_TELEPORT;
            return;
        }
        deltaX = static_cast<int>((deltaX / distance) * speed);
        deltaY = static_cast<int>((deltaY / distance) * speed);

        animation->move(deltaX, deltaY);
    }
}


void BossMonster::attack(int x, int y) {
    if (hp <= 0) return;
    SDL_Point pos = animation->getPosition();
    if (skill->getTimeWait() == 0) {
        skill->setCoordinates(pos.x - 5, pos.y - 5);
        skill->setTime(TIME_WAIT_ELECTRIC_SHIELD, TIME_ACTIVE_ELECTRIC_SHIELD);
        if (hp < 500)
            hp += 5;
    }
    int deltaX = pos.x + KNIGHT_MONSTER_WIDTH / 2 - x;
    int deltaY = pos.y + KNIGHT_MONSTER_HEIGHT / 2 - y;
    float distance = std::sqrt(deltaX * deltaX + deltaY * deltaY);
    
    if (distance <= 50 && distance > 10 && fire_explodesion->getTimeWait() <= 0) {
        fire_explodesion->setCoordinates(pos.x - 10, pos.y - 30);
        fire_explodesion->setTime(TIME_WAIT_FIRE_EXPLODESION, TIME_ACTIVE_FIRE_EXPLODESION);
    }
    if (distance <= 10) {
        black_hole->setCoordinates(x, y);
        black_hole->setTime(TIME_WAIT_BLACK_HOLE, TIME_ACTIVE_BLACK_HOLE);
    }
}

int BossMonster::damageAttack(const SDL_Rect& player) {
    int damage = 0;
    if (checkCollision(animation->getCoordinates(), player)) {
        damage++;
    }
    if (checkCollision(player, fire_explodesion->getCoordinates())) {
        damage += DAMAGE_FIRE_EXPLODESION;
    }
    return damage;
}


void BossMonster::countdown() {
    cooldown();
    fire_explodesion->cooldown();
    black_hole->cooldown();
    if (time_teleport>0)
        time_teleport--;   
}