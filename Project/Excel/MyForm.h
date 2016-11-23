#pragma once
#include "Table.h"
#include "Parser.h"
#include "Graph.h"
#include "MyForm1.h"
#include "MyForm2.h"
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

	private: Table^ table;
	private: Graph^ graph;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  newToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  latestToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem2;










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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->latestToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->dataGridView1->Location = System::Drawing::Point(0, 53);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(153, 68);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellBeginEdit += gcnew System::Windows::Forms::DataGridViewCellCancelEventHandler(this, &MyForm::dataGridView1_CellBeginEdit);
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			this->dataGridView1->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellEndEdit);
			this->dataGridView1->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellValueChanged);
			this->dataGridView1->CurrentCellChanged += gcnew System::EventHandler(this, &MyForm::dataGridView1_CurrentCellChanged);
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(0, 27);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(153, 20);
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
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->newToolStripMenuItem,
					this->openToolStripMenuItem, this->saveToolStripMenuItem, this->latestToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// newToolStripMenuItem
			// 
			this->newToolStripMenuItem->Name = L"newToolStripMenuItem";
			this->newToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->newToolStripMenuItem->Text = L"New";
			this->newToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::newToolStripMenuItem_Click);
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::openToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->saveToolStripMenuItem->Text = L"Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::saveToolStripMenuItem_Click);
			// 
			// latestToolStripMenuItem
			// 
			this->latestToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripMenuItem2 });
			this->latestToolStripMenuItem->Name = L"latestToolStripMenuItem";
			this->latestToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->latestToolStripMenuItem->Text = L"Latest";
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Enabled = false;
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(152, 22);
			this->toolStripMenuItem2->Text = L"No files";
			this->toolStripMenuItem2->Click += gcnew System::EventHandler(this, &MyForm::toolStripMenuItem2_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->aboutToolStripMenuItem });
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::aboutToolStripMenuItem_Click);
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
		array <String^>^ lastFiles;
		int lastFilesNumber = 0;

		void UpdateLastFiles(String^ s)
		{
			//lastFiles = gcnew array <String^>(++lastFilesNumber);
			lastFiles->Resize(lastFiles,++lastFilesNumber);
			lastFiles[lastFilesNumber - 1] = s;
			latestToolStripMenuItem->DropDownItems[0]->Enabled = true;
			if (lastFilesNumber != 1)
			{
				System::Windows::Forms::ToolStripMenuItem^ newItem = gcnew System::Windows::Forms::ToolStripMenuItem();
				newItem->Click += gcnew System::EventHandler(this, &MyForm::toolStripMenuItem2_Click);
				latestToolStripMenuItem->DropDownItems->Add(newItem);
			}
			int i = lastFilesNumber, j = 0;
			while (i>0)
			latestToolStripMenuItem->DropDownItems[j++]->Text = lastFiles[--i];

		}

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

				graph->changeGraph(table, dataGridView1, RowIndex, CollumnIndex);
				dataGridView1->Rows[RowIndex]->Cells[CollumnIndex]->Value = Convert::ToString(table[RowIndex][CollumnIndex]->getResult());
			}
			catch (char* str) {
				table[RowIndex][CollumnIndex]->setIsFormula(false);
				graph->changeGraph(table, dataGridView1, RowIndex, CollumnIndex);

				String^ temp = gcnew String(str);
				dataGridView1->Rows[RowIndex]->Cells[CollumnIndex]->Value = temp;
			}
			catch (int value) {
				table[RowIndex][CollumnIndex]->setIsFormula(false);
				graph->changeGraph(table, dataGridView1, RowIndex, CollumnIndex);
			}

			delete[] value;
			table[RowIndex][CollumnIndex]->setValue(newString);
		}

		bool Initialized = 0;

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		int rows=50, cols=50;
		table = gcnew Table(rows + 1, cols + 1);
		graph = gcnew Graph(rows + 1, cols + 1);

		dataGridView1->Columns->Add("", "");
		dataGridView1->Rows->Add(rows);
		char s1[2] = "A";
		dataGridView1->Columns[0]->Width = 60;
		for (int i = 1; i <= cols; i++)
		{
			//dataGridView1->Columns->Add(gcnew String(s1), gcnew String(s1));
			dataGridView1->Columns->Add(CollumnHeader(i), CollumnHeader(i));
			dataGridView1->Columns[i]->Width = 60;
			dataGridView1->Rows[i - 1]->Cells[0]->Value = Convert::ToString(i);
			dataGridView1->Rows[i - 1]->Cells[0]->ReadOnly = true;
			s1[0]++;
		}

		for (int i = 0; i < rows; i++)
			for (int z = 0; z <= cols; z++)
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
	if (!Initialized) return;

	int RowIndex = dataGridView1->CurrentCell->RowIndex;
	int CollumnIndex = dataGridView1->CurrentCell->ColumnIndex;
	try
	{
		textBox1->Text = table[RowIndex][CollumnIndex]->getValue();
	}
	catch (...)
	{
		textBox1->Text = "";
	}
	if (!dataGridView1->CurrentCell)
	{
		textBox1->Enabled = false;
		textBox1->Text = "";
		DeselectCell();
		return;
	}
	if (dataGridView1->CurrentCell->ColumnIndex == 0)
	{
		textBox1->Enabled = false;
		textBox1->Text = "";
		DeselectCell();
		return;
	}
	textBox1->Enabled = true;
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
	textBox1->Text = table[RowIndex][CollumnIndex]->getValue();
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
				int RowCount = dataGridView1->Rows->Count;
				int ColumnCount = dataGridView1->Columns->Count;
				saveFile->Write(BitConverter::GetBytes(RowCount), 0, sizeof(int));
				saveFile->Write(BitConverter::GetBytes(ColumnCount-1), 0, sizeof(int));
				for (int i = 0; i < RowCount; i++)
					for (int j = 1; j < ColumnCount; j++)
					{
						Cell^ cell = table[i][j];
						String^ str = cell->getValue();
						int length = str->Length;
						saveFile->Write(BitConverter::GetBytes(length), 0, sizeof(int));
						for (int k = 0; k < length; k++)
						{
							saveFile->WriteByte(str[k] >> 8);
							saveFile->WriteByte(str[k]);
						}
					}
				saveFile->Close();
				UpdateLastFiles(saveFileDialog1.FileName);
			}
			catch (...)
			{
				MessageBox::Show("Error Processing file", "Error");
			}
		}
		else
			MessageBox::Show("Error opening file", "Error");
	}
}
	private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		Initialized = false;
		OpenFileDialog openFileDialog1;
		openFileDialog1.Filter = "Table file (*.adc)|*.adc";
		if (openFileDialog1.ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			Stream^ saveFile = openFileDialog1.OpenFile();
			if (saveFile != nullptr)
			{
				try
				{
					cli::array <unsigned char>^ temp = gcnew cli::array <unsigned char>(sizeof(int));
					saveFile->Read(temp, 0, sizeof(int));
					int RowCount = BitConverter::ToInt32(temp, 0);
					saveFile->Read(temp, 0, sizeof(int));
					int ColumnCount = BitConverter::ToInt32(temp, 0);
					int rows = RowCount, cols = ColumnCount;
					int cnt1 = dataGridView1->Columns->Count;
					for (int i = 0; i < cnt1; i++)
					{
						dataGridView1->Columns->Remove(dataGridView1->Columns[0]);
					}
					int cnt2 = dataGridView1->Rows->Count;
					for (int i = 0; i < cnt2; i++)
					{
						dataGridView1->Rows->Remove(dataGridView1->Rows[0]);
					}
					table = gcnew Table(rows + 1, cols + 1);
					graph = gcnew Graph(rows + 1, cols + 1);
					dataGridView1->Columns->Add("", "");
					dataGridView1->Rows->Add(rows);
					dataGridView1->Columns[0]->Width = 60;
					char s1[2] = "A";
					for (int i = 1; i <= cols; i++)
					{
						//dataGridView1->Columns->Add(gcnew String(s1), gcnew String(s1));
						dataGridView1->Columns->Add(CollumnHeader(i), CollumnHeader(i));
						dataGridView1->Columns[i]->Width = 60;
						dataGridView1->Rows[i - 1]->Cells[0]->Value = Convert::ToString(i);
						dataGridView1->Rows[i - 1]->Cells[0]->ReadOnly = true;
						s1[0]++;
					}
					for (int i = 0; i < rows; i++)
						for (int z = 0; z <= cols; z++)
							table[i][z]->setValue(Convert::ToString(dataGridView1->Rows[i]->Cells[z]->Value));
					dataGridView1->Width = Width + 1;
					dataGridView1->Height = Height - dataGridView1->Top;
					textBox1->Width = Width + 1;
					Initialized = 1;
					for (int i = 0; i < RowCount; i++)
						for (int j = 1; j <= ColumnCount; j++)
						{
							saveFile->Read(temp, 0, sizeof(int));
							int length = BitConverter::ToInt32(temp, 0);
							wchar_t* str = new wchar_t[length+1];
							for (int k = 0; k < length; k++)
							{
								//saveFile->Read(temp, 0, sizeof(wchar_t));
								wchar_t s1,s2;
								s1 = saveFile->ReadByte();
								s2 = saveFile->ReadByte();
								s2 = s2 + (s1 << 8);
								str[k] = s2;
							}
							str[length] = L'\0';
							String^ newString = gcnew String(str);
							dataGridView1->Rows[i]->Cells[j]->Value = newString;
							try
							{
								UpdateText(newString, i, j);
							}
							catch(...)
							{
								
							}
							delete[] str;
						}
					saveFile->Close();
					UpdateLastFiles(openFileDialog1.FileName);
				}
				catch (...)
				{
					MessageBox::Show("Error Processing file", "Error");
				}
			}
			else
				MessageBox::Show("Error opening file", "Error");

		}
	}
