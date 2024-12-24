#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

#define MAX_PLAYERS_NUM 2

#define CW	true
#define ACW	false

// This file contains some global constants and definitions to be used in the project.

enum ActionType // The actions supported (add more as needed)
{
	//  [1] Actions of Design Mode
	SET_FLAG_CELL,	// Set Flag on a Cell
	ADD_FLAG = SET_FLAG_CELL,
	TO_PLAY_MODE,	// Go to Play Mode
	EXIT,			// Exit Application
	///TODO: Add more action types of Design Mode
	ADD_ANTENNA,
	ADD_BELT,
	ADD_WATER_PIT,
	ADD_DANGER_ZONE,
	ADD_WORKSHOP,
	ADD_ROTATING_GEAR,
	COPY_GAME_OBJECT,
	CUT_GAME_OBJECT,
	PASTE_GAME_OBJECT,
	DELETE_GAME_OBJECT,
	SAVE_GRID,
	OPEN_GRID,
	// DONE


	//  [2] Actions of Play Mode

	SELECT_COMMAND,		// Select a command from the available ones to be executed
	EXECUTE_COMMANDS,	// Execute the saved commands
	TO_DESIGN_MODE,	// Go to Design Mode
	///TODO: Add more action types of Play Mode
	REBOOT_REPAIR,	//reboot and repair their robot, restoring some health points.
	USE_CONSUMABLE_TOOLKIT,		//use a consumable item
	USE_CONSUMABLE_HACKDEVICE,
	NEW_GAME,			//Restarts the game,
	// Exit,			//Exits the application
	// DONE

	//  [3] Others

	EMPTY,							// Empty Area in ToolBar (NOT inside any action icon)
	GRID_AREA,						// Inside Grid Area
	STATUS 							// Inside StatusBar Area
};

enum Direction // Directions of the game
{
	UP,
	DOWN,
	RIGHT,
	LEFT
};

enum Command
{
	NO_COMMAND,
	MOVE_FORWARD_ONE_STEP,
	MOVE_BACKWARD_ONE_STEP,
	MOVE_FORWARD_TWO_STEPS,
	MOVE_BACKWARD_TWO_STEPS,
	MOVE_FORWARD_THREE_STEPS,
	MOVE_BACKWARD_THREE_STEPS,
	ROTATE_CLOCKWISE,
	ROTATE_COUNTERCLOCKWISE,

	COMMANDS_COUNT,
};

#endif