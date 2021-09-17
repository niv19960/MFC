#pragma once
#include "stdafx.h"
class Figure: public CObject {
	
	DECLARE_SERIAL(Figure)   

	CPoint P1, P2;
	COLORREF  fbgcolor, bg; //colors
	
public:
	
	Figure() {}
	Figure(CPoint p1, CPoint p2, COLORREF color) :
		P1(p1), P2(p2), bg(color) // color
	{}
	
	void Serialize(CArchive& ar); //the process of writing or reading an object to or from a persistent storage medium such as a disk file

	virtual void Draw(CDC *dc, const COLORREF &color) const
	{
		CBrush brush(color);
		CBrush *oldBrush = dc->SelectObject(&brush);
		dc->Rectangle(P1.x, P1.y, P2.x, P2.y);
	}
	
	CPoint getP1() const 
	{ 
		return P1;
	}
	CPoint getP2() const
	{
		return P2;
	}
	
	virtual void Redefine(CPoint p1, CPoint p2) { P1 = p1; P2 = p2; }
	virtual bool isInside(const CPoint &P) const;
	virtual void Shift(int dx, int dy);
	COLORREF getColor()
	{
		return bg;
	}
	void setColor(COLORREF c)
	{
		bg = c;
	}

	void setStart(int x, int y) {P1.x = x; P1.y = y; }
	void setEnd(int x, int y) { P2.x = x; P2.y = y; }
};
