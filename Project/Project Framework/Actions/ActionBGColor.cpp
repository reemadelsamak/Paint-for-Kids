#include "ActionBGColor.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"

ActionBGColor::ActionBGColor(ApplicationManager* pApp) :Action(pApp)
{}

void ActionBGColor::Execute()
{

	GUI* pGUI = pManager->GetGUI();
	// Show Colors Palette
	pGUI->CreateColorToolBar();

	// Change Status Message 
	pGUI->PrintMessage("Choose Background Color");
	// Which Color
	pGUI->GetPointClicked(P.x, P.y);

	if (P.y > UI.ToolBarHeight && P.y < UI.ToolBarHeight + UI.ToolBarHeight) {
		//Color Cases
		int ClickedItemOrder = (P.x / UI.MenuItemWidth);
		switch (ClickedItemOrder)
		{
		case ITM_GREEN:
			pGUI->ChangeBGColor(GREEN);
			break;

		case ITM_BLUE:
			pGUI->ChangeBGColor(BLUE);
			break;

		case ITM_RED:
			pGUI->ChangeBGColor(RED);
			break;

		case ITM_YELLOW:
			pGUI->ChangeBGColor(YELLOW);
			break;

		case ITM_NOFILL:
			pGUI->ChangeBGColor(LIGHTGOLDENRODYELLOW);
			break;

		default:			//click on empty place in color toolbar
			pGUI->ChangeBGColor(UI.BkGrndColor);
			break;
		}
	}
	pGUI->ClearColorsToolBar();
}

ActionBGColor::~ActionBGColor(void)
{}


