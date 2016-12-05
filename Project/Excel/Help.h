#pragma once

namespace Excel {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Help
	/// </summary>
	public ref class Help : public System::Windows::Forms::Form
	{
	public:
		Help(void)
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
		~Help()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Help::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(19, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(212, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"To enter formula start it from \"=\" sign (=1+2)";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(19, 34);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(220, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"You can use arithmetical operations (+,-,*,/,^)";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(19, 47);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(149, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"You can use built-in functions:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(19, 60);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(203, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"sin,cos,tan,ctg,ln,exp,asin,aocs,atan,actg";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(19, 73);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(149, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"All angles should be in radians";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(19, 86);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(146, 13);
			this->label6->TabIndex = 5;
			this->label6->Text = L"You can reference other cells";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(19, 99);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(213, 13);
			this->label7->TabIndex = 6;
			this->label7->Text = L"To do it use $Cell_Column$Cel_Row ($A$1)";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(19, 112);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(142, 13);
			this->label8->TabIndex = 7;
			this->label8->Text = L"You can save and open files";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(19, 125);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(127, 13);
			this->label9->TabIndex = 8;
			this->label9->Text = L"Max table size = 500x500";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(19, 169);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(186, 13);
			this->label10->TabIndex = 9;
			this->label10->Text = L"Khuda, Bulatov && Zarichkoviy © 2016";
			// 
			// Help
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(257, 194);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Help";
			this->Text = L"Help";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
