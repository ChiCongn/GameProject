#pragma once
#ifndef DEFS_H
#define DEFS_H

/// GameObject
const std::string WINDOW_TITLE = "Soul knight version ccn :v";
#define BKGROUND_MUSIC_PATH "./Audio\\BkGroundMusic.mp3"
#define MAP_PATH "./Image\\Map.png"
#define AUDIO_GAME_INTRO_PATH "./Audio\\GameIntro.wav"
#define AUDIO_GAME_DEFEAT_PATH "./Audio\\GameDefeat.wav"
#define AUDIO_GAME_VICTORY_PATH "./Audio\\GameVictory.wav"
#define AUDIO_CHIBI_CHIBI_PATH "./Audio\\ChibiChibi.wav"
#define SCREEN_WIDTH  1200
#define SCREEN_HEIGHT  670

/// MenuGame
#define IMAGE_GAME_INTRO_PATH "./Image\\gameIntro.png"
#define IMAGE_GAME_INSTRUCTION_PATH "./Image\\GameInstructions.png"
#define IMAGE_GAME_VICTORY_PATH "./Image\\GameVictory.png"
#define IMAGE_GAME_DEFEAT_PATH "./Image\\GameDefeat.png"
#define IMAGE_CHIBI_CHIBI_PATH "./Image\\ChibiChibi.png"

const int CHIBI_CHIBI_CLIPS[][4] = { /// :))
	{0, 0, 158, 105}, {158, 0, 158, 105}, {316, 0, 158, 105},
	{475, 0, 158, 105}, {633, 0, 158, 105}, {791, 0, 158, 105},
	{0, 106, 158, 105}, {158, 106, 158, 105}, {316, 106, 158, 105},
	{475, 106, 158, 105}, {633, 106, 158, 105}, {791, 106, 158, 105},
	
};
const int CHIBI_CHIBI_FRAMES = sizeof(CHIBI_CHIBI_CLIPS) / sizeof(int) / 4;
const int CHIBI_CHIBI_WIDTH = 150;
const int CHIBI_CHIBI_HEIGHT = 100;

///PLAYER
#define IMAGE_PLAYER_PATH "./Image\\Player.png"
#define IMAGE_HP_PATH "./Image\\Hp.png"
#define IMAGE_EX_PATH "./Image\\Ex.png"
#define IMAGE_PLAYER_SKILL_PATH "./Image\\PlayerSkill.png"

#define AUDIO_GET_DAMAGE_PATH "./Audio\\GetDamage.wav"
#define AUDIO_LEVEL_UP_PATH "./Audio\\LevelUp.wav"
#define AUDIO_ATTACK_PATH "./Audio\\Attack.wav"
#define AUDIO_GET_EX_PATH "./Audio\\GetEx.wav"

const int MAX_HP_PLAYER = 10;
const int DEFAUT_DAMAGE_PLAYER = 2;
const int DEFAULT_SPEED_PLAYER = 25;
const int PLAYER_WIDTH = 70;
const int PLAYER_HEIGHT = 67;
const int PLAYER_SKILL_WIDTH = 90;
const int PLAYER_SKILL_HEIGHT = 85;
const int ADD_DAMAGE = 2;
const int ADD_SPEED = 5;

const int PLAYER_CLIPS[][4] = {
	{0, 0, 320, 307},
	{320, 0, 320, 307},
	{640, 0, 320, 307},
	{960, 0, 320, 307},
	{0, 307, 320, 307},
	{320, 307, 320, 307},
	{640, 307, 320, 307},
	{960, 307, 320, 307},


};
const int PLAYER_FRAMES = sizeof(PLAYER_CLIPS) / sizeof(int) / 4;

const int PLAYER_SLASH_CLIPS[][4] = {
	{0, 0, 102, 102},
	{102, 0, 102, 102},
	{204, 0, 102, 102},
	{306, 0, 102, 102},
	{408, 0, 102, 102}
};
const int PLAYER_SLASH_FRAMES = sizeof(PLAYER_SLASH_CLIPS) / sizeof(int) / 4;

const int PLAYER_SKILL_CLIPS[][4] = {
	{0, 0, 266, 228},
	{266, 0, 266, 228},
	{532, 0, 266, 228},
	{0, 229, 266, 228},
	{266, 229, 266, 228},
	{532, 229, 266, 228}
};
const int PLAYER_SKILL_FRAMES = sizeof(PLAYER_SKILL_CLIPS) / sizeof(int) / 4;

