#pragma once
#include "command.h"
#include "Figure.h"

class shape_add :public Command  // for Clear, Undo and Redo
{
public:
	shape_add(CTypedPtrArray<CObArray, Figure*> &shapes, Figure *s);
	~shape_add(void);
	virtual void perform();
	virtual void rollback();
private:
	CTypedPtrArray<CObArray, Figure*> &shapes;
	Figure *s;
};

