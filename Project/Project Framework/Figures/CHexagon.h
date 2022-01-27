
#ifndef CHEXAGON_H
#define CHEXAGON_H

#include "CFigure.h"

class CHexagon : public CFigure
{
private:
	Point center;
	Point firstpoint;
public:
	static int hexagonId;
	CHexagon(Point, Point, GfxInfo FigureGfxInfo);
	CHexagon();
	virtual void DrawMe(GUI* pOut) const;
	bool CHexagon::PointOnFig(int x, int y) const;
	void CHexagon::PrintInfo(GUI* pOut) const;
	void CHexagon::Save(ofstream& OutFile);
	void CHexagon::Load(ifstream& Infile);
};

#endif