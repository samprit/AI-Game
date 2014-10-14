#pragma once
#include "Form1.h"
#include "resource.h"
#include "InputMultiPlayerNames.h"
#include "InputComputerPlayType.h"
#include "InputSinglePlayer.h"
#include <string>
#include <msclr/marshal_cppstd.h>

namespace game {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for start
	/// </summary>
	public ref class start : public System::Windows::Forms::Form
	{
	public:
		start(void)
		{
			InitializeComponent();
			ManualInitialization();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~start()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  SinglePlayer;
	private: System::Windows::Forms::Button^  MultiPlayer;
	private: System::Windows::Forms::Button^  ComputerPlay;
	private: System::Windows::Forms::Button^  Browse;
	private: System::Windows::Forms::Label^  File;


	private: System::Windows::Forms::Button^  InstrButton;

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
			this->SinglePlayer = (gcnew System::Windows::Forms::Button());
			this->MultiPlayer = (gcnew System::Windows::Forms::Button());
			this->ComputerPlay = (gcnew System::Windows::Forms::Button());
			this->Browse = (gcnew System::Windows::Forms::Button());
			this->File = (gcnew System::Windows::Forms::Label());
			this->InstrButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// SinglePlayer
			// 
			this->SinglePlayer->Location = System::Drawing::Point(55, 64);
			this->SinglePlayer->Name = L"SinglePlayer";
			this->SinglePlayer->Size = System::Drawing::Size(99, 30);
			this->SinglePlayer->TabIndex = 3;
			this->SinglePlayer->Text = L"Single Player";
			this->SinglePlayer->UseVisualStyleBackColor = true;
			this->SinglePlayer->Click += gcnew System::EventHandler(this, &start::SinglePlayer_Click);
			// 
			// MultiPlayer
			// 
			this->MultiPlayer->Location = System::Drawing::Point(55, 160);
			this->MultiPlayer->Name = L"MultiPlayer";
			this->MultiPlayer->Size = System::Drawing::Size(99, 30);
			this->MultiPlayer->TabIndex = 5;
			this->MultiPlayer->Text = L"Multiplayer";
			this->MultiPlayer->UseVisualStyleBackColor = true;
			this->MultiPlayer->Click += gcnew System::EventHandler(this, &start::MultiPlayer_Click);
			// 
			// ComputerPlay
			// 
			this->ComputerPlay->Location = System::Drawing::Point(268, 64);
			this->ComputerPlay->Name = L"ComputerPlay";
			this->ComputerPlay->Size = System::Drawing::Size(99, 30);
			this->ComputerPlay->TabIndex = 6;
			this->ComputerPlay->Text = L"ComputerPlay";
			this->ComputerPlay->UseVisualStyleBackColor = true;
			this->ComputerPlay->Click += gcnew System::EventHandler(this, &start::ComputerPlay_Click);
			// 
			// Browse
			// 
			this->Browse->Location = System::Drawing::Point(268, 261);
			this->Browse->Name = L"Browse";
			this->Browse->Size = System::Drawing::Size(105, 28);
			this->Browse->TabIndex = 7;
			this->Browse->Text = L"Browse";
			this->Browse->UseVisualStyleBackColor = true;
			this->Browse->Click += gcnew System::EventHandler(this, &start::Browse_Click);
			// 
			// File
			// 
			this->File->AutoSize = true;
			this->File->ForeColor = System::Drawing::Color::Red;
			this->File->Location = System::Drawing::Point(63, 269);
			this->File->Name = L"File";
			this->File->Size = System::Drawing::Size(82, 13);
			this->File->TabIndex = 8;
			this->File->Text = L"File Not Loaded";
			// 
			// InstrButton
			// 
			this->InstrButton->Location = System::Drawing::Point(268, 160);
			this->InstrButton->Name = L"InstrButton";
			this->InstrButton->Size = System::Drawing::Size(99, 30);
			this->InstrButton->TabIndex = 11;
			this->InstrButton->Text = L"Instructions";
			this->InstrButton->UseVisualStyleBackColor = true;
			// 
			// start
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(440, 318);
			this->Controls->Add(this->InstrButton);
			this->Controls->Add(this->File);
			this->Controls->Add(this->Browse);
			this->Controls->Add(this->ComputerPlay);
			this->Controls->Add(this->MultiPlayer);
			this->Controls->Add(this->SinglePlayer);
			this->Name = L"start";
			this->Text = L"start";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public: String^ fileName;

			/// <summary>
			/// Initialize the required variables, buttons
			/// </summary>
	private: void ManualInitialization(){
				 fileName = gcnew String("null");
			 }

			 /// <summary>
			 /// Single Player Button Click Action
			 /// </summary>
	private: System::Void SinglePlayer_Click(System::Object^  sender, System::EventArgs^  e) {

				 String^ tempFile = fileName;

				 if(tempFile == "null"){
					 MessageBox::Show("No File Selected",
						 "Error Loading File", MessageBoxButtons::OKCancel,
						 MessageBoxIcon::Asterisk);
					 return;
				 }

				 // Displays the dialog
				 InputSinglePlayer^ openDialog = gcnew InputSinglePlayer();

				 if ( openDialog->ShowDialog( this ) == Windows::Forms::DialogResult::OK ){

					 std::string sendFileName=msclr::interop::marshal_as< std::string >(tempFile);
					 start::Hide();
					 Form1 ^play = gcnew Form1();
					 play->player1Name = openDialog->Player1Name->Text;
					 play->player2Name = openDialog->Player2Type->Text;
					 play->startButton->Enabled = FALSE;
					 play->player1Type = 2;
					 play->player2Type = (play->player2Name == "MiniMax")?0:1;
					 play->gameType = 0;
					 play->initialize_Squares(sendFileName);
					 play->ShowDialog();
					 start::Show();
				 }

			 }

			 /// <summary>
			 /// MultiPlayer Button Click Action
			 /// </summary>
	private: System::Void MultiPlayer_Click(System::Object^  sender, System::EventArgs^  e) {

				 String^ tempFile = fileName;

				 if(tempFile == "null"){
					 MessageBox::Show("No File Selected",
						 "Error Loading File", MessageBoxButtons::OKCancel,
						 MessageBoxIcon::Asterisk);
					 return;
				 }

				 // Displays the dialog
				 InputMultiPlayerNames^ openDialog = gcnew InputMultiPlayerNames();

				 if ( openDialog->ShowDialog( this ) == Windows::Forms::DialogResult::OK ){

					 std::string sendFileName=msclr::interop::marshal_as< std::string >(tempFile);
					 start::Hide();
					 Form1 ^play = gcnew Form1();
					 play->player1Name = openDialog->player1Name->Text;
					 play->player2Name = openDialog->player2Name->Text;
					 play->startButton->Enabled = FALSE;
					 play->player1Type = 2;
					 play->player2Type = 2;
					 play->gameType = 1;
					 play->initialize_Squares(sendFileName);
					 play->ShowDialog();
					 start::Show();
				 }

			 }

			 /// <summary>
			 /// Computer Play Button Click Action
			 /// </summary>
	private: System::Void ComputerPlay_Click(System::Object^  sender, System::EventArgs^  e) {

				 String^ tempFile = fileName;

				 if(tempFile == "null"){
					 MessageBox::Show("No File Selected",
						 "Error Loading File", MessageBoxButtons::OKCancel,
						 MessageBoxIcon::Asterisk);
					 return;
				 }

				 InputComputerPlayType^ openDialog = gcnew InputComputerPlayType();

				 if ( openDialog->ShowDialog( this ) == Windows::Forms::DialogResult::OK ){

					 std::string sendFileName=msclr::interop::marshal_as< std::string >(tempFile);

					 start::Hide();
					 Form1 ^play = gcnew Form1();
					 play->player1Name = openDialog->Player1Type->Text;
					 play->player2Name = openDialog->Player2Type->Text;
					 play->startButton->Enabled = true;
					 play->player1Type = (play->player1Name == "MiniMax")?0:1;
					 play->player2Type = (play->player2Name == "MiniMax")?0:1;
					 play->gameType = 2;
					 play->initialize_Squares(sendFileName);
					 play->ShowDialog();
					 start::Show();


				 }
			 }

			 /// <summary>
			 /// Browse Button Click Action
			 /// </summary>
	private: System::Void Browse_Click(System::Object^  sender, System::EventArgs^  e) {
				 // Displays an OpenFileDialog so the user can select a Text File.
				 OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();
				 openFileDialog1->Filter = "Text Files|*.txt";
				 openFileDialog1->Title = "Select a Text File";

				 // Show the Dialog.
				 // If the user clicked OK in the dialog and
				 // a .txt file was selected, open it.
				 if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				 {
					 fileName=gcnew String(openFileDialog1->FileName);
					 this->File->Text = fileName;
					 this->File->ForeColor = System::Drawing::Color::Green;
				 }
			 }
	};
}
