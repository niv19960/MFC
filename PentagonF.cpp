#include "StdAfx.h"
#include "PentagonF.h"

IMPLEMENT_SERIAL(PentagonF, CObject, 1)

PentagonF::PentagonF() {}
PentagonF::PentagonF(CPoint p1, CPoint p2, COLORREF color) :Figure(p1, p2, color)
{}
PentagonF::~PentagonF() {}

void PentagonF::Draw(CDC *dc, const COLORREF &color) const
{
	CPoint pentagonPoints[5];

	pentagonPoints[0].SetPoint(P1.x, P2.y);
	pentagonPoints[1].SetPoint(P2.x, P2.y);
	pentagonPoints[2].SetPoint(P2.x + (P2.x - P1.x), (P2.y + P1.y)*0.5);
	pentagonPoints[3].SetPoint(P2.x, P1.y);
	pentagonPoints[4].SetPoint(P1.x, P1.y);

	CBrush brush(color);
	CBrush *oldBrush = dc->SelectObject(&brush);

	dc->Polygon(pentagonPoints, 5);
}