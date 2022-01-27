#




#ifndef ACTION_RESIZE_H
#define ACTION_RESIZE_H
#include "Action.h"
#include "../Figures/CFigure.h"

#include "../Figures/CSquare.h"
class AtionResize : public Action
{
private:
	Point P;
	CFigure* SelectedFig;
	int DeletedID; //ID of the deleted figure (for use in RemoveFig())
	int selectedCount; //Number of selected figures
	CFigure* const* SelectedFigs; //Pointer to the selected figures
	bool IsSelectedFig;		//if a figure is selected
	
	float scale;

public:
	AtionResize(ApplicationManager* pApp);

	virtual void Execute();
	void Unselect();
	~AtionResize(void);


};

#endif
