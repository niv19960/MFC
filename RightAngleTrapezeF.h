#pragma once  
#include "TrapezeF.h"
class RightAngleTrapezeF :public TrapezeF {
public:
	DECLARE_SERIAL(RightAngleTrapezeF)

	RightAngleTrapezeF();
	RightAngleTrapezeF(CPoint p1, CPoint p2, COLORREF color);
	~RightAngleTrapezeF();

	void Draw(CDC *dc, const COLORREF &color)const;
	void InnerDraw(CPoint *TrapezePoints, const COLORREF &color, CDC *dc)const;
	
		
		
};