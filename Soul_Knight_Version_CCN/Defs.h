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
#define IMAGE_PLAYER_LEFT_PATH "Image\\PlayerLeft.png"
#define IMAGE_PLAYER_RIGHT_PATH "Image\\PlayerRight.png"
#define IMAGE_HP_PATH "./Image\\Hp.png"
#define IMAGE_EX_PATH "./Image\\Ex.png"

#define GET_DAMAGE_AUDIO_PATH "./Audio\\GetDamageAudio.wav"
#define LEVEL_UP_AUDIO_PATH "./Audio\\LevelUpAudio.wav"
#define ATTACK_AUDIO_PATH "./Audio\\AttackAudio.wav"
#define GET_EX_AUDIO_PATH "./Audio\\GetExAudio.wav"

#define MAX_HP_PLAYER  5
#define DEFAUT_DAMAGE_PLAYER  2
#define DEFAULT_SPEED_PLAYER 25
#define PLAYER_WIDTH  60
#define PLAYER_HEIGHT  60
#define ADD_DAMAGE  2
#define ADD_SPEED 5

/// MONSTER-THREATS
#define THREAT_DEAD_AUDIO_PATH "./Audio\\ThreatDeadAudio.wav"
#define ATTACK_PLAYER_AUDIO_PATH "./Audio\\AttackPlayerAudio.wav"
//Boss
#define BOSS_PATH "./Image\\Boss.png"
#define BULLET_BOSS_MONSTER_PATH "./Image\\BossBullet.png"
#define BOSS_MONSTER_WIDTH 100
#define BOSS_MONSTER_HEIGHT 100
#define DAMAGE_BOSS_MONSTER 5
#define SPEED_BOSS_MONSTER 10
#define HP_BOSS_MONSTER 100
#define BULLET_BOSS_MONSTER_WIDTH 30
#define BULLET_BOSS_MONSTER_HEIGHT 30

//Normal Monster
#define AMOUNT_NORMAL_MONSTER 8
#define NORMAL_MONSTER_RIGHT_PATH "./Image\\NormalMonsterRight.png"
#define NORMAL_MONSTER_LEFT_PATH "./Image\\NormalMonsterLeft.png"
#define BULLET_NORMAL_MONSTER_PATH "./Image\\BulletNormalMonster.png"
#define HP_NORMAL_MONSTER 5
#define NORMAL_MONSTER_WIDTH 60
#define NORMAL_MONSTER_HEIGHT 50
#define DAMAGE_NORMAL_MONSTER 1
#define SPEED_NORMAL_MONSTER 2
#define AMOUNT_BULLET_NORMAL_MONSTER 4
#define SPEED_NORMAL_MONSTER_BULLET 1
#define BULLET_NORMAL_MONSTER_WIDTH 10
#define BULLET_NORMAL_MONSTER_HEIGHT 10

const int PosXListNormalMonster[] = { 40, 120, 105, 325, 500, 535, 885, 1105 };
const int sizePosXListNormalMonster = sizeof(PosXListNormalMonster) / sizeof(int);
const int PosYListNormalMonster[] = { 435, 555, 160, 480, 175, 350, 120, 200 };
// Laser Monster
#define LAZER_MONSTER_RIGHT_PATH "./Image\\LazerMonsterRight.png"
#define LAZER_MONSTER_LEFT_PATH "./Image\\LazerMonsterLeft.png"
#define AMOUNT_LAZER_MONSTER 7
#define LAZER_MONSTER_WIDTH 60
#define LAZER_MONSTER_HEIGHT 60
#define HP_LAZER_MONSTER 5
#define DAMAGE_LAZER_MONSTER 2
#define SPEED_LAZER_MONSTER 0
const int PosXListLazerMonster[] = {5, 160, 230, 240, 480, 660, 660};
const int sizePosXListLazerMonster = sizeof(PosXListLazerMonster) / sizeof(int);
const int PosYListLazerMonster[] = {205, 370, 85, 535, 285, 150, 420 };

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