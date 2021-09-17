#include "StdAfx.h"
#include "SquareF.h"

IMPLEMENT_SERIAL(SquareF, CObject, 1)

SquareF::SquareF() {}
SquareF::SquareF(CPoint p1, CPoint p2, COLORREF color)
	:Figure(p1, p2, color){}
SquareF::~SquareF() {}

void SquareF ::Draw(CDC *dc, const COLORREF &color) const
{
	CPoint point(P1.x + (P1.y - P2.y), P1.y - (P1.x - P2.x)), point2(P2.x + (P1.y - P2.y), P2.y - (P1.x - P2.x));
	CPoint angle[] = { point,P1,P2,point2 };
	CBrush brush(color);
	CBrush *oldBrush = dc->SelectObject(&brush);
	dc->Rectangle(P1.x, P1.y, P2.x, P2.y);
	//dc->Polygon(angle, 4); // possible instead of Redefine
}

void SquareF::Redefine(CPoint start, CPoint end)
{
	int max = max(abs(start.x - end.x), abs(start.y - end.y));

	if (start.x < end.x && start.y < end.y)
	{
		setEnd(start.x + max, start.y + max);
	}
	else if (start.x > end.x && start.y > end.y)
	{
		setEnd(start.x - max, start.y - max);
	}
	else if (start.x < end.x && start.y > end.y)
	{
		setEnd(start.x + max, start.y - max);
	}
	else if (start.x > end.x && start.y < end.y)
	{
		setEnd(start.x - max, start.y + max);
	}
}

