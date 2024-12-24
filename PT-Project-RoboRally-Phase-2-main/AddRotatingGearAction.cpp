#include "AddRotatingGearAction.h"

AddRotatingGearAction::AddRotatingGearAction(ApplicationManager * pApp):Action(pApp)
{
}

void AddRotatingGearAction::ReadActionParameters()
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	// 2- Read the gearPos
	pOut->PrintMessage("click where to place the Gear ");
	gearPos = pIn->GetCellClicked();
	// 3- Read whether the direction will be clockwise or not
	pOut->PrintMessage("choose direction oF Gear 0 clockwise and 1 anti-clockwise ");
	clockwise = pIn->GetInteger(pOut);
	// 4- Make the needed validations on the read parameters
	bool validati = gearPos.IsValidCell();
	if (!validati) {
		pOut->PrintMessage("invalid cell position");
		return;
	}
	// 5- Clear status bar
}

void AddRotatingGearAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1-Create a rotating gear object
	RotatingGear* RotatingGearpointer = new RotatingGear(gearPos, clockwise);

	// 2-get a pointer to the Grid from the ApplicationManager
	Grid* pGrid = pManager->GetGrid();

	// 3-Add the rotating object to the GameObject of its Cell:
	bool addcheck = pGrid->AddObjectToCell(RotatingGearpointer);

	// 4-Check if the WaterPit was added and print an errror message if gear couldn't be added
	if (!addcheck) {
		pGrid->PrintErrorMessage("invalid RotatingGear position");
	}

}

AddRotatingGearAction::~AddRotatingGearAction()
{
}
