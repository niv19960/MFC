#include "StdAfx.h"
#include "TrapezeF.h"

IMPLEMENT_SERIAL(TrapezeF, CObject, 1)

TrapezeF::TrapezeF() {}

TrapezeF::TrapezeF(CPoint p1, CPoint p2, COLORREF color)
	:Figure(p1, p2, color) {}

TrapezeF::~TrapezeF() {}

void TrapezeF::Draw(CDC *dc,  const COLORREF &color)const 
{
	CPoint TrapezePoints[4];
	TrapezePoints[0].SetPoint(P1.x, P2.y);
	TrapezePoints[1].SetPoint(P2.x, P2.y);
	TrapezePoints[2].SetPoint((P2.x - P1.x) * 3 / 4 + P1.x, P1.y);
	TrapezePoints[3].SetPoint((P2.x - P1.x) * 1 / 4 + P1.x, P1.y);
	InnerDraw(TrapezePoints, color, dc);
}

void TrapezeF::InnerDraw(CPoint *TrapezePoints, const COLORREF &color, CDC *dc)const
{
	CBrush brush(color);
	CBrush *oldBrush = dc->SelectObject(&brush);
	dc->Polygon(TrapezePoints, 4);
}