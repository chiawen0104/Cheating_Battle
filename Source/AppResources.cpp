#include <stdio.h>
#include <unistd.h>
#include "SDLHeaders.h"
#include "AppResources.h"

bool AppResources::useResourceDirectory()
{
    char* basePath = SDL_GetBasePath();
    if( basePath == NULL )
    {
        printf( "Could not find the resource directory! SDL Error: %s\n", SDL_GetError() );
        return false;
    }

    bool success = chdir( basePath ) == 0;
    if( !success )
    {
        printf( "Could not enter resource directory %s\n", basePath );
    }
    SDL_free( basePath );
    return success;
}
