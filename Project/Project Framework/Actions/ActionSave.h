#ifndef ACTION_SAVE_H
#define ACTION_SAVE_H
#include "Action.h"

class ActionSave : public Action
{
private:
	string FileName;
	int FigCnt;
public:
	ActionSave(ApplicationManager* pApp, int FigCount);
	string colorString(color c);
	virtual void ReadActionParameters();
	virtual void Execute();
	//void SavePlayMode();
};

#endif

