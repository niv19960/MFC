#pragma once
//!! 14 b
#include "Figure.h"
class RectangleF : public Figure {

	DECLARE_SERIAL(RectangleF)   
	
public:
	
	RectangleF() {}
	RectangleF(CPoint p1, CPoint p2, const COLORREF &color);
};

