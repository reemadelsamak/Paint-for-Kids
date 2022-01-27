#include "CElipse.h"

#include <iostream>
#include<fstream>


CElipse::CElipse(Point P1, Point p2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	ID = ++celipseId;
	TopLeftCorner = P1;
	RightBottomCorner = p2;
}
int CElipse::celipseId = 0;

CElipse::CElipse() {}


void CElipse::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawElipse(TopLeftCorner, RightBottomCorner, FigGfxInfo, Selected);


}
bool CElipse::PointOnFig(int x, int y) const {
	/*int a, h, k, b;
	a = abs(TopLeftCorner.x - RightBottomCorner.x)/2;
	b = abs(TopLeftCorner.y - RightBottomCorner.y)/2;
	h = abs(a + TopLeftCorner.x);
	k = abs(b + TopLeftCorner.y);
	int p = (pow((x - h), 2) / pow(a, 2)) + (pow((y - k), 2) / pow(b, 2));

	return p <= 1;*/
	return false;
}

void CElipse::PrintInfo(GUI* pOut) const {
	string x1 = to_string(TopLeftCorner.x);
	string y1 = to_string(TopLeftCorner.y);
	string x2 = to_string(RightBottomCorner.x);
	string y2 = to_string(RightBottomCorner.y);
	string c1 = this->getcolor(this->FigGfxInfo.DrawClr);
	string c2 = this->getcolor(this->FigGfxInfo.FillClr);
	string allInfo = (" TopLeftCorner: (" + x1 + ", " + y1 + ")" + " RightBottomCorner: (" + x1 + ", " + y1 + ")" + " drawcolor:(" + c1 + ")" + " fillcolor:(" + c2 + ")");

	pOut->PrintMessage(allInfo);

}

void CElipse::Save(ofstream& OutFile) {

	OutFile << "CElipse\t" << this->ID << "\t" << this->TopLeftCorner.x << "\t" << this->TopLeftCorner.y << "\t" << this->RightBottomCorner.x << "\t"
		<< this->RightBottomCorner.y << "\t" << this->getcolor(this->FigGfxInfo.DrawClr) << "\t";
	if (this->FigGfxInfo.isFilled)
		OutFile << this->getcolor(this->FigGfxInfo.FillClr) << "\n";
	else
		OutFile << "NON-FILLED\n";
}

void CElipse::Load(ifstream& Infile) {

	string s;
	Infile >> ID >> TopLeftCorner.x >> TopLeftCorner.y >> RightBottomCorner.x >> RightBottomCorner.y;

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