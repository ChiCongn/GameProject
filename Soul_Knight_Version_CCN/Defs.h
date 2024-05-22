
#include<string>
#include<SDL.h>
#include<vector>

#ifndef DEFS_H
#define DEFS_H


/// Window
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 562;

const std::string WINDOW_TITLE = "Made by ccn :v";
const std::string FONT_PATH = "BAUHS93.TTF";

const SDL_Color RED_COLOR = { 255, 0, 0 };
const SDL_Color LIGHT_BLUE_COLOR = { 0, 255, 255 };
const SDL_Color BLACK_COLOR = { 0, 0, 0 };


// Pause 
const std::string PAUSE_GAME_PATH = "./Image\\PauseGame.png";

const int PAUSE_WIDTH = 400;
const int PAUSE_HEIGHT = 200;

// MAP
const std::string MAP_PATH = "./Image\\Map.png";
const std::string MATRIX_TILE_MAP_PATH = "./MatrixTileMap.txt";

/// <summary>
///  path : < 10
/// </summary>

const int MAP_WIDTH = 3200;
const int MAP_HEIGHT = 2400;
const int MAP_ROW = 75;
const int MAP_COL = 100;
const int VIEWPORT_WIDTH = 1000;
const int VIEWPORT_HEIGHT = 562;
const SDL_Rect VIEWPORT = { 0, 0, 1000, SCREEN_HEIGHT };

/// MenuGame
#define GAME_INTRO_PATH "./Image\\GameIntro.png"
#define GAME_INSTRUCTIONS_PATH "./Image\\GameInstructions.png"
#define GAME_VICTORY_PATH "./Image\\GameVictory.png"
#define GAME_DEFEAT_PATH "./Image\\GameDefeat.png"
const std::string NOTIFICATION_PATH = "./Image\\Notification.png";

const int NOTIFICATION_WIDTH = 200;
const int NOTIFICATION_HEIGHT = SCREEN_HEIGHT;


///PLAYER
const std::string PLAYER_LEFT_PATH = "./Image\\MagicanLeft.png";
const std::string PLAYER_RIGHT_PATH = "./Image\\MagicanRight.png";
const std::string HP_PATH = "./Image\\Hp.png";
const std::string EX_PATH = "./Image\\Ex.png";
const std::string HIGH_SCORE_PATH = "HighScore.txt";


const int PLAYER_WIDTH = 40;
const int PLAYER_HEIGHT = 45;
const int HP_PLAYER = 10;
const int DAMAGE_PLAYER = 2;
const int SPEED_PLAYER = 8;
const int TIME_IMMORTALITY = 1005;


const int MAGICAN_CLIPS[][4] = {
	{0, 0, 192, 190},
	{192, 0, 192, 190},
	{384, 0, 192, 190},
	{576, 0, 192, 190},
	{0, 190, 192, 190},
	{192, 190, 192, 190},
	{384, 190, 192, 190},
	{576, 190, 192, 190},
};
const int MAGICAN_FRAMES = sizeof(MAGICAN_CLIPS) / sizeof(int) / 4;

/// Slash Sword
const std::string SLASH_LEFT_PATH = "./Image\\SlashSwordPlayerLeft.png";
const std::string SLASH_RIGHT_PATH = "./Image\\SlashSwordPlayerRight.png";
const std::string IMAGE_SLASH_SWORD_PATH = "./Image\\SlashSkill.png";

const int SLASH_SWORD_WIDTH = 80;
const int SLASH_SWORD_HEIGHT = 80;
const int TIME_WAIT_SLASH = 8;

const int PLAYER_SLASH_CLIPS[][4] = {
	{0, 0, 289, 214}
};
const int PLAYER_SLASH_FRAMES = sizeof(PLAYER_SLASH_CLIPS) / sizeof(int) / 4;

/// Skill Tornado
const std::string TORNADO_EFFECT_PATH = "./Image\\TornadoEffect.png";
const std::string IMAGE_TORNADO_SKILL_PATH = "./Image\\TornadoSkill.png";
const int TORNADO_WIDTH = 100;
const int TORNADO_HEIGHT = 120;

