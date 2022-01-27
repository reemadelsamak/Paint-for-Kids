#include "ActionAddElipse.h"
#include "..\Figures\CElipse.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

ActionAddElipse::ActionAddElipse(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionAddElipse::Execute()
{
	Point P1, P2;

	GUI* pGUI = pManager->GetGUI();


	GfxInfo SqrGfxInfo;
	SqrGfxInfo.isFilled = false;
	SqrGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	SqrGfxInfo.FillClr = pGUI->getCrntFillColor();
	SqrGfxInfo.BorderWdth = pGUI->getCrntPenWidth();



	pGUI->PrintMessage("New elipse: Click at first point");
	//Read 1st point and store in point P1
	pGUI->GetPointClicked(P1.x, P1.y);

	pGUI->PrintMessage("New elipse: Click at second point");
	//Read 2nd point and store in point P2
	pGUI->GetPointClicked(P2.x, P2.y);

	pGUI->ClearStatusBar();



	Point topLeft;
	Point bottomRight;
	topLeft.x = P1.x;
	topLeft.y = P1.y;
	bottomRight.x = P2.x;
	bottomRight.y = P2.y;


	CElipse* R = new CElipse(topLeft, bottomRight, SqrGfxInfo);


	pManager->AddFigure(R);
}
