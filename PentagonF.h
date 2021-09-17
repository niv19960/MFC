#pragma once
#include "Figure.h"
class PentagonF : public Figure
{
public:
	DECLARE_SERIAL(PentagonF)
	PentagonF();
	PentagonF(CPoint p1, CPoint p2, COLORREF color);
	~PentagonF(void);
	void Draw(CDC *dc, const COLORREF &color)const;
};