#pragma once
#include <string>
/*
#include <fstream>
#include <iostream>
#include <sstream>
#include <string.h>
*/
//using namespace std;

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::IO;
	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  _no;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  _surname;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  _name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  _pobatkovi;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  _year;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  _area;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  _street;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  _buidingNo;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  _flatNo;
	private: System::Windows::Forms::Button^  button2;
















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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->_no = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->_surname = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->_name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->_pobatkovi = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->_year = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->_area = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->_street = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->_buidingNo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->_flatNo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(788, 346);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Close";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(9) {
				this->_no, this->_surname,
					this->_name, this->_pobatkovi, this->_year, this->_area, this->_street, this->_buidingNo, this->_flatNo
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(851, 239);
			this->dataGridView1->TabIndex = 1;
			// 
			// _no
			// 
			this->_no->HeaderText = L"No";
			this->_no->Name = L"_no";
			this->_no->Width = 50;
			// 
			// _surname
			// 
			this->_surname->HeaderText = L"Surname";
			this->_surname->Name = L"_surname";
			// 
			// _name
			// 
			this->_name->HeaderText = L"Name";
			this->_name->Name = L"_name";
			// 
			// _pobatkovi
			// 
			this->_pobatkovi->HeaderText = L"Pobatkovi";
			this->_pobatkovi->Name = L"_pobatkovi";
			// 
			// _year
			// 
			this->_year->HeaderText = L"Year";
			this->_year->Name = L"_year";
			// 
			// _area
			// 
			this->_area->HeaderText = L"Area";
			this->_area->Name = L"_area";
			this->_area->Width = 50;
			// 
			// _street
			// 
			this->_street->HeaderText = L"Street";
			this->_street->Name = L"_street";
			// 
			// _buidingNo
			// 
			this->_buidingNo->HeaderText = L"BuidingNo";
			this->_buidingNo->Name = L"_buidingNo";
			// 
			// _flatNo
			// 
			this->_flatNo->HeaderText = L"FlatNo";
			this->_flatNo->Name = L"_flatNo";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 257);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Load";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(875, 381);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button1);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
	
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	StreamReader^ sr = gcnew StreamReader("src.txt");
	while (sr->Peek() >= 0)
	{
		String^ row = sr->ReadLine();
		Object cells;
		cells = row.Split(";");
		dataGridView1->Rows->Add(cells);
	}
	sr->Close();
	/*
	std::istream infile;
	infile.open("src.txt", std::ifstream::in);
	std::string teml;
	if (infile.is_open())
	{
		while (infile.good())
		{
			infile.getline(teml, 256, ';');
			//dataGridView1->Rows[1]->Cells[0]->Value = teml;
			//i++;
		}
		infile.close();
	}*/

}
};
}
