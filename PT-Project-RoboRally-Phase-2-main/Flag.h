#pragma once
#include "GameObject.h"
#include <fstream>

class Flag :public GameObject
{
	static int flagCount;

public:
	Flag(const CellPosition & flagposition); // A constructor for initialization
	static int Getflagcount();
	static int minusflagcount();
	virtual void Draw(Output* pOut) const; // Draws a flag in a selected cell
	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the flag
	virtual void Save(ofstream& OutFile) override;
	virtual void Load(ifstream& Infile) override;
	virtual ~Flag(); // Virtual destructor
};