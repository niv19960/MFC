#include "stdafx.h"
#include "LineF.h"

IMPLEMENT_SERIAL(LineF, CObject, 1)

LineF::LineF(CPoint p1, CPoint p2, COLORREF color)
	:Figure(p1, p2, color)
{}

void LineF::Draw(CDC* dc, const COLORREF &color) const
{
	CPoint p1 = getP1();
	CPoint p2 = getP2();
	CBrush brush(color); // color	CBrush *oldBrush = dc->SelectObject(&brush);// color
	dc->MoveTo(P1);
	dc->LineTo(P2);
}
