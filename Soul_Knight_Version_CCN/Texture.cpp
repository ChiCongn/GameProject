
#include"Texture.h"

Texture::~Texture() {
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
		texture = nullptr;
	}
}

Texture::Texture(int _x, int _y, int _w, int _h) {
	coordinates.x = _x;
	coordinates.y = _y;
	coordinates.w = _w;
	coordinates.h = _h;
}

void Texture::setImageTexture(std::string imagePath, SDL_Renderer* renderer) {
	texture = loadImage(imagePath, renderer);
}

void Texture::setText(const std::string text, const SDL_Color color, const std::string fontPath, SDL_Renderer* renderer) {
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
		texture = nullptr;
	}
	texture = loadText(text, color, fontPath, renderer);
}

void Texture::render(SDL_Renderer* renderer) {
	SDL_RenderCopy(renderer, texture, NULL, &coordinates);
}

void Texture::move(int x, int y) {
	coordinates.x -= x;
	coordinates.y -= y;
}


// Map=====================================================
Map::Map(const std::string& path, SDL_Renderer* renderer) {
	map = loadImage(MAP_PATH, renderer);
	camera.x = camera.y = 100;
	camera.w = 1000;
	camera.h = SCREEN_HEIGHT;
	Map::takeTileMapMatrix();
}

Map::~Map() {
	SDL_DestroyTexture(map);
}

void Map::render(SDL_Renderer* renderer) {
	SDL_RenderCopy(renderer, map, &camera, &VIEWPORT);
}

void Map::move(int& x, int& y) {
	camera.x += x;
	camera.y += y;
	if (camera.x < 0) {
		camera.x = 0;
		x = 0;
	}
	if ( camera.x > MAP_WIDTH - VIEWPORT_WIDTH) {
		camera.x = MAP_WIDTH - VIEWPORT_WIDTH;
		x = 0;
	}
	if (camera.y < 0) {
		camera.y = 0;
		y = 0;
	}
	if (camera.y > MAP_HEIGHT - SCREEN_HEIGHT) {
		camera.y = MAP_HEIGHT - SCREEN_HEIGHT;
		y = 0;
	}
}

bool Map::isBoundary() {
	if (camera.x == 0 || camera.x == MAP_WIDTH - VIEWPORT_WIDTH || camera.y == 0 || camera.y == MAP_HEIGHT - VIEWPORT_HEIGHT)
		return true;
	return false;
}

void Map::newTurn() {
	camera.x = camera.y = 100;
}

void Map::takeTileMapMatrix() {
	tile_map = new int* [MAP_ROW];
	for (int i = 0; i < MAP_ROW; i++) {
		tile_map[i] = new int[MAP_COL];
	}
	std::ifstream file(MATRIX_TILE_MAP_PATH);
	if (!file.is_open()) {
		std::cout << "Error! Can not open file: " << std::endl;
	}
	for (int i = 0; i < MAP_ROW; i++) {
		for (int j = 0; j < MAP_COL; j++) {
			file >> tile_map[i][j];
		}
	}
	file.close();
}