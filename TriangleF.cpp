#include "StdAfx.h"
#include "TriangleF.h"

IMPLEMENT_SERIAL(TriangleF, CObject, 1)

TriangleF::TriangleF() {}

TriangleF::TriangleF(CPoint p1, CPoint p2, COLORREF color)
	: Figure(p1, p2, color) {}

 TriangleF::~TriangleF() {}

void TriangleF::Draw(CDC *dc, const COLORREF &color)const
{
	CPoint TPoints[3];
	TPoints[0].SetPoint(P1.x, P2.y);
	TPoints[1].SetPoint(P2.x, P2.y);
	TPoints[2].SetPoint((P1.x + P2.x) / 2, P1.y);

	InnerDraw(TPoints, color, dc);
}

void TriangleF::InnerDraw(CPoint *TPoints, const COLORREF &color, CDC *dc)const
{
	CBrush brush(color);
	CBrush *oldBrush = dc->SelectObject(&brush);
	dc->Polygon(TPoints, 3);
}

