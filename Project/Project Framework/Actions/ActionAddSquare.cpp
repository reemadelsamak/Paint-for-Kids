#include "ActionAddSquare.h"
#include "..\Figures\CSquare.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

ActionAddSquare::ActionAddSquare(ApplicationManager * pApp):Action(pApp)
{}

//Execute the action
void ActionAddSquare::Execute() 
{
	Point P1,P2;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	GfxInfo SqrGfxInfo;
	SqrGfxInfo.isFilled = pGUI->getIsFilled();
	//get drawing, filling colors and pen width from the interface
	SqrGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	SqrGfxInfo.FillClr = pGUI->getCrntFillColor();
	SqrGfxInfo.BorderWdth = pGUI->getCrntPenWidth();

	
	//Step 1 - Read Square data from the user
	//if (P1.y <= 50) {

	//}
	//else {
	pGUI->PrintMessage("New Square: Click at first point");	
	//Read 1st point and store in point P1
	pGUI->GetPointClicked(P1.x, P1.y);
	

		pGUI->PrintMessage("New Square: Click at second point");
		//Read 2nd point and store in point P2
		pGUI->GetPointClicked(P2.x, P2.y);

		pGUI->ClearStatusBar();


		//Step 2 - prepare square data
		//User has entered two points P1&P2
		//2.1- Identify the Top left corner of the square
		Point topLeft;
		int z= P1.x < P2.x ? P1.x : P2.x;
		
		//topLeft.y = P1.y < P2.y ? P1.y : P2.y;
		int c= P1.y < P2.y ? P1.y : P2.y;
		if (z >= 1283) { topLeft.x = 1283- P1.x; }
		else if (z <= 1283) { topLeft.x = z; }

		if (c >= 50) { topLeft.y = c; }
		else if (c <= 50) { topLeft.y = 50; }
		//2.2- Calcuate square side legnth
		//The square side length would be the longer distance between the two points coordinates
		int SideLength = max(abs(P1.x - P2.x), abs(P1.y - P2.y));


		//Step 3 - Create a Square with the parameters read from the user
		CSquare* R = new CSquare(topLeft, SideLength, SqrGfxInfo);

		//Step 4 - Add the Square to the list of figures
		pManager->AddFigure(R);
	//}
}
