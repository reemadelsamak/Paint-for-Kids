#include "ActionDelete.h"

#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include <iostream>
#include "ActionSelectFigure.h"

#include "../Figures/CFigure.h"

//#include "ActionSelectFigure.h"

ActionDelete::ActionDelete(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionDelete::Execute()
{

	GUI* pGUI = pManager->GetGUI();
	cout << "action delete";


	//get the figure selected
	//SelectedFig = pManager->GetFigure(P.x, P.y);

	//NULL if no figure is clicked
	pGUI->GetPointClicked(P.x, P.y);
	SelectedFigs = pManager->GetSelectedFigures();
	selectedCount = pManager->GetSelectedCount();

	if (SelectedFigs[0] == NULL)
		IsSelectedFig = false;
	else
		IsSelectedFig = true;



		if (!IsSelectedFig)
		{
			//No figures selected so >> change default fill colr
			pGUI->PrintMessage("Choose Current figure to delete");

		}
		else
		{
			//figures selected so >> loop on selected figures and change fill color

			for (int i = 0; i < selectedCount; i++) {
				//Gets the deleted figure ID
				DeletedID = SelectedFigs[i]->GetID();
				cout << "dddddddddddddddddddddddddddddddddddddddd";
				cout << DeletedID;


				//Remove the figure from the FigList by ID
				pManager->RemoveFig(DeletedID);

				//Delete the selected figure
				delete SelectedFigs[i];
			}

			pManager->ClearSelectedFigs();
			pGUI->ClearColorsToolBar();

			pGUI->PrintMessage("Figure(s) Deleted");
		}



	



}
ActionDelete::~ActionDelete(void)
{}
