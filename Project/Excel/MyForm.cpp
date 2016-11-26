#include "MyForm.h"
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <fstream>
#include <stdio.h>
#include <direct.h>
namespace Excel
{
	void MyForm::SaveLastFiles()
	{
		char* appdata = getenv("APPDATA");
		char SettingsFile[260];
		strcpy(SettingsFile, appdata);
		strcat(SettingsFile, "\\Excel");
		mkdir(SettingsFile);
		strcat(SettingsFile, "\\Settings.dat");
		try
		{
			Stream^ saveFile = gcnew FileStream(gcnew String(SettingsFile), System::IO::FileMode::Create);
			saveFile->Write(BitConverter::GetBytes(lastFilesNumber),0,sizeof(lastFilesNumber));
			for (int i=0;i<lastFilesNumber;i++)
			{
				int length = lastFiles[i]->Length;
				saveFile->Write(BitConverter::GetBytes(length), 0, sizeof(int));
				for (int k = 0; k < length; k++)
				{
					saveFile->WriteByte(lastFiles[i][k] >> 8);
					saveFile->WriteByte(lastFiles[i][k]);
				}
			}
		}
		catch(...)
		{
			
		}
	}
	void MyForm::LoadLastFiles()
	{
		char* appdata = getenv("APPDATA");
		char SettingsFile[260];
		strcpy(SettingsFile, appdata);
		strcat(SettingsFile, "\\Excel\\Settings.dat");
		try
		{
			Stream^ saveFile = gcnew FileStream(gcnew String(SettingsFile), System::IO::FileMode::Open);
			cli::array <unsigned char>^ temp = gcnew cli::array <unsigned char>(sizeof(int));
			saveFile->Read(temp, 0, sizeof(int));
			lastFilesNumber = BitConverter::ToInt32(temp, 0);
			lastFiles->Resize(lastFiles, lastFilesNumber);

			for (int i = 0; i<lastFilesNumber; i++)
			{
				saveFile->Read(temp, 0, sizeof(int));
				int length = BitConverter::ToInt32(temp, 0);
				wchar_t* str = new wchar_t[length + 1];
				for (int k = 0; k < length; k++)
				{
					wchar_t s1, s2;
					s1 = saveFile->ReadByte();
					s2 = saveFile->ReadByte();
					s2 = s2 + (s1 << 8);
					str[k] = s2;
				}
				str[length] = L'\0';
				lastFiles[i] = gcnew String(str);
			}

			if (lastFilesNumber>0)
			{
				latestToolStripMenuItem->DropDownItems[0]->Enabled = true;
			}

			for (int i = 1; i < lastFilesNumber;i++)
			{
				System::Windows::Forms::ToolStripMenuItem^ newItem = gcnew System::Windows::Forms::ToolStripMenuItem();
				newItem->Click += gcnew System::EventHandler(this, &MyForm::toolStripMenuItem2_Click);
				latestToolStripMenuItem->DropDownItems->Add(newItem);
			}

			int i = lastFilesNumber, j = 0;
			while (i > 0)
				latestToolStripMenuItem->DropDownItems[j++]->Text = lastFiles[--i];
		}
		catch (...)
		{

		}
	}
	void MyForm::UpdateLastFiles(String^ s)
	{
		int sIndex = -1;
		for (int i=0; i < lastFilesNumber; i++)
		{
			if (s->Equals(lastFiles[i]))
			{
				sIndex = i;
				break;
			}
		}
		if (sIndex==-1)
		{
			lastFiles->Resize(lastFiles, ++lastFilesNumber);
			lastFiles[lastFilesNumber - 1] = s;
			latestToolStripMenuItem->DropDownItems[0]->Enabled = true;
			if (lastFilesNumber != 1)
			{
				System::Windows::Forms::ToolStripMenuItem^ newItem = gcnew System::Windows::Forms::ToolStripMenuItem();
				newItem->Click += gcnew System::EventHandler(this, &MyForm::toolStripMenuItem2_Click);
				latestToolStripMenuItem->DropDownItems->Add(newItem);
			}
		}
		else
		{
			String^ temp=lastFiles[0];
			int i = sIndex;
			while (i<lastFilesNumber-1)
			{
				lastFiles[i] = lastFiles[i + 1];
				i++;
			}
			lastFiles[lastFilesNumber - 1] = s;
		}
		int i = lastFilesNumber, j = 0;
		while (i > 0)
			latestToolStripMenuItem->DropDownItems[j++]->Text = lastFiles[--i];
	}

