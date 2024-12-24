#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition()
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;
}

CellPosition::CellPosition(int v, int h)
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition(int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
	// from the passed (cellNum)
	// (*this) = ... --> this will copy the returned (vCell and hCell)
	//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v)
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	if (v >= START_H_V && v <= MAX_V_CELLS) {
		vCell = v;
		return true;
	}
	//DONE

	return false; // this line sould be changed with your implementation
}

bool CellPosition::SetHCell(int h)
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	if (h >= START_H_V && h <= MAX_H_CELLS) {
		hCell = h;
		return true;
	}
	//DONE

	return false; // this line should be changed with your implementation
}

int CellPosition::VCell() const
{
	return vCell;
}

int CellPosition::HCell() const
{
	return hCell;
}

bool CellPosition::IsValidCell() const
{
	///TODO: Implement this function as described in the .h file
	if (vCell < START_H_V || vCell > MAX_V_CELLS || hCell < START_H_V || hCell > MAX_H_CELLS/*vCell == -1 || hCell == -1*/)
		return false;
	else
		return true;
	//DONE
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
	// which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition& cellPosition)
{
	// Note:
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// just define an integer that represents cell number and calculate it using the passed cellPosition then return it

	///TODO: Implement this function as described in the .h file
	if (cellPosition.IsValidCell()) {
		int cellNum = 1 + (MAX_V_CELLS - cellPosition.VCell()) * ROW_SIZE + cellPosition.HCell();
	//DONE

		return cellNum;
	}
	else
		return -1;
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)

	CellPosition position;

	/// TODO: Implement this function as described in the .h file
	position.SetVCell(MAX_V_CELLS - (cellNum / ROW_SIZE));
	position.SetHCell((cellNum % ROW_SIZE) - 1);
	//DONE

	// Note: use the passed cellNum to set the vCell and hCell of the "position" variable declared inside the function
	//       I mean: position.SetVCell(...) and position.SetHCell(...) then return it


	return position;
}

void CellPosition::AddCellNum(int addedNum, Direction direction)
{

	/// TODO: Implement this function as described in the .h file
	switch (direction)
	{
	case UP:
		SetVCell(vCell - addedNum);
		break;
	case DOWN:
		SetVCell(vCell + addedNum);
		break;
	case RIGHT:
		SetHCell(hCell + addedNum);
		break;
	case LEFT:
		SetHCell(hCell - addedNum);
		break;
	default:
		break;
	}
	//DONE

	// Note: this function updates the data members (vCell and hCell) of the calling object

}