const int TIME_WAIT_TORNADO = 50;
const int TIME_ACTIVE_TORNADO = 10;
const int DAMAGE_TORNADO = 2;

const int TORNADO_CLIPS[][4] = {
	{8, 12, 56, 44}, {72, 8, 48, 48}, {150, 4, 48, 52}, {220, 0, 55, 60},
	{0, 72, 52, 48}, {72, 68, 52, 52}, {144, 68, 60, 52}, {220, 68, 52, 60},
	{0, 140, 52, 48}, {72, 140, 52, 48}, {148, 140, 48, 48}, {220, 140, 48, 48},
	{8, 203, 40, 48}, {76, 196, 55, 48}, {148, 192, 48, 60}, {220, 200, 50, 50}
};
const int TORNADO_FRAMES = sizeof(TORNADO_CLIPS) / sizeof(int) / 4;

const std::string SHIELD_EFFECT_PATH = "./Image\\ShieldEffect.png";
const std::string IMAGE_SHIELD_SKILL_PATH = "./Image\\ShieldSkill.png";
const int SHIELD_WIDTH = 70;
const int SHIELD_HEIGHT = 70;

const int TIME_WAIT_SHIELD = 81;
const int TIME_ACTIVE_SHIELD = 9;

const int SHIELD_CLIPS[][4] = {
	{0, 0, 157, 165}, {157, 0, 163, 165}, {320, 0, 176, 165}, {495, 0,175, 165 }, {680, 0, 185, 165},
	{0, 172, 155, 157}, {155, 172, 165, 57}, {320, 172, 155, 157}, {475, 172, 160, 157}
};
const int SHIELD_FRAMES = sizeof(SHIELD_CLIPS) / sizeof(int) / 4;

const std::string HEALING_PATH = "./Image\\Healing.png";
const std::string IMAGE_HEALING_SKILL_PATH = "./Image\\HealingSkill.png";
const int HEALING_WIDTH = 60;
const int HEALING_HEIGHT = 60;

const int TIME_WAIT_HEALING = 200;
const int TIME_ACTIVE_HEALING = 8;

const int HEALING_CLIPS[][4] = {
	{0, 0, 345, 360},
};
const int HEALING_FRAMES = sizeof(HEALING_CLIPS) / sizeof(int) / 4;

const std::string TURBULENT_SLASH_PATH = "./Image\\TurbulentSlash.png";
const std::string IMAGE_TURBULENT_SLASH_SKILL_PATH = "./Image\\TurbulentSlashSkill.png";

const int TURBULENT_SLASH_WIDTH = 100;
const int TURBULENT_SLASH_HEIGHT = 80;

const int TIME_WAIT_TURBULENT_SLASH = 0;
const int TIME_ACTIVE_TURBULENT_SLASH = 25;
const int DAMAGE_TURBULENT_SLASH = 10;

const int TURBULENT_SLASH_CLIPS[][4] = {
	{0, 0, 228, 194}, {250, 0, 235, 194}, { 490, 0, 270, 194}, {808, 0, 255, 194}, {1100, 0, 230, 194},
	{0, 194, 228, 155}, {250, 194, 235, 155}, {490, 194, 270, 155}, {808, 194, 255, 155}, {1110, 194, 230, 155},
	{0, 350, 228, 219}, {250, 350, 235, 219}, {490, 350, 270, 219}, {808, 350, 255, 220}, {1110, 350, 230, 220},
	{0, 570, 228, 275}, {250, 570, 235, 275}, {490, 570, 270, 275}, {808, 570, 255, 275}, {1110, 570, 230, 275},
	{0, 845, 228, 223}, {250, 845, 235, 223}, {490, 845, 270, 223}, {808, 845, 255, 223},
};
const int TURBULENT_SLASH_FRAMES = sizeof(TURBULENT_SLASH_CLIPS) / sizeof(int) / 4;


