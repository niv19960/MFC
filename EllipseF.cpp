#include "stdafx.h"
#include "EllipseF.h"

IMPLEMENT_SERIAL(EllipseF, CObject, 1)

EllipseF::EllipseF(CPoint p1, CPoint p2, COLORREF color)
	:Figure(p1, p2, color)
{}

void EllipseF::Draw(CDC* dc, const COLORREF &color) const
{
	CPoint p1 = getP1();
	CPoint p2 = getP2();
	CBrush brush(color);
	CBrush *oldBrush = dc->SelectObject(&brush);
	dc->Ellipse(P1.x, P1.y, P2.x, P2.y);
}

