
#include"Tile.h"

void Tile::initTile(const std::string path, SDL_Renderer* renderer) {
	coordinates.w = TILE_WIDTH;
	coordinates.h = TILE_HEIGHT;
	texture = loadImage(path,renderer);
}

Tile::~Tile() {
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
		texture = nullptr;
	}
}

void Tile::renderTile(SDL_Renderer* renderer) {
	SDL_RenderCopy(renderer, texture, NULL, &coordinates);
}


//// MAP


std::vector<std::vector<int>> Map::getTileMatrix() {
	std::vector<std::vector<int>> matrix;
	std::ifstream file(TILE_MATRIX_PATH);
	if (!file.is_open()) {
		std::cout << "Can not open file with path: " << TILE_MATRIX_PATH << std::endl;
	}
	std::string line;
	while (std::getline(file, line)) {
		std::vector<int> row;
		std::istringstream iss(line);
		int element;
		while (iss >> element) {
			row.push_back(element);
		}
		matrix.push_back(row);
	}
	file.close();
	return matrix;
}

Map::Map(SDL_Renderer* renderer) {
	x = y = 0;
	camera.x = camera.y = 0;
	camera.w = SCREEN_WIDTH;
	camera.h = SCREEN_HEIGHT;
	std::vector<std::vector<int>> grid = Map::getTileMatrix();
	texture = loadImage(MAP_PATH, renderer);
	/*for (int i = 0; i < 18; i++) {
		for (int j = 0; j < 32; j++) {
			switch (matrix[i][j])
			{
			case 1:
				grid[i][j].initTile(IMAGE_GRASS_PATH, renderer);
				break;

			case 2:
				grid[i][j].initTile(IMAGE_LAKE_PATH, renderer);
				break;

			case 3:
				grid[i][j].initTile(IMAGE_WALL_PATH, renderer);
				break;

			default:
				grid[i][j].initTile(IMAGE_LAND_PATH, renderer);
				break;
			}
			grid[i][j].setCoordinates(i * TILE_WIDTH, j * TILE_HEIGHT);
		}
	}*/
}

void Map::renderMap(SDL_Renderer* renderer) {

	SDL_RenderCopy(renderer, texture, &camera, NULL);
}

void Map::updateCamera() {
	camera.x = x;
	camera.y = y;
	//std::cout <<"position of camera: "<< camera.x << camera.y << std::endl;
	if (camera.x < 0) {
		camera.x = 0;
	}
	if (camera.x > MAP_WIDTH-SCREEN_WIDTH) {
		camera.x = MAP_WIDTH - SCREEN_WIDTH;
	}
	if (camera.y < 0) {
		camera.y = 0;
	}
	if (camera.y > MAP_HEIGHT - SCREEN_HEIGHT) {
		camera.x = MAP_HEIGHT - SCREEN_HEIGHT;
	}
}
