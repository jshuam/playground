#include <memory>
#include <SDL.h>
#include <stdio.h>
#include <string>

/*** Forward declarations **/

// Starts up SDL and creates a window
bool init();

// Loads media
bool loadMedia();

// Frees media and shuts down SDL
void close();

/*** Global variables ***/

// Window that will be rendered to
SDL_Window* gWindow(nullptr);

// Surface contained within the window (SDL_Surface is rendered by the CPU)
SDL_Surface* gScreenSurface(nullptr);

// The image that will be shown on screen
SDL_Surface* gHelloWorld(nullptr);

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main( int argc, char* args[] )
{
	if(!init())
	{
		printf("Failed to initialize\n");
	}
	else
	{
		if(!loadMedia())
		{
			printf("Failed to load media\n");
		}
		else
		{
			// Apply the image to the window's surface using blitting method
			SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);

			// Update the surface with the newly blitted image
			SDL_UpdateWindowSurface(gWindow);

			SDL_Delay(2000);
		}
		
	}
	
	close();

	return 0;
}

bool init()
{
	// Initialization flag
	bool success(true);

	// Initialize
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("[ERROR] SDL could not initialize. SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		// Create a new window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if(gWindow == nullptr)
		{
			printf("[ERROR] Window could not be created. SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			// Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
		
	}

	return success;
}

bool loadMedia()
{
	// Loading success flag
	bool success(true);

	// Filename for image
	std::string filename("hello_world.bmp");

	// Load splash image
	gHelloWorld = SDL_LoadBMP(filename.c_str());
	if(gHelloWorld == nullptr)
	{
		printf("[ERROR] Unable to load image %s. SDL_Error: %s\n", filename, SDL_GetError());
		success = false;
	}

	return success;
}

void close()
{
	// Deallocate SDL object memory
	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = nullptr;

	// This destroys the games window and the window's surface
	SDL_DestroyWindow(gWindow);
	gHelloWorld = nullptr;

	// Quit SDL subsystems
	SDL_Quit();
}