const int PLAYER_SKILL_CLIPS[][4] = {
	{0, 0, 163, 162}, {163, 0, 163, 162}, {326, 0, 163, 162}, {489, 0, 163, 162}, {652, 0, 163, 162},
	{0, 162, 163, 162}, {163, 162, 163, 162}, {326, 162, 163, 162}, {489, 162, 163, 162}, {652, 162, 163, 162},
};
const int PLAYER_SKILL_FRAMES = sizeof(PLAYER_SKILL_CLIPS) / sizeof(int) / 4;

//const std::string IMAGE_FIRE_PATH = "./Image\\FireFlame.png";
//
//const int FIRE_CLIPS[][4] = {
//	{0, 0, 120, 150},
//	{120, 0, 120, 150},
//	{240, 0, 120, 150},
//	{360, 0, 120, 150},
//	{0, 150, 120, 150},
//	{120, 150, 120, 150},
//	{240, 150, 120, 150},
//	{360, 150, 120, 150},
//};
//
//const int FIRE_FRAMES = sizeof(FIRE_CLIPS) / sizeof(int) / 4;


/// MONSTER ============================================================================================================================================
const std::string IMAGE_SKILL_MONSTER_PATH = "./Image\\ImageSkillMonster.png";
const int TIME_IMMORTALITY_MONSTER = 40;
const int TIME_WAIT_ATTACK = 25;
const int TIME_ATTACK = 2;
const int TIME_TELEPORT = 2000;

// STRUCTURE 
const std::string TOWER_PATH = "./Image\\Tower.png";
const std::string THORN_PATH = "./Image\\ThornGrow.png";

const int TOWER_WIDTH = 50;
const int TOWER_HEIGHT = 100;
const int HP_STRUCTURE = 30;
const int TIME_REGENERATION = 500;
const int DANGEROUS_ZONE = 250;
const int SCORE_STRUCTURE = 100;

const int POS_X_STRUCTURE[] = { 760, 2200, 800, 500, 2700, 1400 };
const int POS_Y_STRUCTURE[] = { 410, 160, 940, 1770, 810, 1500 };
const int AMOUNT_STRUCTURE = sizeof(POS_X_STRUCTURE) / sizeof(int);
// Thorn
const int THORN_WIDTH = 30;
const int THORN_HEIGHT = 50;
const int TIME_THORN_GROW = 12;
const int TIME_WAIT_GROW = 100;

const int THORN_CLIPS[][4] = {
	{0, 0, 152, 276}, {0, 0, 152, 276}, {152, 0, 152, 276}, {152, 0, 152, 276},
	{304, 0, 152, 276}, {456, 0, 152, 276}, {0, 276, 152, 276}, {152, 152, 152, 276},
	{304, 0, 152, 276}, {456, 0, 152, 276}
};
const int THORN_FRAMES = sizeof(THORN_CLIPS) / sizeof(int) / 4;

//Boss==================================================================================================================================================
const std::string IMAGE_BOSS_MONSTER_LEFT_PATH = "./Image\\BossMonsterLeft.png";
const std::string IMAGE_BOSS_MONSTER_RIGHT_PATH = "./Image\\BossMonsterRight.png";
const std::string IMAGE_BULLET_BOSS_MONSTER_PATH = "./Image\\Bullet.png";
const std::string IMAGE_BLACK_HOLE_PATH = "./Image\\BlackHole.png";

const int BOSS_MONSTER_WIDTH = 100;
const int BOSS_MONSTER_HEIGHT = 120;
const int DAMAGE_BOSS_MONSTER = 5;
const int SPEED_BOSS_MONSTER = 3;
const int HP_BOSS_MONSTER = 50;
const int ATTACK_DISTANCE_BOSS_MONSTER = 400;

const int MANA_BOSS_MONSTER = 100;
const int POINT_BOSS_MONSTER = 200;
const int SCORE_BOSS_MONSTER = 200;

const int BOSS_MONSTER_CLIPS[][4] = {
	{0, 0, 261, 270},
	{261, 0, 261, 270},
	{522, 0, 261, 270},
	{0, 270, 261, 270},
	{261, 270, 261, 270},
	{522, 270, 261, 270}
};
const int BOSS_MONSTER_FRAMES = sizeof(BOSS_MONSTER_CLIPS) / sizeof(int) / 4;

