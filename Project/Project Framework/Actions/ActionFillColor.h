#ifndef ACTION_FILL_COLOR_H
#define ACTION_FILL_COLOR_H

#include "Action.h"

class ActionFillColors :public Action
{
private:
	Point P;
	color fillClr;
	int selectedCount;				//number of selected figures
	CFigure* const* SelectedFigs;	//pointer to selected figures
	bool IsSelectedFig;				//if a figure is selected

public:
	ActionFillColors(ApplicationManager* pApp);

	virtual void Execute();

	~ActionFillColors(void);
};

#endif
