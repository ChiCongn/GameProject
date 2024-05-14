
#include<string>
#include<SDL.h>
#include<vector>

#ifndef DEFS_H
#define DEFS_H

/// GameObject

#define SCREEN_WIDTH  1028
#define SCREEN_HEIGHT  445
const std::string WINDOW_TITLE = "Made by ccn :v";
const std::string BKGROUND_MUSIC_PATH = "./Audio\\BkGroundMusic.mp3";
const std::string MAP_PATH = "./Image\\Map.png";
const std::string IMAGE_PAUSE_GAME_PATH = "./Image\\PauseGame.png";
const std::string AUDIO_GAME_INTRO_PATH = "./Audio\\GameIntro.wav";
const std::string AUDIO_GAME_DEFEAT_PATH = "./Audio\\GameDefeat.wav";
const std::string AUDIO_GAME_VICTORY_PATH = "./Audio\\GameVictory.wav";
const std::string AUDIO_CHIBI_CHIBI_PATH = "./Audio\\ChibiChibi.wav";
const std::string FONT_PATH = "BAUHS93.TTF";
const std::string HIGH_SCORE_PATH = "HighScore.txt";

const SDL_Color RED_COLOR = { 255, 0, 0 };
const SDL_Color LIGHT_BLUE_COLOR = { 0, 255, 255 };
const SDL_Color BLACK_COLOR = { 0, 0, 0 };

const int PAUSE_WIDTH = 200;
const int PAUSE_HEIGHT = 160;


/// MenuGame
#define IMAGE_GAME_INTRO_PATH "./Image\\MenuGame.png"
#define IMAGE_GAME_INSTRUCTION_PATH "./Image\\GameInstructions.png"
#define IMAGE_GAME_VICTORY_PATH "./Image\\GameVictory.png"
#define IMAGE_GAME_DEFEAT_PATH "./Image\\GameDefeat.png"
#define IMAGE_CHIBI_CHIBI_PATH "./Image\\ChibiChibi.png"

///PLAYER
const std::string IMAGE_PLAYER_LEFT_PATH = "./Image\\MagicanLeft.png";
const std::string IMAGE_PLAYER_RIGHT_PATH = "./Image\\MagicanRight.png";
const std::string IMAGE_HP_PATH = "./Image\\Hp.png";
const std::string IMAGE_EX_PATH = "./Image\\Ex.png";

const int MAX_HP_PLAYER = 10;
const int DAMAGE_PLAYER = 2;
const int SPEED_PLAYER = 10;
const int PLAYER_WIDTH = 30;
const int PLAYER_HEIGHT = 30;
const int TIME_UNDEAD = 15;

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
const std::string IMAGE_SLASH_LEFT_PATH = "./Image\\SlashSwordPlayerLeft.png";
const std::string IMAGE_SLASH_RIGHT_PATH = "./Image\\SlashSwordPlayerRight.png";

const int SLASH_SWORD_WIDTH = 60;
const int SLASH_SWORD_HEIGHT = 60;
const int TIME_WAIT_SLASH = 8;

const int PLAYER_SLASH_CLIPS[][4] = {
	{0, 0, 289, 214}
};
const int PLAYER_SLASH_FRAMES = sizeof(PLAYER_SLASH_CLIPS) / sizeof(int) / 4;

/// Skill
const std::string FIRE_BALL_PATH = "./Image\\FireBall.png";
const std::string ELECTRIC_BALL_PATH = "./Image\\ElectricBall.png";
const std::string TORNADO_EFFECT_PATH = "./Image\\TornadoEffect.png";

const int SKILL_WIDTH = 60;
const int SKILL_HEIGHT = 60;
const int TORNADO_WIDTH = 55;
const int TORNADO_HEIGHT = 60;
const int TIME_WAIT_SKILL = 30;
const int SPEED_SKILL = 3;
const int DAMAGE_SKILL = 2;

const int TIME_WAIT_TORNADO = 40;
const int TIME_ACTIVE_TORNADO = 15;
const int TORNADO_CLIPS[][4] = {
	{8, 12, 56, 44}, {72, 8, 48, 48}, {150, 4, 48, 52}, {220, 0, 55, 60},
	{0, 72, 52, 48}, {72, 68, 52, 52}, {144, 68, 60, 52}, {220, 68, 52, 60},
	{0, 140, 52, 48}, {72, 140, 52, 48}, {148, 140, 48, 48}, {220, 140, 48, 48},
	{8, 203, 40, 48}, {76, 196, 55, 48}, {148, 192, 48, 60}, {220, 200, 50, 50}
};
const int TORNADO_FRAMES = sizeof(TORNADO_CLIPS) / sizeof(int) / 4;