// Skill
const std::string BLACK_HOLE_PATH = "./Image\\BlackHole.png";
const int BLACK_HOLE_WIDTH = 90;
const int BLACK_HOLE_HEIGHT = 90;
const int TIME_WAIT_BLACK_HOLE = 150;
const int TIME_ACTIVE_BLACK_HOLE = 10;
const int BLACK_HOLE_CLIPS[][4] = {
	{0, 0, 28, 32}, {36, 0, 28, 32}, {72, 0, 28, 32}, {108, 0, 28, 32}, {140, 0, 28, 32}, {180, 0, 28, 32},
	{0, 48, 28, 32}, {36, 48, 28, 32}, {72, 48, 28, 32}, {108, 48, 28, 32}, {140, 48, 28, 32}, {180, 48, 28, 32},
	{0, 76, 28, 32}, {36, 76, 28, 32}, {72, 76, 28, 32}, {108, 76, 28, 32}, {140, 76, 28, 32}, {180, 76, 28, 32}
};
const int BLACK_HOLE_FRAMES = sizeof(BLACK_HOLE_CLIPS) / sizeof(int) / 4;

const std::string FIRE_EXPLODESION_PATH = "./Image\\FireExplodesion.png";
const int FIRE_EXPLODESION_WIDTH = 200;
const int FIRE_EXPLODESION_HEIGHT = 200;
const int TIME_WAIT_FIRE_EXPLODESION = 200;
const int TIME_ACTIVE_FIRE_EXPLODESION = 10;
const int DAMAGE_FIRE_EXPLODESION = 3;

const int FIRE_EXPLODESION_CLIPS[][4] = {
	{0, 0, 240, 245}, {240, 0, 240, 245}, {480, 0, 240, 245},
	{0, 245, 240, 245}, {240, 245, 240, 245}, {480, 245, 240, 245}
};
const int FIRE_EXPLODESION_FRAMES = sizeof(FIRE_EXPLODESION_CLIPS) / sizeof(int) / 4;

const std::string ELECTRIC_SHIELD_PATH = "./Image\\ElectricShield.png";
const int ELECTRIC_SHIELD_WIDTH = 100;
const int ELECTRIC_SHIELD_HEIGHT = 100;

const int TIME_WAIT_ELECTRIC_SHIELD = 200;
const int TIME_ACTIVE_ELECTRIC_SHIELD = 10;

const int ELECTRIC_SHIELD_CLIPS[][4] = {
	{0, 0, 163, 162}, {163, 0, 163, 162}, {326, 0, 163, 162}, {489, 0, 163, 162}, {652, 0, 163, 162},
	{0, 162, 163, 162}, {163, 162, 163, 162}, {326, 162, 163, 162}, {489, 162, 163, 162}, {652, 162, 163, 162}
};
const int ELECTRIC_SHIELD_FRAMES = sizeof(ELECTRIC_SHIELD_CLIPS) / sizeof(int) / 4;

//Normal Monster========================================================================================================================================
const std::string IMAGE_NORMAL_MONSTER_LEFT_PATH = "./Image\\NormalMonsterLeft.png";
const std::string IMAGE_NORMAL_MONSTER_RIGHT_PATH = "./Image\\NormalMonsterRight.png";

const int NORMAL_MONSTER_WIDTH = 40;
const int NORMAL_MONSTER_HEIGHT = 42;
const int HP_NORMAL_MONSTER = 15;
const int DAMAGE_NORMAL_MONSTER = 1;
const int SPEED_NORMAL_MONSTER = 2;

const int MANA_NORMAL_MONSTER = 5;
const int POINT_NORMAL_MONSTER = 5;
const int ATTACK_DISTANCE_NORMAL_MONSTER = 200;
const int SCORE_NORMAL_MONSTER = 10;

