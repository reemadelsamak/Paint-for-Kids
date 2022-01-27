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
<<<<<<< HEAD
	CSquare(Point P1, Point P2, GfxInfo FigureGfxInfo) ;
	int getInfo() const;
	virtual void DrawMe(GUI* pOut) const;
	virtual bool PointOnFig(int, int) const;
	virtual void PrintInfo(GUI* pOut) const;
	virtual void Resize(float aa);
	virtual float getsize();




=======
	CSquare();
	virtual void DrawMe(GUI* pOut) const;
	virtual bool PointOnFig(int, int) const;
	virtual void PrintInfo(GUI* pOut) const;
	void CSquare::Save(ofstream& OutFile);
	void CSquare::Load(ifstream& Infile);
>>>>>>> 94a402085a606c7da51d6c5b7dfe0e32ec55dbee
};

#endif