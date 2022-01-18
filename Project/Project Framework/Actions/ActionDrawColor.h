#ifndef ACTION_DRAW_COLOR_H
#define ACTION_DRAW_COLOR_H

#include "Action.h"

//Add Square Action class
class ActionDrawColor : public Action
{
private:
	Point P;
	color drawClr;
	int selectedCount;				//number of selected figures
	CFigure* const* SelectedFigs;	//pointer to selected figures
	bool IsSelectedFig;				//If a figure is selected

public:
	ActionDrawColor(ApplicationManager* pApp);

	virtual void Execute();

	~ActionDrawColor(void);

};

#endif
