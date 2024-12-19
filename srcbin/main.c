#include <stdio.h>
#include <SDL3/SDL.h>

int main(int argc, char* argv[]) {
    SDL_Window* window = NULL; 
    SDL_Renderer* renderer = NULL; 

    int result = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS); 
    if(result <0){
        SDL_Log("error: %s" , SDL_GetError); 
        return -1; 
    }
    
    window = SDL_CreateWindow("Hello World", 800 , 600 , 0);
    if(window == NULL){
        SDL_Log("error: %s" , SDL_GetError); 
        return -2; 
    } 
    
    renderer = SDL_CreateRenderer(window , NULL); 
    if(renderer == NULL){
        SDL_Log("error: %s" , SDL_GetError); 
        return -2; 
    } 

    SDL_Log("Ready to lunch");

    SDL_Event event; 
    int quit = 0; 
    while(!quit){
        while(SDL_PollEvent(&event)){
            switch(event.type){
            case SDL_EVENT_QUIT:
                SDL_Log("Quit");
                quit = 1; 
                break;  
            }
        }


        SDL_SetRenderDrawColor(renderer, 0, 0, 0xff, 0xff);
        SDL_RenderClear(renderer); 

        SDL_RenderPresent(renderer); 
        SDL_Delay(1); 
    }

    SDL_Log("Shutdown");
    SDL_DestroyRenderer(renderer); 
    SDL_DestroyWindow(window);

    SDL_Quit(); 


    return 0; 
}