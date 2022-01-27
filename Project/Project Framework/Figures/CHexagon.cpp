#include "CHexagon.h"

#include <iostream>
#include <fstream>

CHexagon::CHexagon(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	ID = ++hexagonId;
	center = P1;
	firstpoint = P2;
}
int CHexagon::hexagonId = 0;

CHexagon::CHexagon() {}

void CHexagon::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Hexagon on the screen	
	pGUI->DrawHexagon(center, firstpoint, FigGfxInfo, Selected);

}

bool CHexagon::PointOnFig(int x, int y) const {
	int radius = sqrt(pow(center.x - firstpoint.x, 2) + pow(center.y - firstpoint.y, 2));
	int length = sqrt(pow(center.x - x, 2) + pow(center.y - y, 2));
	return length <= radius;
}

void CHexagon::PrintInfo(GUI* pOut) const {
	string x1 = to_string(center.x);
	string y1 = to_string(center.y);
	string x2 = to_string(firstpoint.x);
	string y2 = to_string(firstpoint.y);
	string c1 = this->getcolor(this->FigGfxInfo.DrawClr);
	string c2 = this->getcolor(this->FigGfxInfo.FillClr);
	string allInfo = (" TopLeftCorner: (" + x1 + ", " + y1 + ")" + " firstpoint: (" + x2 + ", " + y2 + ")" + " drawcolor:(" + c1 + ")" + " fillcolor:(" + c2 + ")");

	pOut->PrintMessage(allInfo);

}

void CHexagon::Save(ofstream& OutFile) {

	OutFile << "CHexagon\t" << this->ID << "\t" << this->center.x << "\t" << this->center.y << "\t" << this->firstpoint.x << "\t" << this->firstpoint.y << "\t"
		<< this->getcolor(this->FigGfxInfo.DrawClr) << "\t";
	if (this->FigGfxInfo.isFilled)
		OutFile << this->getcolor(this->FigGfxInfo.FillClr) << "\n";
	else
		OutFile << "NON-FILLED\n";
}

void CHexagon::Load(ifstream& Infile) {

	string s;
	Infile >> ID >> center.x >> center.y >> firstpoint.x >> firstpoint.y;

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