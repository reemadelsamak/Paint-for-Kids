#ifndef CSQUARE_H
#define CSQUARE_H

#include "CFigure.h"

class CSquare : public CFigure
{
private:
	Point TopLeftCorner;	
	int length;
public:
	CSquare(Point , int, GfxInfo FigureGfxInfo );
	CSquare();
	virtual void DrawMe(GUI* pOut) const;
	virtual bool PointOnFig(int, int) const;
	virtual void PrintInfo(GUI* pOut) const;
	void CSquare::Save(ofstream& OutFile);
	void CSquare::Load(ifstream& Infile);
};

#endif