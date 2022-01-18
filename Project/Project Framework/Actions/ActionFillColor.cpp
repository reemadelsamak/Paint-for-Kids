#include "ActionFillColors.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include <iostream>
#include "../Figures/CFigure.h"

ActionFillColors::ActionFillColors(ApplicationManager* pApp) :Action(pApp)
{}

void ActionFillColors::Execute()
{
	GUI* pGUI = pManager->GetGUI();

	// Show Colors Palette
	pGUI->CreateColorToolBar();

	// Which Color is clicked
	pGUI->GetPointClicked(P.x, P.y);
	pGUI->setIsFilled(true);
	pGUI->getIsFilled();


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
		int ClickedItemOrder = (P.x / UI.MenuItemWidth);
		//colors cases
		if (ClickedItemOrder == ITM_NOFILL) {
			pGUI->setIsFilled(false);
		}
		else
		{
			pGUI->setIsFilled(true);
			switch (ClickedItemOrder)
			{
			case ITM_GREEN:
				fillClr = GREEN;
				break;

			case ITM_BLUE:
				fillClr = BLUE;
				break;

			case ITM_RED:
				fillClr = RED;
				break;

			case ITM_YELLOW:
				fillClr = YELLOW;
				break;

			default:	//click on empty place in color toolbar
				fillClr = pGUI->getCrntFillColor();
				break;
			}
		}
		//Change Colors
		if (!IsSelectedFig)
		{
			//No figures selected so >> change default fill colr
			pGUI->PrintMessage("Choose Current Fill Color");
			pGUI->setCrntFillColor(fillClr);
		}
		else
		{
			//figures selected so >> loop on selected figures and change fill color
			pGUI->PrintMessage("Choose Fill Color for Selected Figures");
			for (int i = 0; i < selectedCount; i++)
				SelectedFigs[i]->ChngFillClr(fillClr);
		}
	}

	pGUI->ClearStatusBar();
	pGUI->ClearColorsToolBar();
}

ActionFillColors::~ActionFillColors(void)
{}
