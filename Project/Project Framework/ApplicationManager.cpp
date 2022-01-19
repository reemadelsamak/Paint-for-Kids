#include "ApplicationManager.h"
#include "Actions\ActionAddSquare.h"
#include "Actions\ActionDrawColor.h"
#include "Actions\ActionFillColors.h"
#include "Actions\ActionBGColor.h"
#include "Actions\ActionSelectFigure.h"
#include "Actions\ActionPlayMode.h"
#include "Actions\ActionDrawMode.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pGUI = new GUI;	
	
	FigCount = 0;
	clipboardCount = 0;

	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++) {
		FigList[i] = NULL;
		SelectedFigs[i] = NULL;
		Clipboard[i] = NULL;
	}
	selectedCount = 0;

}

void ApplicationManager::Run()
{
	ActionType ActType;
	do
	{		
		//1- Read user action
		ActType = pGUI->MapInputToActionType();

		//2- Create the corresponding Action
		Action *pAct = CreateAction(ActType);
		
		//3- Execute the action
		ExecuteAction(pAct);

		//4- Update the interface
		UpdateInterface();	

	}while(ActType != EXIT);
	
}


//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
//Creates an action
Action* ApplicationManager::CreateAction(ActionType ActType) 
{
	Action* newAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_SQUARE:
			newAct = new ActionAddSquare(this);
			break;

		case DRAW_ELPS:
			///create AddLineAction here

			break;

		case CHNG_DRAW_CLR:
			pGUI->CreateColorToolBar();
			newAct = new ActionDrawColor(this);
			break;

		case CHNG_FILL_CLR:
			pGUI->CreateColorToolBar();
			newAct = new ActionFillColors(this);
			break;

		case CHNG_BK_CLR:
			pGUI->CreateColorToolBar();
			newAct = new ActionBGColor(this);
			break;
		case TO_PLAY:
			newAct = new ActionPlayMode(this);
			break;
		case TO_DRAW:
			newAct = new ActionDrawMode(this);
			break;

		case SELECT_FIGURE:
			newAct = new ActionSelectFigure(this);
			break;

		case EXIT:
			///create ExitAction here
			
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return NULL;
			break;
	}	
	return newAct;
}
//////////////////////////////////////////////////////////////////////
//Executes the created Action
void ApplicationManager::ExecuteAction(Action* &pAct) 
{	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount) {
		//FigList[FigCount++] = pFig;
		FigList[FigCount] = pFig;
		FigList[FigCount]->SetID(FigCount);
		FigCount++;

	}
}
////////////////////////////////////////////////////////////////////////////////////
//get number of figures 
int ApplicationManager::getFigCount() const
{
	return FigCount;
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	//Add your code here to search for a figure given a point x,y	

	for (int i = FigCount - 1; i >= 0; i--) {
			if (FigList[i]->PointOnFig(x, y))
				return FigList[i];
	}
	return NULL;
}


//==================================================================================//
//							Select Functions										//
//==================================================================================//

//Returns the number of selected figures
int ApplicationManager::GetSelectedCount() const {
	return selectedCount;
}
////////////////////////////////////////////////////////////////////////////////////
//Returns a pointer to SelectedFigs array
CFigure* const* ApplicationManager::GetSelectedFigures() const {
	return SelectedFigs;
}
///////////////////////////////////////////////////////////////////////////////////
//Adds a figure to the SelectedFigs array
void ApplicationManager::AddSelectedFigure(CFigure* sf) {

	SelectedFigs[selectedCount] = sf;
	selectedCount++;
}
////////////////////////////////////////////////////////////////////////////////////
//Removes a figure from the SelectedFigs array
void ApplicationManager::RemoveSelectedFigure(CFigure* sf) {

	for (int i = 0; i < selectedCount; i++) {
		if (SelectedFigs[i] == sf) {
			SelectedFigs[i] = SelectedFigs[selectedCount - 1];
			SelectedFigs[selectedCount - 1] = NULL;
			selectedCount--;
			return;
		}
	}
}

void ApplicationManager::ClearSelectedFigs() {
	for (int i = 0; i < selectedCount; i++)
	{
		SelectedFigs[i] = NULL;
	}
	selectedCount = 0;
}

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
		FigList[i]->DrawMe(pGUI);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the interface
GUI *ApplicationManager::GetGUI() const
{	return pGUI; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pGUI;
	
}
