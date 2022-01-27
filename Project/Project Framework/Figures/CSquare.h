#ifndef CSQUARE_H
#define CSQUARE_H

#include "CFigure.h"

class CSquare : public CFigure
{
private:
	Point TopLeftCorner;	
	int length;
	
	
public:
	static int RectCnt;
	CSquare(Point , int, GfxInfo FigureGfxInfo );
	CSquare(Point P1, Point P2, GfxInfo FigureGfxInfo) ;
	int getInfo() const;
	virtual void DrawMe(GUI* pOut) const;
	virtual bool PointOnFig(int, int) const;
	virtual void PrintInfo(GUI* pOut) const;
	virtual void Resize(float aa);
	virtual float getsize();




};

#endif