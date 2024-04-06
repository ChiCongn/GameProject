#pragma once
#ifndef DEFS_H
#define DEFS_H

/// Background
const std::string WINDOW_TITLE = "CCN";
#define BKGROUND_MUSIC_PATH "./Audio\\BkGroundMusic.mp3"
#define SCREEN_WIDTH  1200
#define SCREEN_HEIGHT  670
#define MAP_PATH "./Image\\Map.png"

///PLAYER
#define IMAGE_PLAYER_PATH "Image\\Player.png"
#define IMAGE_HP_PATH "./Image\\Hp.png"
#define IMAGE_EX_PATH "./Image\\Ex.png"

#define GET_DAMAGE_AUDIO_PATH "./Audio\\GetDamageAudio.wav"
#define LEVEL_UP_AUDIO_PATH "./Audio\\LevelUpAudio.wav"
#define ATTACK_AUDIO_PATH "./Audio\\AttackAudio.wav"
#define GET_EX_AUDIO_PATH "./Audio\\GetExAudio.wav"

const int MAX_HP_PLAYER = 100;
const int DEFAUT_DAMAGE_PLAYER = 2;
const int DEFAULT_SPEED_PLAYER = 25;
const int PLAYER_WIDTH = 75;
const int PLAYER_HEIGHT = 80;
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

/// MONSTER-THREATS
#define THREAT_DEAD_AUDIO_PATH "./Audio\\ThreatDeadAudio.wav"
#define ATTACK_PLAYER_AUDIO_PATH "./Audio\\AttackPlayerAudio.wav"
//Boss
#define BOSS_MONSTER_PATH "./Image\\BossMonster.png"
#define BULLET_BOSS_MONSTER_PATH "./Image\\BulletBossMonster.png"
const int BOSS_MONSTER_WIDTH = 115;
const int BOSS_MONSTER_HEIGHT = 120;
const int DAMAGE_BOSS_MONSTER = 5;
const int SPEED_BOSS_MONSTER = 3;
const int HP_BOSS_MONSTER = 100;
const int BULLET_BOSS_MONSTER_WIDTH = 30;
const int BULLET_BOSS_MONSTER_HEIGHT = 30;
const int AMOUNT_BULLET_BOSS_MONSTER = 8;
const int SPEED_BOSS_MONSTER_BULLET = 1;
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
#define NORMAL_MONSTER_PATH "./Image\\NormalMonster.png"
#define BULLET_NORMAL_MONSTER_PATH "./Image\\BulletNormalMonster.png"
const int HP_NORMAL_MONSTER = 5;
const int NORMAL_MONSTER_WIDTH = 52;
const int NORMAL_MONSTER_HEIGHT = 60;
const int DAMAGE_NORMAL_MONSTER = 1;
const int SPEED_NORMAL_MONSTER = 2;
const int AMOUNT_BULLET_NORMAL_MONSTER = 4;
const int SPEED_NORMAL_MONSTER_BULLET = 1;
const int BULLET_NORMAL_MONSTER_WIDTH = 10;
const int BULLET_NORMAL_MONSTER_HEIGHT = 10;

const int PosXListNormalMonster[] = { 40, 120, 105, 325, 500, 535, 885, 1105 };
const int sizePosXListNormalMonster = sizeof(PosXListNormalMonster) / sizeof(int);
const int PosYListNormalMonster[] = { 435, 555, 160, 480, 175, 350, 120, 200 };
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
#define LAZER_MONSTER_PATH "./Image\\LazerMonster.png"
const int AMOUNT_LAZER_MONSTER = 7;
const int LAZER_MONSTER_WIDTH = 44;
const int LAZER_MONSTER_HEIGHT = 60;
const int HP_LAZER_MONSTER = 5;
const int DAMAGE_LAZER_MONSTER = 2;
const int SPEED_LAZER_MONSTER = 0;

const int PosXListLazerMonster[] = {5, 160, 230, 240, 480, 660, 660};
const int sizePosXListLazerMonster = sizeof(PosXListLazerMonster) / sizeof(int);
const int PosYListLazerMonster[] = {205, 370, 85, 535, 285, 150, 420 };

const int LAZER_MONSTER_CLIPS[][4] = {
	{0, 0, 194, 267},
	{195, 0, 194, 267},
	{389, 0, 194, 267},
	{583, 0, 194, 267},
	{0, 268, 194, 267},
	{195, 268, 194, 267},
	{389, 268, 194, 267},
	{583, 268, 194, 267},
};
const int LAZER_MONSTER_FRAMES = sizeof(LAZER_MONSTER_CLIPS) / sizeof(int) / 4;

// Obstacle
const SDL_Rect obstaclePos[] = { {120,435,285,45},{190,470,45,200},{235,260,45,175},{385,50,45,205},{500,410,45,45},{610,50,45,175},{610,360,45,310},
	{750,475,45,45},{785,190,95,45},{835,140,45,45},{935,535,150,45},{1035,485,45,45} };

enum class GameState{
	Intro,
	Play,
	GameOver,
	Quit,
	Null
};

enum class Direction {
	North, South, West,East,
	NorthWest, SouthWest, SouthEast, NorthEast	
};

#endif