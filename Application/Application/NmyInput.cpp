#include "NmyInput.h"

namespace Nmy
{
	std::vector<Input::Key> Input::mKeys;

	int ASCII[(UINT)eKeyCode::END] =
	{
		'Q', 'W', 'E', 'R',
		'T', 'Y', 'U', 'I',
		'O', 'P', 'A', 'S',
		'D', 'F', 'G', 'H',
		'J', 'K', 'Z', 'X',
		'C', 'V', 'B', 'N',

		// SPCIAL KEY
		VK_RETURN, VK_ESCAPE , VK_LSHIFT, VK_LMENU,
		VK_LCONTROL, VK_SPACE, VK_LEFT, VK_RIGHT, VK_UP , VK_DOWN,
		VK_LBUTTON, VK_RBUTTON,

		// NUMBER PAD
		VK_NUMPAD0, VK_NUMPAD1, VK_NUMPAD2, VK_NUMPAD3,
		VK_NUMPAD4, VK_NUMPAD5, VK_NUMPAD6, VK_NUMPAD7,
		VK_NUMPAD8, VK_NUMPAD9,

		// NUMBER LINE
		'0','1','2','3','4','5','6','7','8','9',


	};

	void Input::Initialize()
	{
		for (size_t i = 0; i < (UINT)eKeyCode::END; i++)
		{
			Key key;
			key.codeKey = (eKeyCode)i;
			key.stateKey = eKeyState::NONE;
			key.bPressed = false;

			mKeys.push_back(key);
		}

	}
	void Input::Tick()
	{
	
		for (UINT i = 0; i < (UINT)eKeyCode::END; i++)
		{
			// 해당 키가 현재 눌려져있는 경우
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				// 이전 프레임에 눌려져 있었다.
				//- 그러면 키보드를 누르고있는 상태
				if (mKeys[i].bPressed)
					mKeys[i].stateKey = eKeyState::PRESSED;
				else
					mKeys[i].stateKey = eKeyState::DOWN;

				mKeys[i].bPressed = true;
			}
			// 눌려져있지 않은 경우
			else
			{
				if (mKeys[i].bPressed)
					mKeys[i].stateKey = eKeyState::UP;
				else
					mKeys[i].stateKey = eKeyState::NONE;
				mKeys[i].bPressed = false;
			}
		}

	}
	void Input::Render(HDC hdc)
	{


	}


	eKeyState Input::GetKeystate(eKeyCode ekey)
	{
		return;
	}

}