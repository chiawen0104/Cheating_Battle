//
//  LWindow.cpp
//  Final Project
//
//  Created by 盧家雯 on 2022/1/2.
//

#include "SDLHeaders.h"
#include <stdio.h>
#include <string>
#include <sstream>
#include "LWindow.h"

LWindow::LWindow()
{
    mWindow = NULL;
    mFullScreen = false;
    mMinimized = false;
    mWidth = 0;
    mHeight = 0;
}

bool LWindow::init()
{
    mWindow = SDL_CreateWindow( "Cheating Battle", WINDOW_X, WINDOW_Y, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( mWindow != NULL )
    {
        mWidth = SCREEN_WIDTH;
        mHeight = SCREEN_HEIGHT;
    }

    return mWindow != NULL;
}

SDL_Renderer* LWindow::createRenderer()
{
    return SDL_CreateRenderer( mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
}

void LWindow::handleEvent( SDL_Event& e )
{
    if( e.type == SDL_WINDOWEVENT )
    {
        switch( e.window.event )
        {
            case SDL_WINDOWEVENT_SIZE_CHANGED:
            mWidth = e.window.data1;
            mHeight = e.window.data2;
            SDL_RenderPresent( gRenderer );
            break;

            case SDL_WINDOWEVENT_EXPOSED:
            SDL_RenderPresent( gRenderer );
            break;

            case SDL_WINDOWEVENT_MINIMIZED:
            mMinimized = true;
            break;

            case SDL_WINDOWEVENT_MAXIMIZED:
            mMinimized = false;
            break;
            
            case SDL_WINDOWEVENT_RESTORED:
            mMinimized = false;
            break;
        }
    }
}

void LWindow::free()
{
    if( mWindow != NULL )
    {
        SDL_DestroyWindow( mWindow );
    }
    mWidth = 0;
    mHeight = 0;
}

int LWindow::getWidth()
{
    return mWidth;
}

int LWindow::getHeight()
{
    return mHeight;
}

bool LWindow::isMinimized()
{
    return mMinimized;
}
