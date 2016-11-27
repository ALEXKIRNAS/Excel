#include "Excel.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThread]
void main(array<String^>^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Excel::Excel^ form = gcnew Excel::Excel;
	Application::Run(form);
}