const int NORMAL_MONSTER_CLIPS[][4] = {
	{0,0, 210, 244},
	{210,0, 210, 244},
	{420,0, 210, 244},
	{630,0, 210, 244},
	{0,244, 210, 244},
	{210,244, 210, 244},
	{420,244, 210, 244},
	{630,244, 210, 244},
};
const int NORMAL_MONSTER_FRAMES = sizeof(NORMAL_MONSTER_CLIPS) / sizeof(int) / 4;
// Skill 
const std::string EXPLODESION_PATH = "./Image\\Explodesion.png";
const int EXPLODESION_WIDTH = 45;
const int EXPLODESION_HEIGHT = 50;
const int TIME_WAIT_EXPLODESION = 80;
const int TIME_ACTIVE_EXPLODESION = 6;
const int DAMAGE_EXPLODESION = 2;

const int EXPLODESION_CLIPS[][4] = {
	{0, 0, 160, 202}, {170, 0, 214, 202}, {430, 0, 190, 202},
	{650, 0, 220, 202}, {650, 0, 220, 202}, {888, 0, 257, 202},
	{888, 0, 257, 202}, {1150, 0, 194, 202}, {1150, 0, 194, 202}
};
const int EXPLODESION_FRAMES = sizeof(EXPLODESION_CLIPS) / sizeof(int) / 4;


// Poison Monster=======================================================================================================================================
const std::string IMAGE_POISON_MONSTER_LEFT_PATH = "./Image\\LazerMonsterLeft.png";
const std::string IMAGE_POISON_MONSTER_RIGHT_PATH = "./Image\\LazerMonsterRight.png";
const std::string IMAGE_POISON_MOSTER_SKILL = "./Iamge\\Poison.png";

const int POISON_MONSTER_WIDTH = 77;
const int POISON_MONSTER_HEIGHT = 80;

const int HP_POISON_MONSTER = 5;
const int DAMAGE_POISON_MONSTER = 1;
const int SPEED_POISON_MONSTER = 2;

const int ATTACK_DISTANCE_POISON_MONSTER = 80;
const int SCORE_POISON_MONSTER = 15;

const int POISON_MONSTER_CLIPS[][4] = {
	{0, 0, 256, 267},
	{256, 0, 256, 267},
	{512, 0, 256, 267},
	{0, 267, 256, 267},
	{256, 267, 256, 267},
	{512, 267, 256, 267},
};
const int POISON_MONSTER_FRAMES = sizeof(POISON_MONSTER_CLIPS) / sizeof(int) / 4;

// Alien Monster========================================================================================================================================
const std::string IMAGE_ALIEN_MONSTER_LEFT = "./Image\\AlienLeft.png";
const std::string IMAGE_ALIEN_MONSTER_RIGHT = "./Image\\AlienRight.png";
const std::string IMAGE_ALIEN_MONSTER_SKILL = "./Image\\Laze.png";
const std::string LASER_PATH = "./Image\\Laser.png";

const int ALIEN_WIDTH = 45;
const int ALIEN_HEIGHT = 55;
const int HP_ALIEN_MONSTER = 25;
const int SPEED_ALIEN = 5;
const int HP_ALIEN = 8;
const int ATTACK_DISTANCE_ALIEN_MONSTER = 250;
const int DAMAGE_ALIEN_MONSTER = 2;
const int SCORE_ALIEN_MONSTER = 30;

const int ALIEN_CLIPS[][4] = {
	{0, 0, 160, 192}, {160, 0, 160, 192}, {320, 0, 160, 192},
	{480, 0, 160, 192}, {640, 0, 160, 192}, {800, 0, 160, 192},
	{0, 192, 160, 192}, {160, 192, 160, 192}, {320, 192, 160, 192},
	{480, 192, 160, 192}, {640, 192, 160, 192}, {800, 192, 160, 192}
};
const int ALIEN_FRAMES = sizeof(ALIEN_CLIPS) / sizeof(int) / 4;

// SKill
const std::string LIGHTNING_PATH = "./Image\\Lightning.png";
const int LIGHTNING_WIDTH = 45;
const int LIGHTNING_HEIGHT = 65;

const int TIME_WAIT_LIGHTNING = 120;
const int TIME_ACTIVE_LIGHTNING = 10;
const int DAMAGE_LIGHTNING = 2;
const int LIGHTNING_CLIPS[][4] = {
	{0, 0, 100, 170}, {110, 0, 110, 170}, {240, 0, 100, 170}, {350, 0, 100, 170}, {465, 0, 110, 170},
	{0, 170, 100, 170}, {110, 170, 110, 170}, {240, 170, 100, 170}, {350, 170, 100, 170}, {465, 170, 110, 170}
};
const int LIGHTNING_FRAMES = sizeof(LIGHTNING_CLIPS) / sizeof(int) / 4;


