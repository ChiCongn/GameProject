#pragma once
#ifndef DEFS_H
#define DEFS_H

/// Background
#define BKGROUND_MUSIC_PATH "./Audio/BkGroundMusic.mp3"
#define SCREEN_WIDTH  1000
#define SCREEN_HEIGHT  650

///PLAYER
#define IMAGE_PLAYER_LEFT_PATH "./Image/PlayerLeft.png"
#define IMAGE_PLAYER_RIGHT_PATH ".Image/PlayerRight.png"
#define GET_DAMAGE_AUDIO_PATH "./Audio/GetDamageAudio.wav"
#define LEVEL_UP_AUDIO_PATH "./Audio/LevelUpAudio.wav"
#define ATTACK_AUDIO_PATH "./Audio/AttackAudio.wav"
#define GET_EX_AUDIO_PATH "./Audio/GetExAudio.wav"

#define MAX_HP_PLAYER  5
#define DEFAUT_DAMAGE_PLAYER  2
#define PLAYER_WIDTH  60
#define PLAYER_HEIGHT  60
#define ADD_DAMAGE  2
#define ADD_SPEED 5

/// MONSTER-THREATS
#define THREAT_DEAD_AUDIO_PATH "./Audio/ThreatDeadAudio.wav"
#define ATTACK_PLAYER_AUDIO_PATH "./Audio/AttackPlayerAudio.wav"
//Boss
#define BOSS_PATH "./Image/Boss.png"
#define BOSS_BULLET_PATH "./Image/BossBullet.png"
#define DAMAGE_BOSS 5
#define SPEED_BOSS 10
#define HP_BOSS 100

//Normal Monster
#define AMOUNT_NORMAL_MONSTER 8
#define NORMAL_MONSTER_PATH "./Image/NormalMonster.png"
#define HP_NORMAL_MONSTER 5
#define NORMAL_MONSTER_WIDTH 10
#define NORMAL_MONSTER_HEIGHT 10
#define DAMAGE_NORMAL_MONSTER 1
#define SPEED_NORMAL_MONSTER 3
const int PosXListNormalMonster[] = { 3,4,5,6 };
const int sizePosXListNormalMonster = sizeof(PosXListLazerMonster) / sizeof(int);

// Laser Monster
#define LAZER_MONSTER_PATH "./Image/LazerMonster.png"
#define AMOUNT_LAZER_MONSTER 6
#define LAZER_MONSTER_WIDTH 12
#define LAZER_MONSTER_HEIGHT 12
#define HP_LAZER_MONSTER 5
#define DAMAGE_LAZER_MONSTER 2
#define SPEED_LAZER_MONSTER 0
const int PosXListLazerMonster[] = {3,4,5,6};
const int sizePosXListLazerMonster = sizeof(PosXListNormalMonster) / sizeof(int);

enum class GameState{
	Intro,
	Play,
	GameOver,
	Quit,
	Null
};

#endif