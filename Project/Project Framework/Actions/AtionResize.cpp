#include "AtionResize.h"

#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include <iostream>
#include "ActionSelectFigure.h"

#include "../Figures/CFigure.h"
#include "../Figures/CSquare.h"

//#include "ActionSelectFigure.h"

AtionResize::AtionResize(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void AtionResize::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	scale = 1;
	// Show Colors Palette
	pGUI->CreateColorToolBar();

	// Which Color
	pGUI->GetPointClicked(P.x, P.y);

	//get selected figures & thier numbers
	SelectedFigs = pManager->GetSelectedFigures();
	selectedCount = pManager->GetSelectedCount();

	//Check if any figures are selected
	if (SelectedFigs[0] == NULL)
		IsSelectedFig = false;
	else
		IsSelectedFig = true;

	pGUI->ClearStatusBar();

	if (P.y > UI.ToolBarHeight && P.y < UI.ToolBarHeight + UI.ToolBarHeight) {
		//Color Cases
		int ClickedItemOrder = (P.x / UI.MenuItemWidth);
		switch (ClickedItemOrder)
		{
		case ITM_GREEN1:
			scale = 0.25;
			break;

		case ITM_BLUE1:
			scale = 0.5;
			break;

		case ITM_RED1:
			
			scale = 2;
			break;

		case ITM_YELLOW1:

			scale = 4;
			break;

	
		}

		//Change Colors
		if (!IsSelectedFig) {
			//No figures selected so >> change default draw colr
			pGUI->ClearStatusBar();
			pGUI->PrintMessage("Choose Current Draw Color");
			
		}

		else {
			//figures selected so >> loop on selected figures and change draw color
			pGUI->ClearStatusBar();
			pGUI->PrintMessage("Choose Draw Color for Selected Figures");
			for (int i = 0; i < selectedCount; i++) {
				
				SelectedFigs[i]->Resize(scale);
			}
		}
	}

	pGUI->ClearColorsToolBar();

}


AtionResize::~AtionResize(void)
{}
