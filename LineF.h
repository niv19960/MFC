#pragma once
#include "Figure.h"
class LineF :public Figure {
	
	DECLARE_SERIAL(LineF)    
	
public:
	LineF() {}
	LineF(CPoint p1, CPoint p2, COLORREF color);
	void Draw(CDC* dc, const COLORREF &color) const;
};