/// MONSTER-THREATS
#define AUDIO_THREAT_DEAD_PATH "./Audio\\ThreatDead.wav"
#define AUDIO_ATTACK_PLAYER_PATH "./Audio\\AttackPlayer.wav"
const int NEXT_TIME_CAUSE_DAMAGE = 4000;
//Boss
#define IMAGE_BOSS_MONSTER_PATH "./Image\\BossMonster.png"
#define IMAGE_BULLET_BOSS_MONSTER_PATH "./Image\\BulletBossMonster.png"
const int BOSS_MONSTER_WIDTH = 115;
const int BOSS_MONSTER_HEIGHT = 120;
const int DAMAGE_BOSS_MONSTER = 5;
const int SPEED_BOSS_MONSTER = 3;
const int HP_BOSS_MONSTER = 50;
const int BULLET_BOSS_MONSTER_WIDTH = 30;
const int BULLET_BOSS_MONSTER_HEIGHT = 30;
const int AMOUNT_BULLET_BOSS_MONSTER = 8;
const int SPEED_BOSS_MONSTER_BULLET = 5;
const int BOSS_MONSTER_CLIPS[][4] = {
	{0, 0, 261, 270},
	{261, 0, 261, 270},
	{523, 0, 261, 270},
	{0, 270, 261, 270},
	{261, 270, 261, 270},
	{523, 270, 261, 270}
};
const int BOSS_MONSTER_FRAMES = sizeof(BOSS_MONSTER_CLIPS) / sizeof(int) / 4;


//Normal Monster
#define AMOUNT_NORMAL_MONSTER 8
#define IMAGE_NORMAL_MONSTER_PATH "./Image\\NormalMonster.png"
#define IMAGE_BULLET_NORMAL_MONSTER_PATH "./Image\\BulletNormalMonster.png"
const int HP_NORMAL_MONSTER = 5;
const int NORMAL_MONSTER_WIDTH = 44;
const int NORMAL_MONSTER_HEIGHT = 50;
const int DAMAGE_NORMAL_MONSTER = 1;
const int SPEED_NORMAL_MONSTER = 2;
const int AMOUNT_BULLET_NORMAL_MONSTER = 4;
const int SPEED_NORMAL_MONSTER_BULLET = 1;
const int BULLET_NORMAL_MONSTER_WIDTH = 8;
const int BULLET_NORMAL_MONSTER_HEIGHT = 8;

const int PosXListNormalMonster[] = { 40, 120, 105, 325, 500, 535, 885, 1105 };
const int sizePosXListNormalMonster = sizeof(PosXListNormalMonster) / sizeof(int);
const int PosYListNormalMonster[] = { 435, 545, 160, 480, 175, 350, 120, 200 };
const int NORMAL_MONSTER_CLIPS[][4] = {
	{0,0, 213, 245},
	{213,0, 213, 245},
	{426,0, 213, 245},
	{640,0, 213, 245},
	{0,246, 213, 245},
	{213,246, 213, 245},
	{426,246, 213, 245},
	{640,246, 213, 245},
};
const int NORMAL_MONSTER_FRAMES = sizeof(NORMAL_MONSTER_CLIPS) / sizeof(int) / 4;

// Laser Monster
#define IMAGE_LAZER_MONSTER_PATH "./Image\\LazerMonster.png"
const int AMOUNT_LAZER_MONSTER = 7;
const int LAZER_MONSTER_WIDTH = 77;
const int LAZER_MONSTER_HEIGHT = 80;
const int HP_LAZER_MONSTER = 5;
const int DAMAGE_LAZER_MONSTER = 1;
const int SPEED_LAZER_MONSTER = 2;

const int PosXListLazerMonster[] = {5, 160, 230, 240, 480, 660, 660};
const int sizePosXListLazerMonster = sizeof(PosXListLazerMonster) / sizeof(int);
const int PosYListLazerMonster[] = {205, 350, 85, 535, 285, 150, 420 };

const int LAZER_MONSTER_CLIPS[][4] = {
	{0, 0, 259, 267},
	{259, 0, 259, 267},
	{519, 0, 259, 267},
	{0, 268, 259, 267},
	{259, 268, 259, 267},
	{519, 268, 259, 267},
};
const int LAZER_MONSTER_FRAMES = sizeof(LAZER_MONSTER_CLIPS) / sizeof(int) / 4;

// Obstacle
const SDL_Rect obstaclePos[] = { {120,435,285,45},{190,470,45,200},{235,260,45,175},{385,50,45,205},{500,410,45,45},{610,50,45,175},{610,360,45,310},
	{750,475,45,45},{785,190,95,45},{835,140,45,45},{935,535,150,45},{1035,485,45,45} };

enum class GameState{
	Intro,
	Instruction,
	Play,
	Defeat,
	Victory,
	Quit,
	Null
};

enum class Direction {
	North, South, West,East,
	NorthWest, SouthWest, SouthEast, NorthEast	
};

#endif