#ifndef ACTION_SELECT_FIGURE_H
#define ACTION_SELECT_FIGURE_H

#include "Action.h"
#include "../Figures/CFigure.h"

class ActionSelectFigure : public Action {
private:
	Point P;
	CFigure* SelectedFig;

public:
	ActionSelectFigure(ApplicationManager* pApp);

	//Executes the select action
	virtual void Execute();
	void Select();
	void Unselect();
};

#endif