// Knight Monster=======================================================================================================================================

const std::string IMAGE_KNIGHT_MONSTER_LEFT = "./Image\\KnightLeft.png";
const std::string IMAGE_KNIGHT_MONSTER_RIGHT = "./Image\\KnightRight.png";

const int KNIGHT_MONSTER_WIDTH = 45;
const int KNIGHT_MONSTER_HEIGHT = 50;
const int HP_KNIGHT_MONSTER = 30;
const int DAMAGE_KNIGHT_MONSTER = 2;
const int ATTACK_DISTANCE_KNIGHT_MONSTER = 250;
const int SCORE_KNIGHT_MONSTER = 50;

const int KNIGHT_MONSTER_CLIPS[][4] = {
	{0, 0, 121, 118},
	{121, 0, 121, 118},
	{242, 0, 121, 118},
	{363, 0, 121, 118},
	{0, 118, 121, 118},
	{121, 118, 121, 118},
	{242, 118, 121, 118},
	{363, 118, 121, 118}

};
const int KNIGHT_MONSTER_FRAMES = sizeof(KNIGHT_MONSTER_CLIPS) / sizeof(int) / 4;

// skill
const std::string FIRE_SWORD_PATH = "./Image\\FireSword.png";
const int FIRE_SWORD_WIDTH = 80;
const int FIRE_SWORD_HEIGHT = 80;

const int TIME_WAIT_FIRE_SWORD = 100;
const int TIME_ACTIVE_FIRE_SWORD = 8;
const int DAMAGE_FIRE_SWORD = 3;

const int FIRE_SWORD_CLIPS[][4] = {
	{0, 0, 140, 206}, {140, 0, 140, 206}, {380, 0, 160, 206}, {440, 0, 210, 206}, 
	{650, 0, 220, 206}, {870, 0, 220, 206}, {1090, 0, 198, 206}
};
const int FIRE_SWORD_FRAMES = sizeof(FIRE_SWORD_CLIPS) / sizeof(int) / 4;

// SOUNDS EFFECT
const std::string BACK_GORUND_MUSIC_PATH = "./Sound\\BackgroundMusic.mp3";

struct SoundInfo {
	std::string id;
	std::string path;
};

//Mix_Chunk* grow_thorn;
//Mix_Chunk* attack_sound;

const std::string BACKGORUND_MUSIC = "./Sound\\BackgorundMusic.mp3";

const std::vector<SoundInfo> SOUNDS = {
	{"game_intro_sound", "./Sound\\GameIntro.wav"},
	{"game_victory_sound", "./Sound\\GameVictory.wav"},
	{"game_defeat_sound", "./Sound\\GameDefeat.wav"},
	// Player
	{"slash_sword_sound", "./Sound\\Slash.wav"},
	//{"tornado_sound", "./Sound\\Tornado.wav"},
	//{"shield_sound", "./Sound\\Shield.wav"},
	//"healing_sound", "./Sound\\Healing.wav"},
	//{"player_take_damage_sound", "./Sound\\PlayerTakeDamage.wav"},
	//{"player_died_sound", "./Sound\\PlayerDied.wav"},
	// Monster
	{"teleport", "./Sound\\Teleport.wav"},
	//{"regeneration_sound", "./Sound\\Regeneration.wav"},
	//{"black_hole_sound", "./Sound\\BlackHole.wav"},
	//{"fire_explodesion_sound", "./Sound\\FireExplodesion.wav"},

};
const int AMOUNT_SOUNDS = sizeof(SOUNDS) / sizeof(SoundInfo);

// ENUM CLASS
enum class GameState{
	Intro,
	Instruction,
	Play,
	Pause,
	Defeat,
	Victory,
	Quit
};

enum class Direction {
	North, South, West,East,
	NorthWest, SouthWest, SouthEast, NorthEast	
};

#endif