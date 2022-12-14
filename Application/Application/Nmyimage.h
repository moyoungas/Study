#pragma once
#include "NmyResource.h"

namespace Nmy
{
	class image : public Resource
	{
	public:
		image();
		~image();

		virtual HRESULT Load(const std::wstring& path) override;

		HDC GetDc() { return mhdc; }
		UINT GetWidth() { return mWidth; }
		UINT GetHeight() { return mheight; }
	private:
		HBITMAP	mBitmap;
		HDC mhdc;
		UINT mWidth;
		UINT mheight;


	};



}