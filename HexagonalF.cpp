#include "StdAfx.h"
#include "HexagonalF.h"

IMPLEMENT_SERIAL(HexagonalF, CObject, 1)

HexagonalF::HexagonalF() {}
HexagonalF::HexagonalF(CPoint p1, CPoint p2, COLORREF color) :Figure(p1, p2, color)
{}
HexagonalF::~HexagonalF() {}

void HexagonalF::Draw(CDC *dc, const COLORREF &color) const
{
	CPoint hexagonalPoints[6];
	hexagonalPoints[0].SetPoint(P1.x, P2.y);
	hexagonalPoints[1].SetPoint(P2.x, P2.y);
	hexagonalPoints[2].SetPoint(P2.x + (P2.x - P1.x), (P2.y + P1.y)*0.5);
	hexagonalPoints[3].SetPoint(P2.x, P1.y);
	hexagonalPoints[4].SetPoint(P1.x, P1.y);
	hexagonalPoints[5].SetPoint(P1.x - (P2.x - P1.x), (P2.y + P1.y)*0.5);
	CBrush brush(color);
	CBrush *oldBrush = dc->SelectObject(&brush);
	dc->Polygon(hexagonalPoints, 6);
}