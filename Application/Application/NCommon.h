#pragma once

#include "framework.h"
#include <vector>
#include <string>
#include <map>
#include <list>

#include "def.h"
#include "Maths.h"

// typedef Pos POINT;
// �����Լ��� �̹� �����ϱ⿡ �ּ�ó�� 
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
