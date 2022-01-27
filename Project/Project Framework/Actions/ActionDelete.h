


#ifndef ACTION_DELETE_H
#define ACTION_DELETE_H
#include "Action.h"
#include "../Figures/CFigure.h"


class ActionDelete : public Action
{
private:
	Point P;
	CFigure* SelectedFig;
	int DeletedID; //ID of the deleted figure (for use in RemoveFig())
	int selectedCount; //Number of selected figures
	CFigure* const* SelectedFigs; //Pointer to the selected figures
	bool IsSelectedFig;				//if a figure is selected


public:
	ActionDelete(ApplicationManager* pApp);

	virtual void Execute();
	void Unselect();
	~ActionDelete(void);


};

#endif
