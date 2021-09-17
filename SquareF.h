#pragma once  
#include "Figure.h"
class SquareF :public Figure {
public:

	DECLARE_SERIAL(SquareF)
	SquareF();
	SquareF(CPoint p1, CPoint p2, COLORREF color);
	~SquareF();
	void Draw(CDC *dc, const COLORREF &color)const;
	void Redefine(CPoint p1, CPoint p2);
};