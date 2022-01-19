

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"
#include <iostream>
#include "ActionDrawMode.h"
#include "../Figures/CFigure.h"

#include "ActionSelectFigure.h"



ActionDrawMode::ActionDrawMode(ApplicationManager* pApp) :Action(pApp)
{}
//Execute the action
void ActionDrawMode::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	cout << "TO DRAW MODE";

	pGUI->CreateDrawToolBar();





}