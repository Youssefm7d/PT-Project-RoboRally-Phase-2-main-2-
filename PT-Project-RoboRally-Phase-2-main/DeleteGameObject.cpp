#include "DeleteGameObject.h"
#include "Grid.h"
#include "Output.h"
#include "GameObject.h"
#include "CellPosition.h"
#include "Input.h"


DeleteGameObject::DeleteGameObject(ApplicationManager* pApp) : Action(pApp)
{
}

void DeleteGameObject::ReadActionParameters()
{
    Grid* pGrid = pManager->GetGrid();
    Input* pIn = pGrid->GetInput();
    Output* pOut = pGrid->GetOutput();

    pOut->PrintMessage("Click on the cell to delete its game object...");
    targetPosition = pIn->GetCellClicked();
    pOut->ClearStatusBar();
}

void DeleteGameObject::Execute()
{
    // Access Grid
    Grid* pGrid = pManager->GetGrid();

    // Validate position
    if (!targetPosition.IsValidCell())
    {
        pGrid->PrintErrorMessage("Invalid cell position! Click to continue...");
        return;
    }

    // Remove the game object from the specified position
    GameObject* pObject = pGrid->Get_object_pos(targetPosition);

    // Check if an object was deleted
    if (pObject)
    {
        delete pObject; // Free memory
        pGrid->PrintErrorMessage("Game object deleted successfully! Click to continue...");
    }
    else
    {
        pGrid->PrintErrorMessage("No game object found at the selected cell! Click to continue...");
    }
}

DeleteGameObject::~DeleteGameObject()
{
}
