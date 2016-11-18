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
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Text;
	using namespace System::Drawing;
	using namespace System::IO;

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
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;








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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->menuStrip1->SuspendLayout();
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
			this->dataGridView1->Size = System::Drawing::Size(153, 68);
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
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(-1, 34);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(63, 20);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox1_KeyPress);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fileToolStripMenuItem,
					this->helpToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(716, 24);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->openToolStripMenuItem,
					this->saveToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->aboutToolStripMenuItem });
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->openToolStripMenuItem->Text = L"Open";
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->saveToolStripMenuItem->Text = L"Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::saveToolStripMenuItem_Click);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(716, 327);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"Excel";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		/*  Convert System::String to std::wstring
		*/
		unsigned int lastRowIndex=0, lastCollumnIndex = 0;

		String^ CollumnHeader(int a)
		{
			a--;
			int l = 1,a2=a;
			while (a2 /= 26) l++;
			char* temp = new char[l + 1];
			temp[l] = '\0';
			for (int i = l - 1; i >= 0; i--)
			{
				temp[i] = 'A' + a % 26;
				a /= 26;
				a--;
			}
			String^ t = gcnew String(temp);
			delete[] temp;
			return t;
		}

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
		}

		void UpdateText(String^ newString, unsigned int RowIndex, unsigned int CollumnIndex)
		{
			if (newString == nullptr) return;
			if (newString->Length == 0)
			{
				table[RowIndex][CollumnIndex]->setIsFormula(false);
				table[RowIndex][CollumnIndex]->setValue(newString);
				table[RowIndex][CollumnIndex]->setResult(0.0);
				return;
			}

			wchar_t* value = toStdWstring(newString);

			try {
				table[RowIndex][CollumnIndex]->setResult(Parser::parse(wstring(value), table));
				table[RowIndex][CollumnIndex]->setIsFormula(true);
				dataGridView1->Rows[RowIndex]->Cells[CollumnIndex]->Value = Convert::ToString(table[RowIndex][CollumnIndex]->getResult());
			}
			catch (char* str) {
				String^ temp = gcnew String(str);
				dataGridView1->Rows[RowIndex]->Cells[CollumnIndex]->Value = temp;
				table[RowIndex][CollumnIndex]->setIsFormula(false);
			}
			catch (int value) {
				table[RowIndex][CollumnIndex]->setIsFormula(false);
			}

			delete[] value;

			table[RowIndex][CollumnIndex]->setValue(newString);
		}

		bool Initialized = 0;

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		table = gcnew Table(150 + 1, 150 + 1);

		dataGridView1->Rows->Add(150);
		char s1[2] = "A";
		dataGridView1->Columns[0]->Width = 60;
		for (int i = 1; i <= 150; i++)
		{
			//dataGridView1->Columns->Add(gcnew String(s1), gcnew String(s1));
			dataGridView1->Columns->Add(CollumnHeader(i), CollumnHeader(i));
			dataGridView1->Columns[i]->Width = 60;
			dataGridView1->Rows[i - 1]->Cells[0]->Value = Convert::ToString(i);
			dataGridView1->Rows[i - 1]->Cells[0]->ReadOnly = true;
			s1[0]++;
		}

		for (int i = 0; i < 150; i++)
			for (int z = 0; z <= 150; z++)
				table[i][z]->setValue(Convert::ToString(dataGridView1->Rows[i]->Cells[z]->Value));
		dataGridView1->Width = Width + 1;
		dataGridView1->Height = Height - dataGridView1->Top;
		textBox1->Width = Width + 1;
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
	/*if (!Initialized) return;
	UpdateText(textBox1->Text, lastRowIndex, lastCollumnIndex);
	lastRowIndex = dataGridView1->CurrentCell->RowIndex;
	lastCollumnIndex = dataGridView1->CurrentCell->ColumnIndex;

	if (!dataGridView1->CurrentCell)
	{
		textBox1->Enabled = false;
		DeselectCell();
		return;
	}

	if (dataGridView1->CurrentCell->ColumnIndex == 0)
	{
		textBox1->Enabled = false;
		DeselectCell();
		textBox1->Text = "";
	}
	else
	{
		textBox1->Enabled = true;
		ChangeCurrentCell(dataGridView1->CurrentCell->RowIndex + 1, dataGridView1->CurrentCell->ColumnIndex);
		textBox1->Text = Convert::ToString(dataGridView1->CurrentCell->Value);
	}

	int RowIndex = dataGridView1->CurrentCell->RowIndex;
	int CollumnIndex = dataGridView1->CurrentCell->ColumnIndex;
	if (table[RowIndex][CollumnIndex]->getValue()->Length!=0)
	dataGridView1->CurrentCell->Value = table[RowIndex][CollumnIndex]->getValue();
	*/
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
	//textBox1->Text = Convert::ToString(table[RowIndex][CollumnIndex]->getValue());
	textBox1->Text = Convert::ToString(dataGridView1->Rows[RowIndex]->Cells[CollumnIndex]->Value);

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
private: System::Void saveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	SaveFileDialog saveFileDialog1;
	saveFileDialog1.Filter = "Table file (*.adc)|*.adc";
	if (saveFileDialog1.ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		Stream^ saveFile = saveFileDialog1.OpenFile();
		if (saveFile != nullptr)
		{
			try 
			{
				UnicodeEncoding unicodeEncoding;
				int RowCount = dataGridView1->Rows->Count;
				int ColumnCount = dataGridView1->Columns->Count;
				saveFile->Write(BitConverter::GetBytes(RowCount), 0, sizeof(int));
				saveFile->Write(BitConverter::GetBytes(ColumnCount), 0, sizeof(int));
				for (int i = 0; i < RowCount; i++)
					for (int j = 0; j < ColumnCount; j++)
					{
						array <unsigned char>^ temp = unicodeEncoding.GetBytes(Convert::ToString(dataGridView1->Rows[i]->Cells[j]->Value));
						saveFile->Write(temp,0,temp->Length);
					}
			}
			catch (...)
			{
				MessageBox::Show("Processing file", "Error");
			}
		}
		else
			MessageBox::Show("Error opening file", "Error");
	}
}
};
};