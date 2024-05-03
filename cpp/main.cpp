#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

class FallingChar {
private:
	char c;
	int x;
	int y;
	int speed;
public:
	FallingChar(char c, int x, int y, int speed) {
		this->c = c;
		this->x = x;
		this->y = y;
		this->speed = speed;
	}

	void draw() {
		// TODO Draw the character at (x, y)
		y += speed;
	}
};

int main(int argc, char** argv) {

		// Check the number of arguments
		if (argc != 3) {
			cerr << "Usage: " << argv[0] << " <width> <height>" << endl;
			return 1;
		}

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
        return 1;
    }

		// Window width and height
		const int SCREEN_WIDTH = atoi(argv[1]);
		const int SCREEN_HEIGHT = atoi(argv[2]);

    // Create a window
    SDL_Window* window = SDL_CreateWindow("Black Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
        return 1;
    }

    // Create a renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << endl;
        return 1;
    }

    // Set black background
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    // Wait until the window is closed
    bool quit = false;
    SDL_Event e;
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }
    }

    // Clean up and quit
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

