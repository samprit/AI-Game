#pragma once

namespace game {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for InputMultiPlayerNames
	/// </summary>
	public ref class InputMultiPlayerNames : public System::Windows::Forms::Form
	{
	public:
		InputMultiPlayerNames(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->player1Name->Text = " ";
			this->player2Name->Text = " ";
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~InputMultiPlayerNames()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  OkButton;
	protected: 

	private: System::Windows::Forms::Button^  CancelButton;
	protected: 

	protected: 

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	public: System::Windows::Forms::TextBox^  player1Name;
	private: 
	public: System::Windows::Forms::TextBox^  player2Name;





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
			this->OkButton = (gcnew System::Windows::Forms::Button());
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->player1Name = (gcnew System::Windows::Forms::TextBox());
			this->player2Name = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// OkButton
			// 
			this->OkButton->Location = System::Drawing::Point(79, 142);
			this->OkButton->Name = L"OkButton";
			this->OkButton->Size = System::Drawing::Size(75, 27);
			this->OkButton->TabIndex = 0;
			this->OkButton->Text = L"OK";
			this->OkButton->UseVisualStyleBackColor = true;
			this->OkButton->Click += gcnew System::EventHandler(this, &InputMultiPlayerNames::OkButton_Click);
			// 
			// CancelButton
			// 
			this->CancelButton->Location = System::Drawing::Point(201, 142);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(75, 27);
			this->CancelButton->TabIndex = 1;
			this->CancelButton->Text = L"CANCEL";
			this->CancelButton->UseVisualStyleBackColor = true;
			this->CancelButton->Click += gcnew System::EventHandler(this, &InputMultiPlayerNames::CancelButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(41, 39);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(73, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Player1 Name";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(41, 88);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(73, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Player2 Name";
			// 
			// player1Name
			// 
			this->player1Name->Location = System::Drawing::Point(190, 36);
			this->player1Name->Name = L"player1Name";
			this->player1Name->Size = System::Drawing::Size(105, 20);
			this->player1Name->TabIndex = 4;
			// 
			// player2Name
			// 
			this->player2Name->Location = System::Drawing::Point(190, 85);
			this->player2Name->Name = L"player2Name";
			this->player2Name->Size = System::Drawing::Size(105, 20);
			this->player2Name->TabIndex = 5;
			// 
			// InputMultiPlayerNames
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(372, 192);
			this->Controls->Add(this->player2Name);
			this->Controls->Add(this->player1Name);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->CancelButton);
			this->Controls->Add(this->OkButton);
			this->Name = L"InputMultiPlayerNames";
			this->Text = L"InputMultiPlayerNames";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void OkButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 if(this->player1Name->Text == " " || this->player2Name->Text == " "){
					 MessageBox::Show("No Name Entered",
						 "Error!!", MessageBoxButtons::OKCancel,
						 MessageBoxIcon::Asterisk);
					 return;
				 }
				 this->DialogResult = Windows::Forms::DialogResult::OK;
				 this->Close();
			 }
private: System::Void CancelButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->DialogResult = Windows::Forms::DialogResult::Cancel;
			 this->Close();
		 }
};
}
