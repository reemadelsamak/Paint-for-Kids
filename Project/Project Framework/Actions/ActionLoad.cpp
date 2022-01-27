#include "ActionLoad.h"
#include "..\ApplicationManager.h"
#include"..\Figures\CSquare.h"
#include"..\Figures\CElipse.h"
#include"..\Figures\CHexagon.h"
#include "..\GUI\GUI.h"

#include <fstream>
#include "String.h"

ActionLoad::ActionLoad(ApplicationManager* pApp, int FigCount) : Action(pApp)
{
	FileName = "TEST";
	FigCnt = FigCount;    //We need the figure number to write it on the file
}

void ActionLoad::ReadActionParameters()
{

	GUI* pGUI = pManager->GetGUI();
	pGUI->ClearStatusBar();
	pGUI->PrintMessage("Please write the file name to load from then press ENTER");
	FileName = pGUI->GetSrting();  //read the file name
}

void ActionLoad::Execute()
{
	ReadActionParameters();     //get the parameters
	GUI* pGUI = pManager->GetGUI();

	ifstream InputFile;   //object of ofstream to write on the disk
	InputFile.open(FileName + ".txt");  // create a file with FileName and .txt exetention
	pGUI->ClearDrawArea();
	bool flag = false;
	if (InputFile.fail()) //Check the FileName and loop till be Valid name
		flag = true;
	while (flag)
	{
		pGUI->ClearStatusBar();
		pGUI->PrintMessage("Please write a valid name then press ENTER");
		FileName = pGUI->GetSrting();
		InputFile.open(FileName + ".txt");
		if (InputFile.good())
			flag = false;
	}

	if (InputFile.is_open())
	{
		//read from the file the current draw clr & fill clr &number of figuers 
		CFigure* pFig = NULL;
		int numberOfFiguers;
		string DrawClr, FillClr, BgClr;
		InputFile >> DrawClr;
		UI.DrawColor = getColorObject(DrawClr);
		InputFile >> FillClr;
		UI.FillColor = getColorObject(FillClr);
		InputFile >> BgClr;
		UI.BkGrndColor = getColorObject(BgClr);
		InputFile >> numberOfFiguers;
		//cleaning the figlist before loading the file
		pManager->ClearFigList();
		// Loop all figures ,identify the type ,then create an obj of the specified type,add to the figlist  after the loading it
		for (int i = 0; i < numberOfFiguers; i++)
		{
			string shapeType;
			InputFile >> shapeType;
			if (shapeType == "CSquare") {
				pFig = new CSquare;
			}
			else if (shapeType == "CElipse") {
				pFig = new CElipse;
			}
			else if (shapeType == "CHexagon") {
				pFig = new CHexagon;
			}

			//loading the parameters of each figure 
			pFig->Load(InputFile);
			if (pFig != NULL)
			{
				//seneding it to the application manager to add them
				pManager->AddFigure(pFig);
			}
		}

		pManager->UpdateInterface();     //Draw the figure list
		pGUI->PrintMessage("Graph Loaded Successfully");
		pGUI->ClearStatusBar();
		pGUI->CreateStatusBar();
		InputFile.close();
		//close the file after looping 

	}

}

color ActionLoad::getColorObject(string s) const  //Convert from Color Type to String Type
{
	if (s == "BLACK") return BLACK;
	else if (s == "WHITE") return WHITE;
	else if (s == "BLUE") return BLUE;
	else if (s == "RED") return RED;
	else if (s == "YELLOW") return YELLOW;
	else if (s == "GREEN") return GREEN;
	else if (s == "LIGHTGOLDENRODYELLOW") return LIGHTGOLDENRODYELLOW;
	else if (s == "MAGENTA") return MAGENTA;
	else if (s == "TURQUOISE") return TURQUOISE;
	return LIGHTGOLDENRODYELLOW;
}
