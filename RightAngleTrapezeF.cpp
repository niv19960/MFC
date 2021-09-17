#include "StdAfx.h"
#include "RightAngleTrapezeF.h"

IMPLEMENT_SERIAL(RightAngleTrapezeF, CObject, 1)

RightAngleTrapezeF::RightAngleTrapezeF(){}
RightAngleTrapezeF::RightAngleTrapezeF(CPoint p1, CPoint p2, COLORREF color) : TrapezeF(p1, p2, color) {}
RightAngleTrapezeF::~RightAngleTrapezeF(){}


void RightAngleTrapezeF::Draw(CDC *dc, const COLORREF &color)const
{
	CPoint midlleP((P1.x + P2.x) / 2, (P1.y + P2.y) / 2);
	CPoint point(P1.x - (P2.x - P1.x), P2.y), point2(P1.x + (P2.x - P1.x), P1.y);

	CPoint angle[] = { P1, point , P2 ,point2 };
	TrapezeF::InnerDraw(angle, color, dc);
	
}

