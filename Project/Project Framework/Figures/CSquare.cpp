#include "CSquare.h"

#include <iostream>
#include <fstream>


CSquare::CSquare() {}
CSquare::CSquare(Point P1, int len, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	TopLeftCorner = P1;
	length = len;
}
	

void CSquare::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawSquare(TopLeftCorner, length, FigGfxInfo, Selected);
	
}

//If x,y Point on the Square
bool CSquare::PointOnFig(int x, int y) const {

	bool isOnFig=((x >= TopLeftCorner.x && x <= TopLeftCorner.x + length) || (x <= TopLeftCorner.x && x >= TopLeftCorner.x + length))
		&& ((y >= TopLeftCorner.y && y <= TopLeftCorner.y + length) || (y <= TopLeftCorner.y && y >= TopLeftCorner.y + length));
	return isOnFig;
}


void CSquare::PrintInfo(GUI* pOut) const {
	string x1 = to_string(TopLeftCorner.x);
	string y1 = to_string(TopLeftCorner.y);
	string x2 = to_string(length);
	string c1 = this->getcolor(this->FigGfxInfo.DrawClr);
	string c2 = this->getcolor(this->FigGfxInfo.FillClr);
	string allInfo = (" TopLeftCorner: (" + x1 + ", " + y1 + ")" + " length: (" + x2 + ")" + " drawcolor:(" + c1 + ")" + " fillcolor:(" + c2 + ")");

	pOut->PrintMessage(allInfo);

}

void CSquare::Save(ofstream& OutFile) {

	OutFile << "CSquare\t" << this->ID << "\t" << this->TopLeftCorner.x << "\t" << this->TopLeftCorner.y << "\t" << this->length << "\t"
		<< this->getcolor(this->FigGfxInfo.DrawClr) << "\t";
	if (this->FigGfxInfo.isFilled)
		OutFile << this->getcolor(this->FigGfxInfo.FillClr) << "\n";
	else
		OutFile << "NON-FILLED\n";
}

void CSquare::Load(ifstream& Infile) {

	string s;
	Infile >> ID >> TopLeftCorner.x >> TopLeftCorner.y >> length;

	Infile >> s;
	FigGfxInfo.DrawClr = this->getcolor(s);

	Infile >> s;
	if (s == "NON-FILLED")
		FigGfxInfo.isFilled = false;
	else
	{
		FigGfxInfo.FillClr = this->getcolor(s);
		FigGfxInfo.isFilled = true;
	}
	this->FigGfxInfo.BorderWdth = 3;
	this->SetSelected(false);

}