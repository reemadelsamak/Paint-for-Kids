
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include <iostream>
#include "ActionPlayMode.h"
#include "../Figures/CFigure.h"

//#include "ActionSelectFigure.h"

ActionPlayMode::ActionPlayMode(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionPlayMode::Execute()
{
	
	GUI* pGUI = pManager->GetGUI();
	pGUI->CreatePlayToolBar();



	
}
