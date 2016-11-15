using namespace System::Windows::Forms;
using namespace System;
#include "UserIO.h"
void ChangeCurrentCell(unsigned int RowIndex, unsigned int CollumnIndex)//Numeration from 1
{
	MessageBox::Show(Convert::ToString(RowIndex) + " " + Convert::ToString(CollumnIndex), "ChangeCurrentCell");
}
void DeselectCell()
{
	MessageBox::Show("", "DeselectCell");
}
void UpdateText(String^ newString)
{
	MessageBox::Show(newString, "UpdateText");
}
void ReturnText(String ^ newString)
{
	//FormContainer::Form->SetText(newString);
}