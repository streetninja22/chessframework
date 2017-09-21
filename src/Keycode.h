#pragma once
#include "includeSDL.h"


namespace inpt
{
	enum KeyCode
	{
        KEYCODE_DEFAULT,
		KEYCODE_0,
		KEYCODE_1,
		KEYCODE_2,
		KEYCODE_3,
		KEYCODE_4,
		KEYCODE_5,
		KEYCODE_6,
		KEYCODE_7,
		KEYCODE_8,
		KEYCODE_9,

		KEYCODE_Q,
		KEYCODE_W,
		KEYCODE_E,
		KEYCODE_R,
		KEYCODE_T,
		KEYCODE_Y,
		KEYCODE_U,
		KEYCODE_I,
		KEYCODE_O,
		KEYCODE_P,
		KEYCODE_A,
		KEYCODE_S,
		KEYCODE_D,
		KEYCODE_F,
		KEYCODE_G,
		KEYCODE_H,
		KEYCODE_J,
		KEYCODE_K,
		KEYCODE_L,
		KEYCODE_Z,
		KEYCODE_X,
		KEYCODE_C,
		KEYCODE_V,
		KEYCODE_B,
		KEYCODE_N,
		KEYCODE_M
		//TODO finish inputting keycodes(stopped at letters)
	};

	//compiler whines if we don't have this static

	/* Converts an SDL_Scancode value to our KeyCode enum
	*
	* @param scancode the SDL_Scancode to convert
	*/
	static KeyCode scancodeToKeycode(SDL_Scancode scancode)
	{
		switch (scancode)
		{
			//ugh, tedious
		case (SDL_SCANCODE_0):
			return KeyCode::KEYCODE_0;

		case (SDL_SCANCODE_1):
			return KeyCode::KEYCODE_1;

		case (SDL_SCANCODE_2):
			return KeyCode::KEYCODE_2;

		case (SDL_SCANCODE_3):
			return KeyCode::KEYCODE_3;

		case (SDL_SCANCODE_4):
			return KeyCode::KEYCODE_4;

		case (SDL_SCANCODE_5):
			return KeyCode::KEYCODE_4;

		case (SDL_SCANCODE_6):
			return KeyCode::KEYCODE_6;

		case (SDL_SCANCODE_7):
			return KeyCode::KEYCODE_7;

		case (SDL_SCANCODE_8):
			return KeyCode::KEYCODE_8;

		case (SDL_SCANCODE_9):
			return KeyCode::KEYCODE_9;

		case (SDL_SCANCODE_A):
			return KeyCode::KEYCODE_A;

		case (SDL_SCANCODE_B):
			return KeyCode::KEYCODE_B;

		case (SDL_SCANCODE_C):
			return KeyCode::KEYCODE_C;

		case (SDL_SCANCODE_D):
			return KeyCode::KEYCODE_D;

		case (SDL_SCANCODE_E):
			return KeyCode::KEYCODE_E;

		case (SDL_SCANCODE_F):
			return KeyCode::KEYCODE_F;

		case (SDL_SCANCODE_G):
			return KeyCode::KEYCODE_G;

		case (SDL_SCANCODE_H):
			return KeyCode::KEYCODE_H;

		case (SDL_SCANCODE_I):
			return KeyCode::KEYCODE_I;

		case (SDL_SCANCODE_J):
			return KeyCode::KEYCODE_J;

		case (SDL_SCANCODE_K):
			return KeyCode::KEYCODE_K;

		case (SDL_SCANCODE_L):
			return KeyCode::KEYCODE_L;

		case (SDL_SCANCODE_M):
			return KeyCode::KEYCODE_M;

		case (SDL_SCANCODE_N):
			return KeyCode::KEYCODE_N;

		case (SDL_SCANCODE_O):
			return KeyCode::KEYCODE_O;

		case (SDL_SCANCODE_P):
			return KeyCode::KEYCODE_P;

		case (SDL_SCANCODE_Q):
			return KeyCode::KEYCODE_Q;

		case (SDL_SCANCODE_R):
			return KeyCode::KEYCODE_R;

		case (SDL_SCANCODE_S):
			return KeyCode::KEYCODE_S;

		case (SDL_SCANCODE_T):
			return KeyCode::KEYCODE_T;

		case (SDL_SCANCODE_U):
			return KeyCode::KEYCODE_U;

		case (SDL_SCANCODE_V):
			return KeyCode::KEYCODE_V;

		case (SDL_SCANCODE_W):
			return KeyCode::KEYCODE_W;

		case (SDL_SCANCODE_Y):
			return KeyCode::KEYCODE_Y;

		case (SDL_SCANCODE_X):
			return KeyCode::KEYCODE_X;

		case (SDL_SCANCODE_Z):
			return KeyCode::KEYCODE_Z;
		}
        
        return KEYCODE_DEFAULT;
	}
	
}
