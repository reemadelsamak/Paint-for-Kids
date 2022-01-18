#include "ActionSelectFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"

ActionSelectFigure::ActionSelectFigure(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionSelectFigure::Execute()
{
	//Point P;
	GUI* pGUI = pManager->GetGUI();

	pGUI->ClearStatusBar();
	pGUI->PrintMessage("click to be selected / unselected");
	pGUI->GetPointClicked(P.x, P.y);

	//get the figure selected
	SelectedFig = pManager->GetFigure(P.x, P.y);

	//NULL if no figure is clicked
	if (SelectedFig != NULL) {
		//if figured clicked, check selected or not
		if (SelectedFig->IsSelected())
			Unselect();
		else
			Select();
	}
}

//Select a figure
void ActionSelectFigure::Select() {
	GUI* pGUI = pManager->GetGUI();

	pGUI->ClearStatusBar();
	SelectedFig->SetSelected(true);
	pManager->AddSelectedFigure(SelectedFig); //Add to SelectedFigs array
	SelectedFig->PrintInfo(pGUI); //Print Selected Figure Info
}

//Unselect a figure
void ActionSelectFigure::Unselect() {
	GUI* pGUI = pManager->GetGUI();

	SelectedFig->SetSelected(false);
	pManager->RemoveSelectedFigure(SelectedFig); //Removes from SelectedFigs array
	pGUI->ClearStatusBar();

}