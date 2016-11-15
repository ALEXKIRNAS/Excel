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
			this->dataGridView1->Location = System::Drawing::Point(-1, 60);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(718, 268);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
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
			this->textBox1->Location = System::Drawing::Point(-1, 34);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(718, 20);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(716, 327);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->dataGridView1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"Excel";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
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

		for (int i = 1; i < 50; i++)
			for (int z = 1; z <= 50; z++)
				table[i][z]->change(Convert::ToString(dataGridView1->Rows[i]->Cells[z]->Value));

		String^ str = gcnew String("2 + 3 * $B$10 + sin($B$2 - 10.01)");
		char* s=new char[str->Length+1];
		array <wchar_t>^ temp = str->ToCharArray();
		for (size_t i = 0; i < str->Length; i++)
		{
			s[i]=temp[i];
		}
		s[str->Length] = 0;
		parse(s, table);
		delete[] s;
		Initialized = 1;
	}
	private: System::Void MyForm_Resize(System::Object^  sender, System::EventArgs^  e) {
		dataGridView1->Width = Width + 1;
		dataGridView1->Height = Height - dataGridView1->Top;
		textBox1->Width=Width+1;
	}
	private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	}
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	UpdateText(textBox1->Text);
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
	}
	else
	{
		ChangeCurrentCell(dataGridView1->CurrentCell->RowIndex + 1, dataGridView1->CurrentCell->ColumnIndex);
	}
}
private: System::Void dataGridView1_CellValueChanged(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	if (!Initialized) return;
	UpdateText(Convert::ToString(dataGridView1->CurrentCell->Value));

}
public: void SetText(String^ newString)
{
	textBox1->Text = gcnew String(newString);
	if (dataGridView1->CurrentCell->ColumnIndex != 0)
		dataGridView1->CurrentCell->Value = gcnew String(newString);
}
};
}
