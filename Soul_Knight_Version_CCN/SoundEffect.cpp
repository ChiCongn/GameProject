
#include"SoundEffect.h"

SoundManager::SoundManager(const std::vector<SoundInfo>& sound, SDL_Renderer* renderer) {
    is_music_on = true;
    is_sound_on = true;
    for (const auto& sound_info : sound) {
        Mix_Chunk* chunk = loadSound(sound_info.path);
        if (chunk == nullptr) {
            std::cerr << "Failed to load sound: " << sound_info.path << " ->" << Mix_GetError() << std::endl;
        }
        else {
            sounds[sound_info.id] = chunk;
        }
    }
    background_music = loadMusic(BACKGROUND_MUSIC_PATH);
  
    toggle_texture = loadImage(TOGGLE_PATH, renderer);
    sound_position.x = 1010;
    music_position.x = 1090;
    sound_position.y = music_position.y = 10;
    sound_position.w = music_position.w = 50;
    sound_position.h = music_position.h = 50;

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

void SoundManager::render(SDL_Renderer* renderer) {
    if (is_sound_on) {
        SDL_RenderCopy(renderer, toggle_texture, &SOUND_MUSIC[3], &sound_position);
    }
    else {
        SDL_RenderCopy(renderer, toggle_texture, &SOUND_MUSIC[2], &sound_position);
    }
    if (is_music_on) {
        SDL_RenderCopy(renderer, toggle_texture, &SOUND_MUSIC[1], &music_position);
    }
    else {
        SDL_RenderCopy(renderer, toggle_texture, &SOUND_MUSIC[0], &music_position);
    }
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

void SoundManager::toggle(SDL_Event& e) {
    int x, y;
    SDL_GetMouseState(&x, &y);
    if (10 <= y && y <= 50) {
        if (1010 <= x && x <= 1060) {
            is_sound_on = !is_sound_on;
        }
        if (1090 <= x && x <= 1130) {
            is_music_on = !is_music_on;
            if (is_music_on) {
                Mix_ResumeMusic();
            }
            else {
                Mix_PauseMusic();
            }
        }
    }
}




