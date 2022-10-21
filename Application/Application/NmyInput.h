#pragma once
#include "NCommon.h"

namespace Nmy
{
	enum class eKeyCode
	{
		Q, W, E, R,
		T, Y, U, I,
		O, P, A, S,
		D, F, G, H,
		J, K, Z, X,
		C, V, B, N,

		// SPCIAL KEY
		ENTER, ESC, LSHIFT, LALT, LCTRL,
		SPACE, LEFT, RIGHT, UP, DOWN,
		LBTN, RBTN,
		// NUM PAD
		NUM_0, NUM_1, NUM_2,
		NUM_3, NUM_4, NUM_5,
		NUM_6, NUM_7, NUM_8,
		NUM_9,

		// NUM LINE
		N_0, N_1, N_2, N_3, N_4, N_5, N_6, N_7, N_8, N_9,

		END,
	};

	enum class eKeyState
	{
		DOWN,
		PRESSED,
		UP,
		NONE,

	};

	class Input
	{
	public:

		struct Key
		{
			eKeyCode codeKey;
			eKeyState stateKey;
			bool bPressed;

		};

		static void Initialize();
		static void Tick();
		static void Render(HDC hdc);
		static eKeyState GetKeystate(eKeyCode ekey);

	private:
		static std::vector<Key> mKeys;

	};

}