	String^ MyForm::CollumnHeader(int a)
	{
		a--;
		int l = 1, a2 = a;
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

	wchar_t* MyForm::toStdWstring(String^ str) {
		wchar_t* s = new wchar_t[str->Length + 1];
		array <wchar_t>^ temp = str->ToCharArray();

		for (size_t i = 0; i < str->Length; i++)
			s[i] = temp[i];

		s[str->Length] = 0;
		return s;
	}

	void MyForm::DeleteTable()
	{
		dataGridView2->Columns->Remove(dataGridView2->Columns[0]);
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
	}
	void MyForm::CreateTable(int RowCount, int ColumnCount)
	{
		Initialized = 0;
		int rows = RowCount, cols = ColumnCount;
		table = gcnew Table(rows + 1, cols + 1);
		graph = gcnew Graph(rows + 1, cols + 1);
		dataGridView2->Columns->Add(" ", " ");
		dataGridView2->Rows->Add(rows);
		dataGridView2->Columns[0]->SortMode = DataGridViewColumnSortMode::NotSortable;
		dataGridView1->Columns->Add("", "");
		dataGridView1->Columns[0]->Visible = false;
		dataGridView1->Rows->Add(rows);
		char s1[2] = "A";
		dataGridView1->Columns[0]->Width = 60;
		dataGridView1->Columns[0]->SortMode = DataGridViewColumnSortMode::NotSortable;
		for (int i = 1; i <= cols; i++)
		{
			//dataGridView1->Columns->Add(gcnew String(s1), gcnew String(s1));
			dataGridView1->Columns->Add(CollumnHeader(i), CollumnHeader(i));
			dataGridView1->Columns[i]->SortMode = DataGridViewColumnSortMode::NotSortable;
			dataGridView1->Columns[i]->Width = 60;
			dataGridView2->Rows[i - 1]->Cells[0]->Value = Convert::ToString(i);
			dataGridView2->Rows[i - 1]->Cells[0]->ReadOnly = true;
			s1[0]++;
		}
		dataGridView2->ClearSelection();
		for (int i = 0; i < rows; i++)
			for (int z = 0; z <= cols; z++)
				table[i][z]->setValue(Convert::ToString(dataGridView1->Rows[i]->Cells[z]->Value));
		Initialized = 1;

	}
	void MyForm::ReCreateTable(int RowCount, int ColumnCount)
	{
		DeleteTable();
		CreateTable(RowCount, ColumnCount);
	}

	void MyForm::UpdateText(String^ newString, unsigned int RowIndex, unsigned int CollumnIndex)
	{
		label1->Text = "Processing...";
		label2->Text = "";
		clock_t begin = clock();

		if (newString == nullptr) {

			label1->Text = "Ready.";
			label2->Text = "Processed in " + (clock() - begin) / static_cast <double> (1000) + "s";

			return;
		}
		if (newString->Length == 0)
		{
			table[RowIndex][CollumnIndex]->setIsFormula(false);
			table[RowIndex][CollumnIndex]->setValue(newString);
			table[RowIndex][CollumnIndex]->setResult(0.0);

			label1->Text = "Ready.";
			label2->Text = "Processed in " + (clock() - begin) / static_cast <double> (1000) + "s";

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

		label1->Text = "Ready.";
		label2->Text = "Processed in " + (clock() - begin) / static_cast <double> (1000) + "s";
	}
	System::Void MyForm::MyForm_Closed(Object^ sender, EventArgs^ e) {
		SaveLastFiles();
	}
	System::Void MyForm::MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		label1->Text = "Ready.";
		label2->Text = "";
		CreateTable(startRows, startCols);
		dataGridView1->RowHeadersWidthSizeMode = DataGridViewRowHeadersWidthSizeMode::DisableResizing;
		dataGridView2->RowHeadersWidthSizeMode = DataGridViewRowHeadersWidthSizeMode::DisableResizing;
		dataGridView1->AllowUserToResizeRows = false;
		dataGridView2->AllowUserToResizeRows = false;
		LoadLastFiles();
	}

	System::Void MyForm::dataGridView1_CurrentCellChanged(System::Object^  sender, System::EventArgs^  e) {
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

	System::Void MyForm::dataGridView1_CellValueChanged(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
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

	System::Void MyForm::textBox1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		if (e->KeyChar == (char)13) {
			int RowIndex = dataGridView1->CurrentCell->RowIndex;
			int CollumnIndex = dataGridView1->CurrentCell->ColumnIndex;
			dataGridView1->CurrentCell->Value = textBox1->Text;
			UpdateText(textBox1->Text, RowIndex, CollumnIndex);
			textBox1->Text = Convert::ToString(table[RowIndex][CollumnIndex]->getValue());
		}
	}
	System::Void MyForm::dataGridView1_CellEndEdit(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		int RowIndex = dataGridView1->CurrentCell->RowIndex;
		int CollumnIndex = dataGridView1->CurrentCell->ColumnIndex;
		UpdateText(Convert::ToString(dataGridView1->CurrentCell->Value), RowIndex, CollumnIndex);
		textBox1->Text = table[RowIndex][CollumnIndex]->getValue();
	}
	System::Void MyForm::saveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
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
					saveFile->Write(BitConverter::GetBytes(ColumnCount - 1), 0, sizeof(int));
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
	System::Void MyForm::openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
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
					ReCreateTable(rows, cols);
					for (int i = 0; i < rows; i++)
						for (int z = 0; z <= cols; z++)
							table[i][z]->setValue(Convert::ToString(dataGridView1->Rows[i]->Cells[z]->Value));
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
	System::Void MyForm::dataGridView1_CellBeginEdit(System::Object^  sender, System::Windows::Forms::DataGridViewCellCancelEventArgs^  e) {
		int RowIndex = e->RowIndex;
		int CollumnIndex = e->ColumnIndex;
		dataGridView1->CurrentCell->Value = table[RowIndex][CollumnIndex]->getValue();
	}
	System::Void MyForm::newToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		Initialized = false;
		Excel::MyForm1^ form = gcnew Excel::MyForm1;
		form->ShowDialog();
		if (!form->good) return;
		int rows = form->getRows(), cols = form->getCols();
		ReCreateTable(rows, cols);
		for (int i = 0; i < rows; i++)
			for (int z = 0; z <= cols; z++)
				table[i][z]->setValue(Convert::ToString(dataGridView1->Rows[i]->Cells[z]->Value));
		textBox1->Width = Width + 1;
		Initialized = 1;
	}
	System::Void MyForm::aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		Excel::MyForm2^ form = gcnew Excel::MyForm2;
		form->ShowDialog();
	}
	System::Void MyForm::toolStripMenuItem2_Click(System::Object^  sender, System::EventArgs^  e) {
		Initialized = false;
		String^ FileName = ((System::Windows::Forms::ToolStripMenuItem^)sender)->Text;
		Stream^ saveFile;
		try
		{
			saveFile = gcnew FileStream(FileName, System::IO::FileMode::Open);
		}
		catch (...)
		{
			MessageBox::Show("Error Opening File", "Error");
		}
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
				ReCreateTable(rows, cols);
				for (int i = 0; i < rows; i++)
					for (int z = 0; z <= cols; z++)
						table[i][z]->setValue(Convert::ToString(dataGridView1->Rows[i]->Cells[z]->Value));
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
				UpdateLastFiles(((System::Windows::Forms::ToolStripMenuItem^)sender)->Text);
			}
			catch (...)
			{
				MessageBox::Show("Error Processing file", "Error");
			}
		}
		else
			MessageBox::Show("Error opening file", "Error");

	}
	System::Void MyForm::closeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		Close();
	}
	System::Void MyForm::functionsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		Excel::MyForm3^ form = gcnew Excel::MyForm3;
		form->ShowDialog();
	}
	System::Void MyForm::dataGridView2_CurrentCellChanged(System::Object^  sender, System::EventArgs^  e) {
		dataGridView2->ClearSelection();
	}
	System::Void MyForm::dataGridView1_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e) {
		dataGridView2->FirstDisplayedScrollingRowIndex = dataGridView1->FirstDisplayedScrollingRowIndex;
		dataGridView1->FirstDisplayedScrollingRowIndex = dataGridView1->FirstDisplayedScrollingRowIndex;
	}
}