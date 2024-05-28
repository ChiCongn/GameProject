
#ifndef SOUNDS_EFFECT_H
#define SOUNDS_EFFECT_H

#include"Common.h"
#include"Defs.h"
#include<map>

class SoundManager {
public:
	SoundManager(const std::vector<SoundInfo>& sound, SDL_Renderer* renderer);
	~SoundManager();
	void render(SDL_Renderer* renderer);

	void playSound(const std::string id);
	void playMusic();

	void toggle(SDL_Event& e);
	//void turnOnSoundAndMusic();
	//void turnOffSoundAndMusic();
private:
	SDL_Texture* toggle_texture;
	SDL_Rect sound_position, music_position;
	bool is_sound_on, is_music_on;
	Mix_Music* background_music;
	std::map<std::string, Mix_Chunk*> sounds; 
};

#endif