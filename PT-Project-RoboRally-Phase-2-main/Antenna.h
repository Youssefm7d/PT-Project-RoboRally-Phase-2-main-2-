#pragma once
#include "GameObject.h"
#include <fstream>

class Antenna :public GameObject
{
	static int AntennaCount;
public:
	Antenna(const CellPosition & antennaPosition);
	static int GetAntennaCount();
	static int minusAntennaCount();
	virtual void Draw(Output* pOut) const; // Draws an antenna
	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the antenna by deciding the players turns
	virtual void Save(ofstream& OutFile) override;
	virtual void Load(ifstream& Infile) override;
	virtual ~Antenna();
};

