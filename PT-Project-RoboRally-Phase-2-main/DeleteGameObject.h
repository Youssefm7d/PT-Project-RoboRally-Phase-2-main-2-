#pragma once
#include "Action.h"
#include "CellPosition.h"
class DeleteGameObject : public Action
{
    CellPosition targetPosition; // The position of the object to delete
public:
    DeleteGameObject(ApplicationManager* pApp); // Constructor
    virtual void ReadActionParameters();       // Reads cell position
    virtual void Execute();                    // Executes delete logic
    virtual ~DeleteGameObject();               // Destructor
};