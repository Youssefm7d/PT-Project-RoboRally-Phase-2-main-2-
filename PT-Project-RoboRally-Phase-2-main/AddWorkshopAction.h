#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include "Workshop.h"

class AddWorkshopAction :public Action
{
	CellPosition WorkshopPos;
public:

	AddWorkshopAction(ApplicationManager* pApp);
	virtual void ReadActionParameters(); // Reads action parameters 

	virtual void Execute(); // Creates a new rotating gear Object 
	// then Sets this rotating gear object to the GameObject Pointer of its Cell
	virtual ~AddWorkshopAction();

};

