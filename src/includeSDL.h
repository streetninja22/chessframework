#pragma once

//Included indirecty so that it will compile properly on Xcode and Visual Studio
#ifdef __APPLE__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif
