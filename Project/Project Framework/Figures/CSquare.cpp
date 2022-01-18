#include "CSquare.h"

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


void CSquare::PrintInfo(GUI* pOut) const{
	//Print Selected Square Info
	string message = "ID: " + to_string(GetID()) +
		", Top-Left: " + to_string(TopLeftCorner.x) + "," + to_string(TopLeftCorner.y) +
		", Length: " + to_string(length) +
		", Area: " + to_string(length * length);
	pOut->PrintMessage(message);
}