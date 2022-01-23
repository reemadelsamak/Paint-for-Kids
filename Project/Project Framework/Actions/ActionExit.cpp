#include "ActionExit.h"
#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"
#include "String.h"

ActionExit::ActionExit(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionExit::Execute() {

	GUI* pGUI = pManager->GetGUI();

	pGUI->PrintMessage("Do you want to save before exit? y or n");
	string answer;
	answer = pGUI->GetSrting();
	if (answer == "Y" || answer == "y") {
		Action* pAct = pManager->CreateAction(SAVE);
		pManager->ExecuteAction(pAct);
		pGUI->PrintMessage("your graph saved successfuly bye bye");
		Sleep(2000);
		exit(0);
	}

}
