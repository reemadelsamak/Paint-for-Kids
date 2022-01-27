#include "ActionSave.h"
#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"
#include <iostream>
#include <fstream>

ActionSave::ActionSave(ApplicationManager* pApp, int FigCount) : Action(pApp)
{
	FileName = "TEST";
	FigCnt = FigCount;    //We need the figure number to write it on the file
}

void ActionSave::ReadActionParameters()
{
	//Output* pOut = pManager->GetOutput();   //Pointer to Output
	//Input* pIn = pManager->GetInput();      //Pointer to Input

	GUI* pGUI = pManager->GetGUI();
	pGUI->ClearStatusBar();
	pGUI->PrintMessage("Please write the file name then press ENTER");
	FileName = pGUI->GetSrting();  //read the file name
}

void ActionSave::Execute()
{
	ReadActionParameters();     //get the parameters
	GUI* pGUI = pManager->GetGUI();

	ofstream OutFile;   //object of ofstream to write on the disk
	OutFile.open(FileName + ".txt");  // create a file with FileName and .txt exetention
	bool flag = false;
	if (OutFile.fail()) //Check the FileName and loop till be Valid name
		flag = true;
	while (flag)
	{
		pGUI->ClearStatusBar();
		pGUI->PrintMessage("Please write a valid name then press ENTER");
		FileName = pGUI->GetSrting();
		OutFile.open(FileName + ".txt");
		if (OutFile.good())
			flag = false;
	}
	OutFile << colorString(UI.DrawColor) << "\t" << colorString(UI.FillColor) << "\t" << colorString(UI.BkGrndColor) << "\n";  //Write the Current Draw Color 
	OutFile << FigCnt << "\n";  //and Current Fill Color and in the second line write the number of figures 
	pManager->Saveall(OutFile);  //Now Start Saving each figure proccess 
	OutFile.close();
	pGUI->PrintMessage("Saved !");

}

string ActionSave::colorString(color c)  //Convert from Color Type to String Type
{
	if (c == BLACK) return "BLACK";
	else if (c == WHITE) return "WHITE";
	else if (c == BLUE) return "BLUE";
	else if (c == RED) return "RED";
	else if (c == YELLOW) return "YELLOW";
	else if (c == GREEN) return "GREEN";
	else if (c == LIGHTGOLDENRODYELLOW) return "LIGHTGOLDENRODYELLOW";
	else if (c == MAGENTA) return "MAGENTA";
	else if (c == TURQUOISE) return "TURQUOISE";
	else
		return "COLOR";
}
