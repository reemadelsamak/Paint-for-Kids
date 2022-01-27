#ifndef CELIPSE_H
#define CELIPSE_H

#include "CFigure.h"

class CElipse : public CFigure
{
private:
	Point TopLeftCorner, RightBottomCorner;
public:
	static int celipseId;
	CElipse(Point, Point, GfxInfo FigureGfxInfo);
	CElipse();
	bool CElipse::PointOnFig(int x, int y) const;
	void CElipse::PrintInfo(GUI* pOut) const;
	virtual void DrawMe(GUI* pOut) const;
	void CElipse::Save(ofstream& OutFile);
	void CElipse::Load(ifstream& Infile);
};

#endif