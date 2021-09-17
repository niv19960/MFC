#include "stdafx.h" 
#include "RectangleF.h"

IMPLEMENT_SERIAL(RectangleF, CObject, 1)

RectangleF::RectangleF(CPoint p1, CPoint p2, const COLORREF &color)
	:Figure(p1,p2, color)
{
	setColor(color);
}