const int PLAYER_SKILL_CLIPS[][4] = {
	{0, 0, 163, 162}, {163, 0, 163, 162}, {326, 0, 163, 162}, {489, 0, 163, 162}, {652, 0, 163, 162},
	{0, 162, 163, 162}, {163, 162, 163, 162}, {326, 162, 163, 162}, {489, 162, 163, 162}, {652, 162, 163, 162},
};
const int PLAYER_SKILL_FRAMES = sizeof(PLAYER_SKILL_CLIPS) / sizeof(int) / 4;

/// Audio
const std::string AUDIO_GET_DAMAGE_PATH = "./Audio\\GetDamage.wav";
const std::string AUDIO_LEVEL_UP_PATH = "./Audio\\LevelUp.wav";
const std::string AUDIO_ATTACK_PATH = "./Audio\\Slash.wav";
const std::string AUDIO_GET_EX_PATH = "./Audio\\GetEx.wav";
/////////////////////////////

const std::string IMAGE_FIRE_PATH = "./Image\\FireFlame.png";

const int FIRE_CLIPS[][4] = {
	{0, 0, 120, 150},
	{120, 0, 120, 150},
	{240, 0, 120, 150},
	{360, 0, 120, 150},
	{0, 150, 120, 150},
	{120, 150, 120, 150},
	{240, 150, 120, 150},
	{360, 150, 120, 150},
};

const int FIRE_FRAMES = sizeof(FIRE_CLIPS) / sizeof(int) / 4;


/// MONSTER
const std::string AUDIO_THREAT_DEAD_PATH = "./Audio\\ThreatDead.wav";
const std::string AUDIO_ATTACK_PLAYER_PATH = "./Audio\\AttackPlayer.wav";
const int TIME_UNDEAD_MONSTER = 3;
const int TIME_WAIT_ATTACK = 25;
const int TIME_ATTACK = 2;

// STRUCTURE 
const std::string TOWER_PATH = "./Image\\Tower.png";
const std::string THORN_PATH = "./Image\\ThornGrow.png";

const int TOWER_WIDTH = 30;
const int TOWER_HEIGHT = 60;
const int HP_STRUCTURE = 30;
const int TIME_REGENERATION = 500;
const int DANGEROUS_ZONE = 100;

// Thorn
const int THORN_WIDTH = 18;
const int THORN_HEIGHT = 35;
const int TIME_THORN_GROW = 6;
const int TIME_WAIT_GROW = 50;

const int THORN_CLIPS[][4] = {
	{0, 0, 152, 276}, {0, 0, 152, 276}, {152, 0, 152, 276}, {152, 0, 152, 276},
	{304, 0, 152, 276}, {456, 0, 152, 276}, {0, 276, 152, 276}, {152, 152, 152, 276},
	{304, 0, 152, 276}, {456, 0, 152, 276}
};
const int THORN_FRAMES = sizeof(THORN_CLIPS) / sizeof(int) / 4;

//Boss
const std::string IMAGE_BOSS_MONSTER_LEFT_PATH = "./Image\\BossMonsterLeft.png";
const std::string IMAGE_BOSS_MONSTER_RIGHT_PATH = "./Image\\BossMonsterRight.png";
const std::string IMAGE_BULLET_BOSS_MONSTER_PATH = "./Image\\Bullet.png";
const std::string IMAGE_BLACK_HOLE_PATH = "./Image\\BlackHole.png";

const int BOSS_MONSTER_WIDTH = 80;
const int BOSS_MONSTER_HEIGHT = 90;
const int DAMAGE_BOSS_MONSTER = 5;
const int SPEED_BOSS_MONSTER = 3;
const int HP_BOSS_MONSTER = 50;

const int MANA_BOSS_MONSTER = 100;
const int POINT_BOSS_MONSTER = 200;

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
const int BLACK_HOLE_WIDTH = 40;
const int BLACK_HOLE_HEIGHT = 40;
const int TIME_WAIT_BLACK_HOLE = 35;
const int TIME_ACTIVE_BLACK_HOLE = 10;
const int BLACK_HOLE_CLIPS[][4] = {
	{0, 0, 0, 0}
};
const int BLACK_HOLE_FRAMES = sizeof(BLACK_HOLE_CLIPS) / sizeof(int) / 4;

const std::string FIRE_EXPLODESION_PATH = "./Image\\FireExplodesion.png";
const int FIRE_EXPLODESION_WIDTH = 110;
const int FIRE_EXPLODESION_HEIGHT = 120;
const int TIME_WAIT_FIRE_EXPLODESION = 100;
const int TIME_ACTIVE_FIRE_EXPLODESION = 10;
const int DAMAGE_FIRE_EXPLODESION = 3;

