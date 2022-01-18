#ifndef ACTION_BG_COLOR_H
#define ACTION_BG_COLOR_H
#include "Action.h"

class ActionBGColor : public Action
{
private:
	Point P;
public:
	ActionBGColor(ApplicationManager* pApp);

	virtual void Execute();

	~ActionBGColor(void);
};

#endif
