#ifndef SDL3_H_
#define SDL3_H_

#include "ppl7.h"
#include "SDL3/SDL.h"

class SDLException : public ppl7::Exception
{
public:
    SDLException() noexcept {};
	SDLException(const char *msg, ...) noexcept {
		va_list args; va_start(args, msg); copyText(msg,args);
		va_end(args);
    };
    const char* what() const noexcept override{
        return (STR_VALUE(SDLException));
    };
};

class SDL3
{
    private:
        bool screensaver_enabled;
        SDL_Window *window;
        SDL_Renderer *renderer;
    public:
        SDL3();
        ~SDL3();
        void createWindow(int width, int height, int x=-1, int y=-1, bool fullscreen=false);
        void destroyWindow();

};

#endif // SDL3_H_
