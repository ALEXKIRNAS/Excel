#include "New.h"
namespace Excel
{

	int New::getRows()
	{
		return (int)numericUpDown1->Value;
	}
	int New::getCols()
	{
		return (int)numericUpDown2->Value;
	}
	System::Void New::button1_Click(System::Object^  sender, System::EventArgs^  e) {
	good = true;
	Close();
}
	System::Void New::New_Load(System::Object^  sender, System::EventArgs^  e) {
	good = false;
}
}