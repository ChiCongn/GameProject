#pragma once
#ifndef DEFS_H
#define DEFS_H

/// GameObject

#define SCREEN_WIDTH  840
#define SCREEN_HEIGHT  540
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

const int PAUSE_WIDTH = 200;
const int PAUSE_HEIGHT = 160;

/// Map
const int MAP_WIDTH = 1920;
const int MAP_HEIGHT = 1080;
const std::string IMAGE_LAND_PATH = "./Image\\Land.png";
const std::string IMAGE_LAKE_PATH = "./Image\\Lake.png";
const std::string IMAGE_GRASS_PATH = "./Image\\Grass.png";
const std::string IMAGE_WALL_PATH = "./Image\\Wall.png";
const std::string TILE_MATRIX_PATH = "./TileMatrix.txt";
const int TILE_WIDTH = 60;
const int TILE_HEIGHT = 60;

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
const std::string IMAGE_PLAYER_LEFT_PATH = "./Image\\MagicanLeft.png";
const std::string IMAGE_PLAYER_RIGHT_PATH = "./Image\\MagicanRight.png";
const std::string IMAGE_HP_PATH = "./Image\\Hp.png";
const std::string IMAGE_EX_PATH = "./Image\\Ex.png";
const std::string IMAGE_SLASH_LEFT_PATH = "./Image\\SlashLeft.png";
const std::string IMAGE_SLASH_RIGHT_PATH = "./Image\\SlashRight.png";

const std::string AUDIO_GET_DAMAGE_PATH = "./Audio\\GetDamage.wav";
const std::string AUDIO_LEVEL_UP_PATH = "./Audio\\LevelUp.wav";
const std::string AUDIO_ATTACK_PATH = "./Audio\\Slash.wav";
const std::string AUDIO_GET_EX_PATH = "./Audio\\GetEx.wav";


const int MAX_HP_PLAYER = 1000;
const int DEFAUT_DAMAGE_PLAYER = 2;
const int DEFAULT_SPEED_PLAYER = 10;
const int PLAYER_WIDTH = 60;
const int PLAYER_HEIGHT = 58;
const int PLAYER_SKILL_WIDTH = 100;
const int PLAYER_SKILL_HEIGHT = 100;
const int ADD_DAMAGE = 2;
const int ADD_SPEED = 5;

const int PLAYER_CLIPS[][4] = {
	{0, 0, 121, 118},
	{121, 0, 121, 118},
	{242, 0, 121, 118},
	{363, 0, 121, 118},
	{0, 118, 121, 118},
	{121, 118, 121, 118},
	{242, 118, 121, 118},
	{363, 118, 121, 118},


};
const int PLAYER_FRAMES = sizeof(PLAYER_CLIPS) / sizeof(int) / 4;

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
const int COOLDOWN = 3;
const int SPEED_SKILL = 3;
const int FIRE_WIDTH = 30;
const int FIRE_HEIGHT = 30;

const int PLAYER_SLASH_CLIPS[][4] = {
	{0, 0, 102, 102},
	{102, 0, 102, 102},
	{204, 0, 102, 102},
	{306, 0, 102, 102},
	{408, 0, 102, 102}
};
const int PLAYER_SLASH_FRAMES = sizeof(PLAYER_SLASH_CLIPS) / sizeof(int) / 4;

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
const std::string AUDIO_THREAT_DEAD_PATH = "./Audio\\ThreatDead.wav";
const std::string AUDIO_ATTACK_PLAYER_PATH = "./Audio\\AttackPlayer.wav";
const int NEXT_TIME_CAUSE_DAMAGE = 4000;
//Boss
const std::string IMAGE_BOSS_MONSTER_LEFT_PATH = "./Image\\BossMonsterLeft.png";
const std::string IMAGE_BOSS_MONSTER_RIGHT_PATH = "./Image\\BossMonsterRight.png";
const std::string IMAGE_BULLET_BOSS_MONSTER_PATH = "./Image\\BulletBossMonster.png";
const int BOSS_MONSTER_WIDTH = 115;
const int BOSS_MONSTER_HEIGHT = 120;
const int DAMAGE_BOSS_MONSTER = 5;
const int SPEED_BOSS_MONSTER = 3;
const int HP_BOSS_MONSTER = 50;
const int BULLET_BOSS_MONSTER_WIDTH = 30;
const int BULLET_BOSS_MONSTER_HEIGHT = 30;
const int AMOUNT_BULLET_BOSS_MONSTER = 8;
const int SPEED_BOSS_MONSTER_BULLET = 5;
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


