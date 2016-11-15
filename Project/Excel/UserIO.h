#pragma once
using System::String;
//Called from Form
void ChangeCurrentCell(unsigned int RowIndex, unsigned int CollumnIndex);//Numeration from 1
void DeselectCell();
void UpdateText(String^ newString);
//Called from Code
//#include "FormContainer.h"
void ReturnText(String^ newString);
