#include "MyForm.h"
#include "gcroot.h"
#include "FormContainer.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThread]
void main(array<String^>^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	FormContainer::Form = gcnew Excel::MyForm;
	Application::Run((System::Windows::Forms::Form^)FormContainer::Form);
}