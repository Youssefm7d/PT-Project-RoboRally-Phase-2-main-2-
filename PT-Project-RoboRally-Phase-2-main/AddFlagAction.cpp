#include "AddFlagAction.h"



AddFlagAction::AddFlagAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}


void AddFlagAction::ReadActionParameters()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==
	// 1- Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	// 2- Read the flagPos
	pOut->PrintMessage("click where to place the flag ");
	flagPos = pIn->GetCellClicked();
	// 4- Make the needed validations on the read parameters
	//check if cell position is valid
	bool validationsCheck = flagPos.IsValidCell();
	if (!validationsCheck) {
		pOut->PrintMessage("invalid cell position");
		flagPos = CellPosition(-1, -1); //remoVe placed flag
		Flag::minusflagcount();
		return;
	}
	// 5- Clear status bar
	pOut->ClearStatusBar();

	//Done
}

void AddFlagAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==
	
	// 2-get a pointer to the Grid from the ApplicationManager
	Grid* pGrid = pManager->GetGrid();

	
	if (Flag::Getflagcount() >= 1)
		{
			pGrid->PrintErrorMessage("A flag is already placed! Only one flag can be added. Click to continue...");
			return;
		}
	// 1-Create a flag object
	Flag* flagpointer = new Flag(flagPos);

	// 3-Add the flag object to the GameObject of its Cell:
	bool addcheck = pGrid->AddObjectToCell(flagpointer);

	// 4-Check if the flag was added and print an errror message if flag couldn't be added
	if (!addcheck) {
		pGrid->PrintErrorMessage("Error: flag can't be added");
		Flag::minusflagcount();
	}
	//Done
}

AddFlagAction::~AddFlagAction()
{
}