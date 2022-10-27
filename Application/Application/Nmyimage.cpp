#include "Nmyimage.h"
#include "myNewApplication.h"

namespace Nmy
{
	image::image()
		: mBitmap(NULL)
		, mhdc(NULL)
		, mWidth(0)
		, mheight(0)
	{

	}

	image::~image()
	{
		HWND newHwnd = NewApplication::Getinstance().GetWindowdata().hWnd;
		ReleaseDC(newHwnd, mhdc);
	}

	HRESULT image::Load(const std::wstring& path)
	{

		mBitmap = (HBITMAP)LoadImageW(nullptr, path.c_str(),
			IMAGE_BITMAP, 0, 0,
			LR_LOADFROMFILE | LR_LOADFROMFILE);
		if (mBitmap == nullptr)
		{
			return E_FAIL;
		}

		BITMAP bitInfo = {};
		GetObject(mBitmap, sizeof(BITMAP), &bitInfo);

		mWidth = bitInfo.bmWidth;
		mheight = bitInfo.bmHeight;

		HDC mainDC = NewApplication::Getinstance().GetWindowdata().hdc;
		mhdc = CreateCompatibleDC(mainDC);

		HBITMAP prevBit = (HBITMAP)SelectObject(mhdc,mBitmap);
		DeleteObject(prevBit);


		return S_OK;
	}


}