const int FIRE_EXPLODESION_CLIPS[][4] = {
	{0, 0, 160, 202}, {170, 0, 214, 202}, {430, 0, 190, 202},
	{650, 0, 220, 202}, {650, 0, 220, 202}, {888, 0, 257, 202}, 
	{888, 0, 257, 202}, {1150, 0, 194, 202}, {1150, 0, 194, 202}
};
const int FIRE_EXPLODESION_FRAMES = sizeof(FIRE_EXPLODESION_CLIPS) / sizeof(int) / 4;

//Normal Monster
const std::string IMAGE_NORMAL_MONSTER_LEFT_PATH = "./Image\\NormalMonsterLeft.png";
const std::string IMAGE_NORMAL_MONSTER_RIGHT_PATH = "./Image\\NormalMonsterRight.png";

const int NORMAL_MONSTER_WIDTH = 28;
const int NORMAL_MONSTER_HEIGHT = 30;
const int HP_NORMAL_MONSTER = 10;
const int DAMAGE_NORMAL_MONSTER = 1;
const int SPEED_NORMAL_MONSTER = 2;

const int MANA_NORMAL_MONSTER = 5;
const int POINT_NORMAL_MONSTER = 5;
const int ATTACK_DISTANCE_NORMAL_MONSTER = 100;

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

// Poison Monster
const std::string IMAGE_POISON_MONSTER_LEFT_PATH = "./Image\\LazerMonsterLeft.png";
const std::string IMAGE_POISON_MONSTER_RIGHT_PATH = "./Image\\LazerMonsterRight.png";
const std::string IMAGE_POISON_MOSTER_SKILL = "./Iamge\\Poison.png";

const int POISON_MONSTER_WIDTH = 77;
const int POISON_MONSTER_HEIGHT = 80;

const int HP_POISON_MONSTER = 5;
const int DAMAGE_POISON_MONSTER = 1;
const int SPEED_POISON_MONSTER = 2;

const int ATTACK_DISTANCE_POISON_MONSTER = 80;

const int POISON_MONSTER_CLIPS[][4] = {
	{0, 0, 256, 267},
	{256, 0, 256, 267},
	{512, 0, 256, 267},
	{0, 267, 256, 267},
	{256, 267, 256, 267},
	{512, 267, 256, 267},
};
const int POISON_MONSTER_FRAMES = sizeof(POISON_MONSTER_CLIPS) / sizeof(int) / 4;

// Alien Monster
const std::string IMAGE_ALIEN_MONSTER_LEFT = "./Image\\AlienLeft.png";
const std::string IMAGE_ALIEN_MONSTER_RIGHT = "./Image\\AlienRight.png";
const std::string IMAGE_ALIEN_MONSTER_SKILL = "./Image\\Laze.png";
const std::string LASER_PATH = "./Image\\Laser.png";

const int ALIEN_WIDTH = 30;
const int ALIEN_HEIGHT = 30;
const int HP_ALIEN_MONSTER = 25;
const int SPEED_ALIEN = 5;
const int HP_ALIEN = 8;
const int ATTACK_DISTANCE_ALIEN_MONSTER = 150;
const int DAMAGE_ALIEN_MONSTER = 2;

const int ALIEN_CLIPS[][4] = {
	{0, 0, 160, 192}, {160, 0, 160, 192}, {320, 0, 160, 192},
	{480, 0, 160, 192}, {640, 0, 160, 192}, {800, 0, 160, 192},
	{0, 192, 160, 192}, {160, 192, 160, 192}, {320, 192, 160, 192},
	{480, 192, 160, 192}, {640, 192, 160, 192}, {800, 192, 160, 192}
};
const int ALIEN_FRAMES = sizeof(ALIEN_CLIPS) / sizeof(int) / 4;

// Knight Monster

const std::string IMAGE_KNIGHT_MONSTER_LEFT = "./Image\\KnightLeft.png";
const std::string IMAGE_KNIGHT_MONSTER_RIGHT = "./Image\\KnightRight.png";
const std::string DUAL_SWORDS_PATH = "./Image\\DualSwords.png";

const int KNIGHT_MONSTER_WIDTH = 30;
const int KNIGHT_MONSTER_HEIGHT = 30;
const int HP_KNIGHT_MONSTER = 5;
const int DAMAGE_KNIGHT_MONSTER = 2;
const int ATTACK_DISTANCE_KNIGHT_MONSTER = 100;
const int TIME_TELEPORT = 150;

const int DUAL_SWORDS_WIDTH = 50;
const int DUAL_SWORDS_HEIGHT = 45;

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