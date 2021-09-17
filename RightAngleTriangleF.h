#pragma once  
#include "TriangleF.h"

class RightAngleTriangleF :public TriangleF {
public:
	DECLARE_SERIAL(RightAngleTriangleF)

	RightAngleTriangleF();
	RightAngleTriangleF(CPoint p1, CPoint p2, COLORREF color);
	~RightAngleTriangleF();

	void Draw(CDC *dc, const COLORREF &color)const;
	void InnerDraw(CPoint *TPoints, const COLORREF &color, CDC *dc)const;



};