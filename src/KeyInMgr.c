#include <KeyInMgr.h>

ae2f_SHAREDEXPORT void Input(SDL_Event* event)
{
    if(!event)  return;
    switch ((*event).type)
    {
        case SDL_EVENT_KEY_DOWN:
            switch ((*event).key.key)
            {
                case SDLK_K:
                    SDL_Log("Key up K"); 
                    break;
                        
                default:
                    break;
            }
            
            SDL_Log("Key down %d" , (*event).key);
            break;

            case SDL_EVENT_KEY_UP:
                SDL_Log("Key up %d" , (*event).key);
                break;
            
            break;
        
    default:
        break;
    }   
}