#include "AddAntennaAction.h"

AddAntennaAction::AddAntennaAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}


void AddAntennaAction::ReadActionParameters()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==
	// 1- Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	// 2- Read the AntennaPos
	pOut->PrintMessage("click where to place the Antenna ");
	AntennaPos = pIn->GetCellClicked();
	// 4- Make the needed validations on the read parameters
	//check if cell position is valid
	bool A_validationsCheck = AntennaPos.IsValidCell();
	if (!A_validationsCheck) {
		pOut->PrintMessage("invalid cell position");
		AntennaPos = CellPosition(-1, -1); //remoVe placed flag
		Antenna::minusAntennaCount();
		return;
	}
	// 5- Clear status bar
	pOut->ClearStatusBar();

	//Done
}

void AddAntennaAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 2-get a pointer to the Grid from the ApplicationManager
	Grid* pGrid = pManager->GetGrid();


	if (Antenna::GetAntennaCount() >= 1)
	{
		pGrid->PrintErrorMessage("A Antenna is already placed! Only one Antenna can be added. Click to continue...");
		return;
	}
	// 1-Create a flag object
	Antenna* Antennapointer = new Antenna(AntennaPos);

	// 3-Add the flag object to the GameObject of its Cell:
	bool addcheck = pGrid->AddObjectToCell(Antennapointer);

	// 4-Check if the flag was added and print an errror message if flag couldn't be added
	if (!addcheck) {
		pGrid->PrintErrorMessage("Error: Antenna can't be added");
	}
	//Done
}

AddAntennaAction::~AddAntennaAction()
{
}