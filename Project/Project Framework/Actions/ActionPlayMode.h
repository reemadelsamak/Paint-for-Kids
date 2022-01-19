#ifndef ACTION_PLAY_MODE_H
#define ACTION_PLAY_MODE_H

#include "Action.h"
#include "../Figures/CFigure.h"

//Add Square Action class
class ActionPlayMode : public Action
{
public:
	ActionPlayMode(ApplicationManager* pApp);

	//Add Square to the ApplicationManager
	virtual void Execute();

};

#endif