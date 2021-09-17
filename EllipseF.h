#pragma once
#include "Figure.h"
class EllipseF :public Figure {
	
	DECLARE_SERIAL(EllipseF)    
	
public:
	EllipseF() {}
	EllipseF(CPoint p1, CPoint p2, COLORREF color);
	void Draw(CDC* dc, const COLORREF &color) const;
};

