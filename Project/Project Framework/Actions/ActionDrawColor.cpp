#include "ActionDrawColor.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"

ActionDrawColor::ActionDrawColor(ApplicationManager* pApp) :Action(pApp)
{}

void ActionDrawColor::Execute()
{
	GUI* pGUI = pManager->GetGUI();

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
		case ITM_GREEN:
			drawClr = GREEN;
			break;

		case ITM_BLUE:
			drawClr = BLUE;
			break;

		case ITM_RED:
			drawClr = RED;
			break;

		case ITM_YELLOW:
			drawClr = YELLOW;
			break;

		case ITM_NOFILL:
			drawClr = BLACK;
			break;

		default:	//click on empty place in color toolbar
			drawClr = pGUI->getCrntDrawColor();;
			break;
		}

		//Change Colors
		if (!IsSelectedFig) {
			//No figures selected so >> change default draw colr
			pGUI->ClearStatusBar();
			pGUI->PrintMessage("Choose Current Draw Color");
			pGUI->setCrntDrawColor(drawClr);
		}

		else {
			//figures selected so >> loop on selected figures and change draw color
			pGUI->ClearStatusBar();
			pGUI->PrintMessage("Choose Draw Color for Selected Figures");
			for (int i = 0; i < selectedCount; i++)
				SelectedFigs[i]->ChngDrawClr(drawClr);
		}
	}

	pGUI->ClearColorsToolBar();
}

ActionDrawColor::~ActionDrawColor(void)
{}


