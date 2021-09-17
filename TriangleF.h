#pragma once  
#include "Figure.h"
class TriangleF :public Figure {
public:

	DECLARE_SERIAL(TriangleF)
	TriangleF();
	TriangleF(CPoint p1, CPoint p2, COLORREF color);
	~TriangleF();
	void Draw(CDC *dc, const COLORREF &color)const;
	void InnerDraw(CPoint *TPoints, const COLORREF &color, CDC *dc)const;
};