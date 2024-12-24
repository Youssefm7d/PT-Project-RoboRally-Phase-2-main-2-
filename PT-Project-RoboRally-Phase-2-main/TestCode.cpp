#include "Input.h"
#include "Output.h"

//This is a test code to test the Input and Output classes

int main()
{
	int x, y;

	//Create Input and Output objects to test
	Output* pOut = new Output();
	Input* pIn = pOut->CreateInput();

	//Starting the test
	pOut->PrintMessage("This demo is to test classes of phase 1, Click anywhere to start the test");
	pIn->GetPointClicked(x, y);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 1:	
	//			- Create The FULL Tool bar of Design Mode, the grid area, the status bar
	//				and an empty command bar
	//			- This has already been done through the constrcutor of class Output
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST1: Drawing Tool bar, Grid, Status bar and Empty Command bar, Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click


	// 1.1- Drawing the Command bar in the Game mode
	// =============================================
	pOut->PrintMessage("1.1- Drawing the Command bar in the Game mode, Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	Command savedCommands[5];
	for (int i = 0; i < 5; i++)
		savedCommands[i] = NO_COMMAND;
	Command availableCommands[10];
	for (int i = 0; i < 10; i++)
		availableCommands[i] = MOVE_FORWARD_ONE_STEP;
	pOut->CreateCommandsBar(savedCommands, 5, availableCommands, 10);
	pOut->PrintMessage("1.1.1- Finished Drawing the Command bar in the Game mode, Click to continue");

	pOut->PrintMessage("1.1.2- Testing the Command bar in the Game mode, Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	///TODO: Draw the command bar with only 4 available commands and 4 empty slots for saved commands
	availableCommands[0] = MOVE_FORWARD_ONE_STEP;
	availableCommands[1] = MOVE_BACKWARD_ONE_STEP;
	availableCommands[2] = ROTATE_CLOCKWISE;
	availableCommands[3] = ROTATE_COUNTERCLOCKWISE;
	for (int i = 0; i < 4; i++)
		savedCommands[i] = NO_COMMAND;
	pOut->CreateCommandsBar(savedCommands, 4, availableCommands, 4);
	//DONE

	pOut->PrintMessage("1.1.2- Finished Testing the Command bar in the Game mode, Click to continue");

	pOut->PrintMessage("1.1.3- Testing the Command bar in the Game mode, Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	///TODO: Draw the command bar with 5 saved commands and 7 available commands, 
	/// 	but the first saved command will be MOVE_FORWARD_ONE_STEP
	///		and the first available command will be NO_COMMAND

	availableCommands[0] = NO_COMMAND;
	availableCommands[1] = MOVE_FORWARD_ONE_STEP;
	availableCommands[2] = MOVE_FORWARD_TWO_STEPS;
	availableCommands[3] = MOVE_BACKWARD_ONE_STEP;
	availableCommands[4] = MOVE_BACKWARD_TWO_STEPS;
	availableCommands[5] = ROTATE_CLOCKWISE;
	availableCommands[6] = ROTATE_COUNTERCLOCKWISE;
	savedCommands[0] = MOVE_FORWARD_ONE_STEP;
	for (int i = 1; i < 5; i++)
		savedCommands[i] = NO_COMMAND;
	pOut->CreateCommandsBar(savedCommands, 5, availableCommands, 7);
	//DONE

	pOut->PrintMessage("1.1.3- Finished Testing the Command bar in the Game mode, Click to continue");

	pOut->PrintMessage("1.1.4- Testing the Command bar in the Game mode, Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	///TODO: Draw the command bar with 5 saved commands and 6 available commands,
	/// 	but the first saved command will be MOVE_FORWARD_TWO_STEPS
	///		and the first available command will be NO_COMMAND as previous test
	availableCommands[0] = NO_COMMAND;
	availableCommands[1] = MOVE_FORWARD_ONE_STEP;
	availableCommands[2] = MOVE_FORWARD_TWO_STEPS;
	availableCommands[3] = MOVE_BACKWARD_ONE_STEP;
	availableCommands[4] = ROTATE_CLOCKWISE;
	availableCommands[5] = ROTATE_COUNTERCLOCKWISE;
	savedCommands[0] = MOVE_FORWARD_TWO_STEPS;
	for (int i = 1; i < 5; i++)
		savedCommands[i] = NO_COMMAND;
	pOut->CreateCommandsBar(savedCommands, 5, availableCommands, 7);
	//DONE

	pOut->PrintMessage("1.1.4- Finished Testing the Command bar in the Game mode, Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 2:	
	//			Testing the Output Class
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST2: Testing the [ Output ] class, Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	// 2.1- Drawing Water Pits Cells //
	// =============================

	pOut->PrintMessage("2.1- Drawing (Water Pits Cells) Test,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	CellPosition cell_10(10);	// cell num 10
	CellPosition cell_53(53);	// cell num 53
	CellPosition cell_1(1);		// cell num 1

	// TODO: Draw Water Pits in cell_10 and cell_53 and cell_1 (Invalid)
	pOut->DrawWaterPit(cell_10);
	pOut->DrawWaterPit(cell_53);
	pOut->DrawWaterPit(cell_1);
	//DONE

	pOut->PrintMessage("FINISHED - Drawing (Water Pits) Test,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click


	// 2.2- Drawing DangerZone Cells //
	// =============================
	pOut->PrintMessage("2.2- Drawing (DangerZone Cells) Test,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	CellPosition cell_20(20);	// cell num 20
	CellPosition cell_60(60);	// cell num 60

	// TODO: Draw DangerZone in cell_20, [cell_60 and cell_1] (Invalid)
	pOut->DrawDangerZone(cell_20);
	pOut->DrawDangerZone(cell_60);
	pOut->DrawDangerZone(cell_1);
	//DONE

	pOut->PrintMessage("FINISHED - Drawing (DangerZone) Test,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click


	// 2.3- Drawing Players Test //
	// =========================
	pOut->PrintMessage("2.3- Drawing (Players) Test,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	CellPosition player_1(1);
	CellPosition player_2(2);
	CellPosition player_15(2, 18);
	CellPosition player_99(2, 5);


	///TODO: Call Function DrawPlayer of Class Ouput Multiple Times
	///       to draw the following players:
	///       playerNum (0) with color (PlayerColors[0] defined in UI object) 
	///			in cell position (player_1 declared above) pointing to right direction
	pOut->DrawPlayer(player_1, 1, UI.PlayerColors[0], RIGHT);
	///       playerNum (1) with color (PlayerColors[1] defined in UI object) 
	///			in cell position (player_1 declared above) pointing to the up direction
	pOut->DrawPlayer(player_1, 2, UI.PlayerColors[1], UP);
	///       playerNum (2) with color (PlayerColors[2] defined in UI object) 
	///			in cell position (player_1 declared above) pointing to the down direction --> Invalid
	pOut->DrawPlayer(player_1, 3, UI.PlayerColors[2], LEFT);
	///       playerNum (3) with color (PlayerColors[3] defined in UI object) 
	///			in cell position (player_1 declared above) pointing to the left direction --> Invalid
	pOut->DrawPlayer(player_1, 3, UI.PlayerColors[3], LEFT);
	///       playerNum (0) with color (PlayerColors[0] defined in UI object) 
	///			in cell position (player_15 declared above) pointing to the left direction --> Invalid
	pOut->DrawPlayer(player_15, 0, UI.PlayerColors[0], LEFT);
	///       playerNum (1) with color (PlayerColors[1] defined in UI object) 
	///			in cell position (player_99 declared above) pointing up
	pOut->DrawPlayer(player_99, 1, UI.PlayerColors[1], UP);
	///       playerNum (5) with color (PlayerColors[1] defined in UI object) 
	///			in cell position (player_99 declared above) pointing down--> Invalid
	pOut->DrawPlayer(player_99, 5, UI.PlayerColors[1], DOWN);
	///       playerNum (-1) with color (PlayerColors[1] defined in UI object) 
	///			in cell position (player_99 declared above) pointing left--> Invalid
	pOut->DrawPlayer(player_99, -1, UI.PlayerColors[1], LEFT);
	//DONE

	pOut->PrintMessage("FINISHED - Drawing (Players) Test,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	/// 2.4- Drawing Flags
	/// ====================
	/// 
	pOut->PrintMessage("2.4- Drawing (Flags) Test,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	CellPosition flag_1(9);
	CellPosition flag_60(60);
	CellPosition flag_99(99);
	//DONE

	// TODO: Draw Flags in cell positions (flag_1, flag_60, flag_99)
	pOut->DrawFlag(flag_1);
	pOut->DrawFlag(flag_60);
	pOut->DrawFlag(flag_99);
	//DONE

	pOut->PrintMessage("FINISHED - Drawing (Flags) Test,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	/// 2.5- Drawing Belts
	/// ====================
	/// 
	pOut->PrintMessage("2.5- Drawing (Belts) Test,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	CellPosition belt_start_1(1);
	CellPosition belt_end_1(5);
	CellPosition belt_start_2(12);
	CellPosition belt_end_2(45);
	CellPosition belt_start_3(54);
	CellPosition belt_end_3(32);
	CellPosition belt_end_4(33);

	// TODO: Draw 5 belts
	//		1- from belt_start_1 to belt_end_1
	pOut->DrawBelt(belt_start_1, belt_end_1);
	//pOut->DrawBelt(belt_end_1, belt_start_1);
	//		2- from belt_start_2 to belt_end_2 
	pOut->DrawBelt(belt_start_2, belt_end_2);
	//		3- from belt_start_3 to belt_end_3
	pOut->DrawBelt(belt_start_3, belt_end_3);
	//		4- from belt_start_3 to belt_end_4 --> Invalid
	pOut->DrawBelt(belt_start_3, belt_end_4);
	//		5- from belt_end_1 to belt_end_2 --> Invalid
	pOut->DrawBelt(belt_end_1, belt_end_2);
	// 		6- from belt_end_3 to belt_end_4 --> Invalid
	pOut->DrawBelt(belt_end_3, belt_end_4);
	//DONE


	pOut->PrintMessage("FINISHED - Drawing (Belts) Test,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click




	// 2.6- Drawing Rotating Gears //
	// ===========================

	pOut->PrintMessage("2.6- Drawing (Rotating Gears) Test,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	CellPosition cell_13(13);
	CellPosition cell_19(19);

	// TODO: Draw Rotating Gears in cell positions (cell_13, cell_19)
	//        1. At cell_13 with rotation left (anticlockwise)
	pOut->DrawRotatingGear(cell_13, CW);
	//        2. At cell_19 with rotation right (clockwise)
	pOut->DrawRotatingGear(cell_19, ACW);
	//DONE

	pOut->PrintMessage("FINISHED - Drawing (Rotating Gears) Test,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	// 2.7- Drawing Antenna //
	// ======================
	pOut->PrintMessage("2.7- Drawing (Antenna) Test,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	CellPosition cell_25(25);

	// TODO: Draw Antenna in cell position (cell_25)
	pOut->DrawAntenna(cell_25);
	//DONE

	pOut->PrintMessage("FINISHED - Drawing (Antenna) Test,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	// 2.8- Drawing Workshop //
	// =======================

	pOut->PrintMessage("2.8- Drawing (Workshop) Test,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	CellPosition cell_30(30);

	// TODO: Draw Workshop in cell position (cell_30)
	pOut->DrawWorkshop(cell_30);
	//DONE

	pOut->PrintMessage("FINISHED - Drawing (Workshop) Test,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click





	///////////////////////////////////////////////////////////////////////////////////
	// TEST 3: 
	//			Input Class - Part 1
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST3: Now Time to test class [ Input ], Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	/// 3.1- Getting Integer ///
	/// ===========================
	pOut->PrintMessage("3.1- (GetInteger) Test, Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click


	///TODO: Add code here to 
	// 1- Call GetInteger Function and receive its returned integer
	pOut->PrintMessage("Enter Number: ");
	int temp = pIn->GetInteger(pOut);
	// 2- Print it in the status bar in this format:   You Entered: 116
	pOut->PrintMessage("You Entered: " + to_string(temp));
	//    (assuming the entered number is 116)
	// 3- Call GetPointClicked() function
	pIn->GetPointClicked(x, y);


	pOut->PrintMessage("FINISHED - (GetInteger) Test, Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	/// 3.2- Getting Cell Clicked ///
	/// =========================
	pOut->CreateDesignModeToolBar();
	pOut->PrintMessage("3.2- (GetCellClicked) Test, Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click


	///TODO: Add code here to 
	// 1- Call function GetCellClicked
	CellPosition cell = pIn->GetCellClicked();
	// 2- Print on the status bar the vCell and hCell of the clicked cell
	pOut->PrintMessage("vCell: " + to_string(cell.VCell()) + " hCell: " + to_string(cell.HCell()));
	// 3- Repeat Step 1 and 2 five times
	cell = pIn->GetCellClicked();
	pOut->PrintMessage("vCell: " + to_string(cell.VCell()) + " hCell: " + to_string(cell.HCell()));

	cell = pIn->GetCellClicked();
	pOut->PrintMessage("vCell: " + to_string(cell.VCell()) + " hCell: " + to_string(cell.HCell()));

	cell = pIn->GetCellClicked();
	pOut->PrintMessage("vCell: " + to_string(cell.VCell()) + " hCell: " + to_string(cell.HCell()));

	cell = pIn->GetCellClicked();
	pOut->PrintMessage("vCell: " + to_string(cell.VCell()) + " hCell: " + to_string(cell.HCell()));

	cell = pIn->GetCellClicked();
	pOut->PrintMessage("vCell: " + to_string(cell.VCell()) + " hCell: " + to_string(cell.HCell()));


	pOut->PrintMessage("FINISHED - (GetCellClicked) Test, Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click


	/// 3.3- Reading a String ///
	/// =====================
	pOut->PrintMessage("3.3- (GetSrting) Test, Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click


	///TODO: Add code here to 
	// 1- Read a string from the user on the status bar
	pOut->PrintMessage("Enter String: ");
	string str = pIn->GetSrting(pOut);
	// 2- After reading the string clear the status bar
	pOut->ClearStatusBar();
	// 3- print on the status bar "You Entered" then print the string
	pOut->PrintMessage("You Entered: " + str);
	// NOTE: GetString() is already implemented. It is just required from you to call it
	pIn->GetPointClicked(x, y);


	pOut->PrintMessage("FINISHED - (GetSrting) Test, Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 4:	
	//			Test the functions of CellPosition Class
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST4: Testing the [ CellPosition ] class, Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	pOut->PrintMessage("4.1- (Setters with Validation) Test, Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	CellPosition cellPos_1(0, 0);

	///TODO:
	// 1- Ask user to enter an integer and read it using GetInteger()
	pOut->PrintMessage("Enter an number for VCell: ");
	int VcellPos = pIn->GetInteger(pOut);
	// 2- Call SetVCell() of cellpos_1 with that integer
	cellPos_1.SetVCell(VcellPos);
	// 3- Print GetVCell() of cellpos_1 as follows: "Now the vCell = 5" (assuming the entered integer is 5)
	pOut->PrintMessage("Now the vCell = " + to_string(cellPos_1.VCell()));
	// 4- Call GetPointClicked()
	pIn->GetPointClicked(x, y);

	// 5- Repeat the above steps FIVE TIMES
	//for (int i = 0; i < 5; i++) {
	//	pOut->PrintMessage("Enter an number for VCell: ");
	//	VcellPos = pIn->GetInteger(pOut);
	//	cellPos_1.SetVCell(VcellPos);
	//	pOut->PrintMessage("Now the vCell = " + to_string(cellPos_1.VCell()));
	//	pIn->GetPointClicked(x, y);
	//}
	//DONE

	// 6- Repeat all the above steps to test SetHCell() function instead with the needed modifications
		///TODO:
	// 1- Ask user to enter an integer and read it using GetInteger()
	pOut->PrintMessage("Enter a number for HCell: ");
	int HcellPos = pIn->GetInteger(pOut);
	// 2- Call SetHCell() of cellpos_1 with that integer
	cellPos_1.SetHCell(HcellPos);
	// 3- Print GetHCell() of cellpos_1 as follows: "Now the hCell = 5" (assuming the entered integer is 5)
	pOut->PrintMessage("Now the hCell = " + to_string(cellPos_1.HCell()));
	// 4- Call GetPointClicked()
	pIn->GetPointClicked(x, y);

	// 5- Repeat the above steps FIVE TIMES
	//for (int i = 0; i < 5; i++) {
	//	pOut->PrintMessage("Enter a number for HCell: ");
	//	HcellPos = pIn->GetInteger(pOut);
	//	cellPos_1.SetHCell(HcellPos);
	//	pOut->PrintMessage("Now the hCell = " + to_string(cellPos_1.HCell()));
	//	pIn->GetPointClicked(x, y);
	//}
	//DONE

	pOut->PrintMessage("FINISHED - (Setters with Validation) Test, Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	pOut->PrintMessage("4.2- (GetCellNumFromPosition) Test, Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	/// TODO:
	// 1- Read from user two integers representing vCell and hCell
	pOut->PrintMessage("Enter number for vCell: ");
	VcellPos = pIn->GetInteger(pOut);
	pOut->PrintMessage("Enter number for hCell: ");
	HcellPos = pIn->GetInteger(pOut);
	// 2- Creates a CellPosition object of them
	CellPosition cellPos1(VcellPos, HcellPos);
	// 3- Use the function GetCellNum() to get the corresponding Cell Number (it used function : GetCellNumFromPosition() inside it)
	// 4- Print the Cell Number on the status bar
	pOut->PrintMessage("Cell Number= " + to_string(cellPos1.GetCellNum()));
	pIn->GetPointClicked(x, y);

	// 5- Repeat the above steps Five TIMES
	CellPosition* cellPos11[5];
	//for (int i = 0; i < 5; i++) {
	//	pOut->PrintMessage("Enter number for vCell: ");
	//	VcellPos = pIn->GetInteger(pOut);
	//	pOut->PrintMessage("Enter number for hCell: ");
	//	HcellPos = pIn->GetInteger(pOut);
	//	cellPos11[i] = new CellPosition(VcellPos, HcellPos);
	//	pOut->PrintMessage("Cell Number= " + to_string(cellPos11[i]->GetCellNum()));
	//	pIn->GetPointClicked(x, y);
	//}
	//DONE


	pOut->PrintMessage("FINISHED - (GetCellNumFromPosition) Test, Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	pOut->PrintMessage("4.3- (GetCellPositionFromNum) Test, Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	/// TODO:
	// 1- Read from user one integer representing cellNum
	pOut->PrintMessage("Enter number for CellNum: ");
	int cellNum = pIn->GetInteger(pOut);
	// 2- Creates a CellPosition object of that integer using that constructor: 
	//		CellPosition (int cellNum);
	//			--> it uses the function : GetCellPositionFromNum () inside it
	CellPosition cellPos2(cellNum);
	// 4- Print the Cell vCell and hCell on the status bar
	pOut->PrintMessage("vCell= " + to_string(cellPos2.VCell()) + ", hCell= " + to_string(cellPos2.HCell()));
	pIn->GetPointClicked(x, y);
	
	// 5- Repeat the above steps Five TIMES
	CellPosition* cellPos22[5];
	//for (int i = 0; i < 5; i++) {
	//	pOut->PrintMessage("Enter number for CellNum: ");
	//	cellNum = pIn->GetInteger(pOut);
	//	cellPos22[i] = new CellPosition(cellNum);
	//	pOut->PrintMessage("vCell= " + to_string(cellPos22[i]->VCell()) + ", hCell= " + to_string(cellPos22[i]->HCell()));
	//	pIn->GetPointClicked(x, y);
	//}
	//DONE

	pOut->PrintMessage("FINISHED - (GetCellPositionFromNum) Test, Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	pOut->PrintMessage("4.4- (AddCellNum) Test, Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	/// TODO:
	// 1- Read from user two integers representing cellNum and addedNum
	pOut->PrintMessage("Enter number for CellNum: ");
	cellNum = pIn->GetInteger(pOut);
	pOut->PrintMessage("Enter number for AddedNum: ");
	int addedNum = pIn->GetInteger(pOut);
	// 2- Creates a CellPosition object of cellNum
	CellPosition cellPos3(cellNum);
	// 3- Use the function AddCellNum() to add the addedNum to the cellNum
	cellPos3.AddCellNum(addedNum, UP);
	// 4- Print the vCell and hCell of the new Cell Position on the status bar
	pOut->PrintMessage("vCell= " + to_string(cellPos3.VCell()) + ", hCell= " + to_string(cellPos3.HCell()));
	pIn->GetPointClicked(x, y);
	// 5- Repeat the above steps Four TIMES with each time a different direction
	CellPosition* cellPos33[5];
	//for (int i = 0; i < 4; i++) {
	//	pOut->PrintMessage("Enter number for CellNum: ");
	//	cellNum = pIn->GetInteger(pOut);
	//	pOut->PrintMessage("Enter number for AddedNum: ");
	//	addedNum = pIn->GetInteger(pOut);
	//	cellPos33[i] = new CellPosition(cellNum);
	//	pOut->PrintMessage("vCell= " + to_string(cellPos33[i]->VCell()) + ", hCell= " + to_string(cellPos33[i]->HCell()));
	//	pIn->GetPointClicked(x, y);
	//}
	//DONE

	pOut->PrintMessage("FINISHED - (AddCellNum) Test, Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
		// TEST 5: 
		//			Input Class - Part2: Check for the user action
		///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST5: Testing Input ability to detect User Action, click anywhere");

	ActionType ActType;

	///TODO:  
	// You must add a case for EACH action (both Design mode and Game mode actions)
	// Add cases for the missing actions below
	do
	{
		ActType = pIn->GetUserAction();

		int clickedCommandItemIndex; // if the action is SELECT_COMMAND, this will have the icon index
		switch (ActType)
		{
		case SET_FLAG_CELL:
			pOut->PrintMessage("Action: SET_FLAG_CELL , Click anywhere");
			break;


		case EXIT:
			break;

		case TO_PLAY_MODE:

			pOut->PrintMessage("Action: TO_PLAY_MODE , Click anywhere");
			pIn->GetPointClicked(x, y);
			pOut->CreatePlayModeToolBar();
			pIn->GetPointClicked(x, y);

			///TODO:  Call Function (PrintPlayersInfo) of Class Output with a string similar to 
			//        the one given in the screenshot of project document 
			pOut->PrintPlayersInfo("P1(1, RIGHT, 10), P2(1, UP, 10) | Curr = P1");

			cell = pIn->GetCellClicked();
			pOut->PrintPlayersInfo("P1( " + to_string(cell.HCell()) + " ,Right, " + to_string(cell.VCell()) + " )");
			cell = pIn->GetCellClicked();
			pOut->PrintPlayersInfo("P2( " + to_string(cell.HCell()) + " ,Up, " + to_string(cell.VCell()) + " )");

			break;



		case EXECUTE_COMMANDS:
			pOut->PrintMessage("Action: EXECUTE_COMMAND , Click anywhere");
			break;
		case SELECT_COMMAND:
			pOut->PrintMessage("Action: SELECT_COMMAND , Select a command");
			clickedCommandItemIndex = pIn->GetSelectedCommandIndex();
			pOut->PrintMessage("Action: SELECT_COMMAND " + to_string(clickedCommandItemIndex) + " , Click anywhere");
			break;

		case GRID_AREA:
			pOut->PrintMessage("Action: GRID_AREA , Click anywhere");
			break;

		case STATUS:
			pOut->PrintMessage("Action: STATUS , Click anywhere");
			break;
			///TODO:  ADD Cases similarly for ALL the remaining actions of DESIGN Mode
		case ADD_ANTENNA:
			pOut->PrintMessage("Action: ADD_ANTENNA , Click anywhere");
			break;
		case ADD_BELT:
			pOut->PrintMessage("Action: ADD_BELT , Click anywhere");
			break;

		case ADD_WATER_PIT:
			pOut->PrintMessage("Action: ADD_WATER_PIT , Click anywhere");
			break;

		case ADD_DANGER_ZONE:
			pOut->PrintMessage("Action: ADD_DANGER_ZONE , Click anywhere");
			break;

		case ADD_WORKSHOP:
			pOut->PrintMessage("Action: ADD_WORKSHOP , Click anywhere");
			break;

		case ADD_ROTATING_GEAR:
			pOut->PrintMessage("Action: ADD_ROTATING_GEAR , Click anywhere");
			break;

		case COPY_GAME_OBJECT:
			pOut->PrintMessage("Action: COPY_GAME_OBJECT , Click anywhere");
			break;

		case CUT_GAME_OBJECT:
			pOut->PrintMessage("Action: CUT_GAME_OBJECT , Click anywhere");
			break;
		case PASTE_GAME_OBJECT:
			pOut->PrintMessage("Action: PASTE_GAME_OBJECT , Click anywhere");
			break;

		case DELETE_GAME_OBJECT:
			pOut->PrintMessage("Action: DELETE_GAME_OBJECT , Click anywhere");
			break;

		case SAVE_GRID:
			pOut->PrintMessage("Action: SAVE_GRID , Click anywhere");
			break;

		case OPEN_GRID:
			pOut->PrintMessage("Action: OPEN_GRID , Click anywhere");
			break;
			///TODO:  ADD Cases similarly for ALL the remaining actions of PLAY Mode
		case TO_DESIGN_MODE:
			pOut->PrintMessage("Action: TO_DESIGN_MODE , Click anywhere");
			pOut->CreateDesignModeToolBar();
			break;

		case REBOOT_REPAIR:
			pOut->PrintMessage("Action: REBOOT_REPAIR , Click anywhere");
			break;

		case USE_CONSUMABLE:
			pOut->PrintMessage("Action: USE_CONSUMABLE , Click anywhere");
			break;

		case NEW_GAME:
			pOut->PrintMessage("Action: NEW_GAME , Click anywhere");
			break;

		case Exit:
			pOut->PrintMessage("Action: Exit , Click anywhere");
			break;
		default:
			pOut->PrintMessage(" no Action is taken , Click anywhere");
			break;



		}
	} while (ActType != EXIT);


	/// Exiting
	pOut->PrintMessage("Action: EXIT, test is finished, click anywhere to exit");
	pIn->GetPointClicked(x, y);


	delete pIn;
	delete pOut;
	return 0;
}