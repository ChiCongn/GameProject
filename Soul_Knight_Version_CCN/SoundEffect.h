
#include"Common.h"
#include"Defs.h"
#include<map>

class SoundManager {
public:
	SoundManager(const std::vector<SoundInfo>& sound);
	~SoundManager();
	void playSound(const std::string id);
	void playMusic();

	void toggleSound();
	void toggleMusic();

private:
	bool is_sound_on, is_music_on;
	Mix_Music* background_music;;
	std::map<std::string, Mix_Chunk*> sounds; 
};