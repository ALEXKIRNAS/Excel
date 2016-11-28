#include "Save.h"

namespace Excel
{

	System::Void Save::button2_Click(System::Object^  sender, System::EventArgs^  e) {
		Selection = 2;
		Close();
	}
	System::Void Save::button1_Click(System::Object^  sender, System::EventArgs^  e) {
		Selection = 1;
		Close();
	}
}