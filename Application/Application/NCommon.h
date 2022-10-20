#pragma once

#include "framework.h"
#include <vector>
#include <string>
#include <map>
#include <list>

#include "def.h"
#include "Maths.h"

// typedef Pos POINT;
// 메인함수에 이미 존재하기에 주석처리 
//using Pos = POINT;

struct WindowDataA
{
	HWND hWnd;
	HDC hdc;
	UINT height;
	UINT width;
	
	void clear()
	{
		HWND hWnd = nullptr;
		HDC hdc = nullptr;
		UINT height = 0;
		UINT width = 0;
	}



};
