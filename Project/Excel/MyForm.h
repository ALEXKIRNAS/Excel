#pragma once
#include "Table.h"
#include "Parser.h"
#include <string>
#include "UserIO.h"
using std::string;

namespace Excel {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Spacer;
	private: Table^ table;
	private: System::Windows::Forms::TextBox^  textBox1;








	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Spacer = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->Spacer });
			this->dataGridView1->Location = System::Drawing::Point(-1, 74);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(957, 330);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			this->dataGridView1->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellEndEdit);
			this->dataGridView1->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellValueChanged);
			this->dataGridView1->CurrentCellChanged += gcnew System::EventHandler(this, &MyForm::dataGridView1_CurrentCellChanged);
			// 
			// Spacer
			// 
			this->Spacer->HeaderText = L"";
			this->Spacer->Name = L"Spacer";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(-1, 42);
			this->textBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(956, 22);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox1_KeyPress);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(955, 402);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->dataGridView1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"MyForm";
			this->Text = L"Excel";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		/*  Convert System::String to std::wstring
		*/
		wchar_t* toStdWstring(String^ str) {
			wchar_t* s = new wchar_t[str->Length + 1];
			array <wchar_t>^ temp = str->ToCharArray();

			for (size_t i = 0; i < str->Length; i++)
				s[i] = temp[i];

			s[str->Length] = 0;
			return s;
		}

		void ChangeCurrentCell(unsigned int RowIndex, unsigned int CollumnIndex)//Numeration from 1
		{
		}

		void DeselectCell()
		{
			MessageBox::Show("", "DeselectCell");
		}

		void UpdateText(String^ newString, unsigned int RowIndex, unsigned int CollumnIndex)
		{

			
			wchar_t* value = toStdWstring(newString);

			try {
				table[RowIndex][CollumnIndex]->setResult(parse(wstring(value), table));
				dataGridView1->Rows[RowIndex]->Cells[CollumnIndex]->Value = Convert::ToString(table[RowIndex][CollumnIndex]->getResult());
				table[RowIndex][CollumnIndex]->setIsFormula(true);
			}
			catch (char* str) {
				String^ temp = gcnew String(str);
				dataGridView1->Rows[RowIndex]->Cells[CollumnIndex]->Value = temp;
			}
			catch (int value) {
				table[RowIndex][CollumnIndex]->setIsFormula(false);
			}

			delete[] value;

			table[RowIndex][CollumnIndex]->setValue(newString);
		}

		bool Initialized = 0;
		System::EventHandler^ CellChanged;

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		table = gcnew Table(50 + 1, 50 + 1);

		dataGridView1->Rows->Add(50);
		char s1[2] = "A";
		dataGridView1->Columns[0]->Width = 60;
		for (int i = 1; i <= 50; i++)
		{
			dataGridView1->Columns->Add(gcnew String(s1), gcnew String(s1));
			dataGridView1->Columns[i]->Width = 60;
			dataGridView1->Rows[i - 1]->Cells[0]->Value = Convert::ToString(i);
			s1[0]++;
		}

		for (int i = 0; i < 50; i++)
			for (int z = 0; z <= 50; z++)
				table[i][z]->setValue(Convert::ToString(dataGridView1->Rows[i]->Cells[z]->Value));


		Initialized = 1;
	}

	private: System::Void MyForm_Resize(System::Object^  sender, System::EventArgs^  e) {
		dataGridView1->Width = Width + 1;
		dataGridView1->Height = Height - dataGridView1->Top;
		textBox1->Width=Width+1;
	}

	private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		int RowIndex = e->RowIndex;
		int CollumnIndex = e->ColumnIndex;
		dataGridView1->CurrentCell->Value = table[RowIndex][CollumnIndex]->getValue();
	}

private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void dataGridView1_CurrentCellChanged(System::Object^  sender, System::EventArgs^  e) {
	if (!Initialized) return;
	if (!dataGridView1->CurrentCell)
	{
		DeselectCell();
		return;
	}

	if (dataGridView1->CurrentCell->ColumnIndex == 0)
	{
		DeselectCell();
		textBox1->Text = "";
	}
	else
	{
		ChangeCurrentCell(dataGridView1->CurrentCell->RowIndex + 1, dataGridView1->CurrentCell->ColumnIndex);
		textBox1->Text = Convert::ToString(dataGridView1->CurrentCell->Value);
	}
}

private: System::Void dataGridView1_CellValueChanged(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	if (!Initialized) return;
	if (!dataGridView1->CurrentCell)
	{
		textBox1->Enabled = false;
		return;
	}
	if (dataGridView1->CurrentCell->ColumnIndex == 0)
	{
		textBox1->Enabled = false;
		textBox1->Text = "";
	}
	
	int RowIndex = dataGridView1->CurrentCell->RowIndex;
	int CollumnIndex = dataGridView1->CurrentCell->ColumnIndex;

	textBox1->Text = Convert::ToString(table[RowIndex][CollumnIndex]->getValue());

}

public: void SetText(String^ newString)
{
	textBox1->Text = gcnew String(newString);
	if (dataGridView1->CurrentCell->ColumnIndex != 0)
		dataGridView1->CurrentCell->Value = gcnew String(newString);
}

private: System::Void textBox1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
	if (e->KeyChar == (char)13) {
		int RowIndex = dataGridView1->CurrentCell->RowIndex;
		int CollumnIndex = dataGridView1->CurrentCell->ColumnIndex;
		UpdateText(textBox1->Text, RowIndex, CollumnIndex);
		textBox1->Text = Convert::ToString(table[RowIndex][CollumnIndex]->getValue());
	}
	
}
private: System::Void dataGridView1_CellEndEdit(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	int RowIndex = dataGridView1->CurrentCell->RowIndex;
	int CollumnIndex = dataGridView1->CurrentCell->ColumnIndex;
	UpdateText(Convert::ToString(dataGridView1->CurrentCell->Value), RowIndex, CollumnIndex);
}
};
}