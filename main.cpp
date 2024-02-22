#include <iostream>

#include <SDL2/SDL.h>
#include <stdlib.h>

#include "src/window_context.h"

int main(void)
{
    WindowContext window_context;
    window_context.height = 640;
    window_context.width = 480;
    window_context.x = 0;
    window_context.y = 0;

    //The window we'll be rendering to
    SDL_Window* window = NULL;

    //The surface contained by the window
    SDL_Surface* screenSurface = NULL;    

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return(1);
    }

    //Create window
    window = SDL_CreateWindow( "SDL Tutorial", 
        window_context.x,
        window_context.y,
        window_context.width,
        window_context.height,
        SDL_WINDOW_SHOWN 
    );

    if( window == NULL )
    {
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
    }

    //Get window surface
    screenSurface = SDL_GetWindowSurface( window );

    //Fill the surface white
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x00, 0xFF, 0xFF));
    
    SDL_Rect small;
    small.x = 100;
    small.y = 100;
    small.w = 50;
    small.h = 50;

    SDL_FillRect(screenSurface, &small, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
    
    //Update the surface
    SDL_UpdateWindowSurface( window );

    //Hack to get window to stay up
    SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
    

    // Draw

    


    SDL_DestroyWindow( window );

    //Quit SDL subsystems
    SDL_Quit();

    std::cout << "Hello World" <<std::endl;
    return(0);
}