//Normal Monster
const int AMOUNT_NORMAL_MONSTER = 8;
const std::string IMAGE_NORMAL_MONSTER_LEFT_PATH = "./Image\\NormalMonsterLeft.png";
const std::string IMAGE_NORMAL_MONSTER_RIGHT_PATH = "./Image\\NormalMonsterRight.png";
const std::string IMAGE_BULLET_NORMAL_MONSTER_PATH = "./Image\\BulletNormalMonster.png";

const int HP_NORMAL_MONSTER = 5;
const int NORMAL_MONSTER_WIDTH = 44;
const int NORMAL_MONSTER_HEIGHT = 50;
const int DAMAGE_NORMAL_MONSTER = 1;
const int SPEED_NORMAL_MONSTER = 2;
const int AMOUNT_BULLET_NORMAL_MONSTER = 4;
const int SPEED_NORMAL_MONSTER_BULLET = 1;
const int BULLET_NORMAL_MONSTER_WIDTH = 8;
const int BULLET_NORMAL_MONSTER_HEIGHT = 8;
const int MANA_NORMAL_MONSTER = 5;
const int POINT_NORMAL_MONSTER = 5;

const int PosXListNormalMonster[] = { 40, 120, 105, 325, 500, 535, 885, 1105 };
const int sizePosXListNormalMonster = sizeof(PosXListNormalMonster) / sizeof(int);
const int PosYListNormalMonster[] = { 435, 545, 160, 480, 175, 350, 120, 200 };

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

// Laser Monster
const std::string IMAGE_LAZER_MONSTER_LEFT_PATH = "./Image\\LazerMonsterLeft.png";
const std::string IMAGE_LAZER_MONSTER_RIGHT_PATH = "./Image\\LazerMonsterRight.png";
const int AMOUNT_LAZER_MONSTER = 7;
const int LAZER_MONSTER_WIDTH = 77;
const int LAZER_MONSTER_HEIGHT = 80;

const int HP_LAZER_MONSTER = 5;
const int DAMAGE_LAZER_MONSTER = 1;
const int SPEED_LAZER_MONSTER = 2;
const int MANA_LAZER_MONSTER = 6;
const int POINT_LAZER_MONSTER = 3;

const int PosXListLazerMonster[] = {5, 160, 230, 240, 480, 660, 660};
const int sizePosXListLazerMonster = sizeof(PosXListLazerMonster) / sizeof(int);
const int PosYListLazerMonster[] = {205, 350, 85, 535, 285, 150, 420 };

const int LAZER_MONSTER_CLIPS[][4] = {
	{0, 0, 256, 267},
	{256, 0, 256, 267},
	{512, 0, 256, 267},
	{0, 267, 256, 267},
	{256, 267, 256, 267},
	{512, 267, 256, 267},
};
const int LAZER_MONSTER_FRAMES = sizeof(LAZER_MONSTER_CLIPS) / sizeof(int) / 4;

// Obstacle
const SDL_Rect obstaclePos[] = { {120,435,285,45},{190,470,45,200},{235,260,45,175},{385,50,45,205},{500,410,45,45},{610,50,45,175},{610,360,45,310},
	{750,475,45,45},{785,190,95,45},{835,140,45,45},{935,535,150,45},{1035,485,45,45} };

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