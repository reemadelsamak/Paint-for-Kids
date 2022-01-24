#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

//Sets the figure ID
void CFigure::SetID(int id)
{ID = id;}

//Gets the figure ID
int CFigure::GetID() const
{return ID;}


string CFigure::getcolor(color c) const  //Convert from String Type to Color Type
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
	return "NO_COLOR";
}


color CFigure::getcolor(string s) const  //Convert from Color Type to String Type
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