#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\GUI.h"
#include <fstream>

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	
	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);
	void SetSelected(bool );	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	int SetSize() const;
	virtual void DrawMe(GUI*) const  = 0 ;		//Draw the figure
	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color

	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	
	virtual bool PointOnFig(int, int) const = 0; //Checks if a given point is on the figure

	void SetID(int id);				//Sets ID to figure's index in FigList.
	int GetID() const;				//Gets the ID of the figure


	//virtual void Rotate() = 0;	//Rotate the figure
	//virtual void getdata(Point P1) const =0;	//Resize the figure
	//virtual void Move() = 0;		//Move the figure
	virtual void Resize(float aa) = 0;
	virtual float getsize() = 0;

	void setSize(float size);

	//virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	//virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	virtual void PrintInfo(GUI* pOut) const = 0;	//print all figure info on the status bar
	virtual int getInfo() const = 0;

};

#endif