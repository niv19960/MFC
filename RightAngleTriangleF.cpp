#include "StdAfx.h"
#include "RightAngleTriangleF.h"

IMPLEMENT_SERIAL(RightAngleTriangleF, CObject, 1)

RightAngleTriangleF::RightAngleTriangleF() {}
RightAngleTriangleF::RightAngleTriangleF(CPoint p1, CPoint p2, COLORREF color) : TriangleF(p1, p2, color) {}
RightAngleTriangleF::~RightAngleTriangleF() {}


void RightAngleTriangleF::Draw(CDC *dc, const COLORREF &color)const
{
	CPoint point(P1.x, P2.y);
	CPoint angle[] = { P1, P2, point };

	TriangleF::InnerDraw(angle, color, dc);

}

