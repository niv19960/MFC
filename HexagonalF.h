#pragma once
#include "Figure.h"
class HexagonalF : public Figure
{
public:
	DECLARE_SERIAL(HexagonalF)
	HexagonalF();
	HexagonalF(CPoint p1, CPoint p2, COLORREF color);
	~HexagonalF(void);
	void Draw(CDC *dc, const COLORREF &color)const;
};