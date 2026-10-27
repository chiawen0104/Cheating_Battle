#ifndef SDLHEADERS_H
#define SDLHEADERS_H

// Single place that pulls in every SDL library the game uses.
// Include directories are supplied by the build (pkg-config in the Makefile),
// so no install location is hard-coded here.
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#endif
