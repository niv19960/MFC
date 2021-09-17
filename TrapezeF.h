#pragma once
#include "Figure.h"
class TrapezeF :public Figure	
{
public:
	DECLARE_SERIAL(TrapezeF)
	TrapezeF();
	TrapezeF(CPoint p1, CPoint p2, COLORREF color);
	~TrapezeF();
	void Draw(CDC *dc, const COLORREF &color)const ;
	void InnerDraw(CPoint *TrapezePoints, const COLORREF &color, CDC *dc)const;
};
