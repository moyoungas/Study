#pragma once

#define KEY_PRESSED(KEY) Nmy::Input::GetKeystate(KEY) == Nmy::eKeyState::PRESSED
#define KEY_DOWN(KEY) Nmy::Input::GetKeystate(KEY) == Nmy::eKeyState::DOWN
#define KEY_UP(KEY) Nmy::Input::GetKeystate(KEY) == Nmy::eKeyState::UP

enum class eSceneType
{

	Logo,
	Title,
	Play,
	End,
	MAX,

};