private: System::Void dataGridView1_CellBeginEdit(System::Object^  sender, System::Windows::Forms::DataGridViewCellCancelEventArgs^  e) {
}
private: System::Void newToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	Initialized = false;
	Excel::MyForm1^ form = gcnew Excel::MyForm1;
	form->ShowDialog();
	if (!form->good) return;
	//Application::Run(form);
	int rows = form->getRows(), cols = form->getCols();
	int cnt1 = dataGridView1->Columns->Count;
	for (int i = 0; i < cnt1; i++)
	{
		dataGridView1->Columns->Remove(dataGridView1->Columns[0]);
	}
	int cnt2 = dataGridView1->Rows->Count;
	for (int i = 0; i < cnt2; i++)
	{
		dataGridView1->Rows->Remove(dataGridView1->Rows[0]);
	}
	table = gcnew Table(rows + 1, cols + 1);
	graph = gcnew Graph(rows + 1, cols + 1);
	dataGridView1->Columns->Add("", "");
	dataGridView1->Rows->Add(rows);
	dataGridView1->Columns[0]->Width = 60;
	char s1[2] = "A";
	for (int i = 1; i <= cols; i++)
	{
		//dataGridView1->Columns->Add(gcnew String(s1), gcnew String(s1));
		dataGridView1->Columns->Add(CollumnHeader(i), CollumnHeader(i));
		dataGridView1->Columns[i]->Width = 60;
		dataGridView1->Rows[i - 1]->Cells[0]->Value = Convert::ToString(i);
		dataGridView1->Rows[i - 1]->Cells[0]->ReadOnly = true;
		s1[0]++;
	}
	for (int i = 0; i < rows; i++)
		for (int z = 0; z <= cols; z++)
			table[i][z]->setValue(Convert::ToString(dataGridView1->Rows[i]->Cells[z]->Value));
	dataGridView1->Width = Width + 1;
	dataGridView1->Height = Height - dataGridView1->Top;
	textBox1->Width = Width + 1;
	Initialized = 1;
}
private: System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	Excel::MyForm2^ form = gcnew Excel::MyForm2;
	form->ShowDialog();
}
private: System::Void toolStripMenuItem2_Click(System::Object^  sender, System::EventArgs^  e) {
	Initialized = false;
	String^ FileName = ((System::Windows::Forms::ToolStripMenuItem^)sender)->Text;
	Stream^ saveFile = gcnew FileStream(FileName, System::IO::FileMode::Open);
	if (saveFile != nullptr)
	{
		try
		{
			cli::array <unsigned char>^ temp = gcnew cli::array <unsigned char>(sizeof(int));
			saveFile->Read(temp, 0, sizeof(int));
			int RowCount = BitConverter::ToInt32(temp, 0);
			saveFile->Read(temp, 0, sizeof(int));
			int ColumnCount = BitConverter::ToInt32(temp, 0);
			int rows = RowCount, cols = ColumnCount;
			int cnt1 = dataGridView1->Columns->Count;
			for (int i = 0; i < cnt1; i++)
			{
				dataGridView1->Columns->Remove(dataGridView1->Columns[0]);
			}
			int cnt2 = dataGridView1->Rows->Count;
			for (int i = 0; i < cnt2; i++)
			{
				dataGridView1->Rows->Remove(dataGridView1->Rows[0]);
			}
			table = gcnew Table(rows + 1, cols + 1);
			graph = gcnew Graph(rows + 1, cols + 1);
			dataGridView1->Columns->Add("", "");
			dataGridView1->Rows->Add(rows);
			dataGridView1->Columns[0]->Width = 60;
			char s1[2] = "A";
			for (int i = 1; i <= cols; i++)
			{
				//dataGridView1->Columns->Add(gcnew String(s1), gcnew String(s1));
				dataGridView1->Columns->Add(CollumnHeader(i), CollumnHeader(i));
				dataGridView1->Columns[i]->Width = 60;
				dataGridView1->Rows[i - 1]->Cells[0]->Value = Convert::ToString(i);
				dataGridView1->Rows[i - 1]->Cells[0]->ReadOnly = true;
				s1[0]++;
			}
			for (int i = 0; i < rows; i++)
				for (int z = 0; z <= cols; z++)
					table[i][z]->setValue(Convert::ToString(dataGridView1->Rows[i]->Cells[z]->Value));
			dataGridView1->Width = Width + 1;
			dataGridView1->Height = Height - dataGridView1->Top;
			textBox1->Width = Width + 1;
			Initialized = 1;
			for (int i = 0; i < RowCount; i++)
				for (int j = 1; j <= ColumnCount; j++)
				{
					saveFile->Read(temp, 0, sizeof(int));
					int length = BitConverter::ToInt32(temp, 0);
					wchar_t* str = new wchar_t[length + 1];
					for (int k = 0; k < length; k++)
					{
						//saveFile->Read(temp, 0, sizeof(wchar_t));
						wchar_t s1, s2;
						s1 = saveFile->ReadByte();
						s2 = saveFile->ReadByte();
						s2 = s2 + (s1 << 8);
						str[k] = s2;
					}
					str[length] = L'\0';
					String^ newString = gcnew String(str);
					dataGridView1->Rows[i]->Cells[j]->Value = newString;
					try
					{
						UpdateText(newString, i, j);
					}
					catch (...)
					{

					}
					delete[] str;
				}
			saveFile->Close();
		}
		catch (...)
		{
			MessageBox::Show("Error Processing file", "Error");
		}
	}
	else
		MessageBox::Show("Error opening file", "Error");

}
};
};