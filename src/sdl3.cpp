#include "sdl3.h"


SDL3::SDL3()
{
    ppl7::PrintDebug("SDL3 Konstruktor\n");
    renderer=NULL;
    window=NULL;
	screensaver_enabled=SDL_ScreenSaverEnabled();
	if (screensaver_enabled) {
		SDL_DisableScreenSaver();
	}
}

SDL3::~SDL3()
{
    ppl7::PrintDebug("SDL3 Destruktor\n");
    destroyWindow();
    if (screensaver_enabled) {
		SDL_EnableScreenSaver();
	}
    
}

void SDL3::destroyWindow()
{
	if (renderer)
		SDL_DestroyRenderer(renderer);
	if (window)
		SDL_DestroyWindow(window);
	renderer=NULL;
	window=NULL;
}

void SDL3::createWindow(int width, int height, int x, int y, bool fullscreen)
{
	SDL_Rect desktop;
	SDL_GetDisplayBounds(0,&desktop);
    if (width<0) width=desktop.w;
    if (height<0) height=desktop.h;
    if (x<0) x=(desktop.w-width)/2;
    if (y<0) y=(desktop.h-height)/2;    
    int flags=0;
    if (fullscreen) flags|=SDL_WINDOW_FULLSCREEN;
	window=SDL_CreateWindow("SDL3 Window", width, height,flags);

	if (!window) {
		throw SDLException("Couldn't create SDL window: %s", SDL_GetError());
	}
	renderer = SDL_CreateRenderer(window, NULL );
    if (!renderer) {
        throw SDLException("Couldn't create SDL renderer: %s", SDL_GetError());
    }

    SDL_ShowWindow(window);

    SDL_SetWindowPosition(window,x,y);
}
