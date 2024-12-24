#include "AddWaterPitaction.h"

AddWaterPitaction::AddWaterPitaction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

void AddWaterPitaction :: ReadActionParameters() {

	// 1- Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	// 2- Read the waterPitPos
	pOut->PrintMessage("click where to place the WaterPit ");
	waterPitPos = pIn->GetCellClicked();
	
	// 3- Make the needed validations on the read parameters
	//check if cell position is valid
	bool validati = waterPitPos.IsValidCell();
	if (!validati) {
		pOut->PrintMessage("invalid cell position");
		return;
	}
	// 3- Clear status bar
	pOut->ClearStatusBar();
}

void AddWaterPitaction::Execute() {
	ReadActionParameters();

	// 1-Create a flag object
	
	WaterPit* WaterPitpointer = new WaterPit(waterPitPos);

	// 2-get a pointer to the Grid from the ApplicationManager
	Grid* pGrid = pManager->GetGrid();

	// 3-Add the flag object to the GameObject of its Cell:
	bool addcheck = pGrid->AddObjectToCell(WaterPitpointer);

	// 4-Check if the WaterPit was added and print an errror message if flag couldn't be added
	if (!addcheck) {
		pGrid->PrintErrorMessage("invalid WaterPit position");
	}
	//Done
}	

AddWaterPitaction::~AddWaterPitaction()
{
}
