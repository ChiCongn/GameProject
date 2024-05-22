
#include"SoundEffect.h"

SoundManager::SoundManager(const std::vector<SoundInfo>& sound) {
    is_music_on = true;
    is_sound_on = true;
    background_music = loadMusic(BACK_GORUND_MUSIC_PATH);
    for (const auto& sound_info : sound) {
        Mix_Chunk* chunk = loadSound(sound_info.path);
        if (chunk == nullptr) {
            std::cerr << "Failed to load sound: " << sound_info.path << " ->" << Mix_GetError() << std::endl;
        }
        else {
            sounds[sound_info.id] = chunk;
        }
    }
}

SoundManager::~SoundManager() {
    for (auto& pair : sounds) {
        Mix_FreeChunk(pair.second);
    }
    if (background_music) {
        Mix_FreeMusic(background_music);
    }
    Mix_CloseAudio();
}

void SoundManager::playSound(const std::string id) {
    if (is_sound_on) {
        auto it = sounds.find(id);
        if (it != sounds.end()) {
            Mix_PlayChannel(-1, it->second, 0);
        }
        else {
            std::cerr << "Sound ID not found: " << id << std::endl;
        }
    }
}

void SoundManager::playMusic() {
    if (is_music_on) {
        Mix_PlayMusic(background_music, -1);
    }
}

void SoundManager::toggleSound() {
    is_sound_on = !is_sound_on;
}

void SoundManager::toggleMusic() {
    is_music_on = !is_music_on;
    if (is_music_on) {
        Mix_ResumeMusic();
    }
    else {
        Mix_PauseMusic();
    }
}