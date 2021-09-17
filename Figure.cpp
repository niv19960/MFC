#include "stdafx.h"  
#include "Figure.h"

IMPLEMENT_SERIAL(Figure, CObject, 1)

void Figure::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << P1;
		ar << P2;
		ar << bg;
		ar << fbgcolor;
	}
	else // Loading, not storing
	{
		ar >> P1;
		ar >> P2;
		ar >> bg;
		ar >> fbgcolor;
	}
}

bool Figure::isInside(const CPoint &P) const
{
	return (P1.x <= P.x && P.x <= P2.x || P1.x >= P.x && P.x >= P2.x) &&
		(P1.y <= P.y && P.y <= P2.y || P1.y >= P.y && P.y >= P2.y);
}

void Figure::Shift(int dx, int dy)
{
	P1 = P1 + CPoint(dx, dy);
	P2 = P2 + CPoint(dx, dy);
}

