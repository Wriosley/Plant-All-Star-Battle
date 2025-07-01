#ifndef _UTIL_H_
#define _UTIL_H_

#include<graphics.h>
#pragma comment(lib, "MSIMG32.LIB") // 正确的写法


// 翻转图像
inline void flip_image(IMAGE* src, IMAGE* dst)
{
	if (!src || !dst) return;

	int w = src->getwidth();
	int h = src->getheight();
	Resize(dst, w, h);
	DWORD* src_buffer = GetImageBuffer(src);
	DWORD* dst_buffer = GetImageBuffer(dst);
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			int idx_src = y * w + x;
			int idx_dst = y * w + (w - 1 - x);
			dst_buffer[idx_dst] = src_buffer[idx_src];
		}
	}
}


inline void putimage_alpha(int x, int y, IMAGE* img)
{
	int w = img->getwidth();
	int h = img->getheight();
	AlphaBlend(GetImageHDC(NULL), x, y, w, h,
		GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER,0,255,AC_SRC_ALPHA });
}

#endif