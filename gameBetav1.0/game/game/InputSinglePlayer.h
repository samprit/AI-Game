#pragma once

namespace game {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for InputSinglePlayer
	/// </summary>
	public ref class InputSinglePlayer : public System::Windows::Forms::Form
	{
	public:
		InputSinglePlayer(void)
		{
			InitializeComponent();
			ManualInitialize();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~InputSinglePlayer()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  OkButton;
	private: System::Windows::Forms::Button^  CancelButton;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	public: System::Windows::Forms::ComboBox^  Player2Type;
	private: 
	public: System::Windows::Forms::TextBox^  Player1Name;
	protected: 


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
			this->OkButton = (gcnew System::Windows::Forms::Button());
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->Player2Type = (gcnew System::Windows::Forms::ComboBox());
			this->Player1Name = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// OkButton
			// 
			this->OkButton->Location = System::Drawing::Point(75, 171);
			this->OkButton->Name = L"OkButton";
			this->OkButton->Size = System::Drawing::Size(67, 31);
			this->OkButton->TabIndex = 0;
			this->OkButton->Text = L"OK";
			this->OkButton->UseVisualStyleBackColor = true;
			this->OkButton->Click += gcnew System::EventHandler(this, &InputSinglePlayer::OkButton_Click);
			// 
			// CancelButton
			// 
			this->CancelButton->Location = System::Drawing::Point(218, 171);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(67, 31);
			this->CancelButton->TabIndex = 1;
			this->CancelButton->Text = L"Cancel";
			this->CancelButton->UseVisualStyleBackColor = true;
			this->CancelButton->Click += gcnew System::EventHandler(this, &InputSinglePlayer::CancelButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(87, 53);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(42, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Player1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(87, 107);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(42, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Player2";
			// 
			// Player2Type
			// 
			this->Player2Type->FormattingEnabled = true;
			this->Player2Type->Location = System::Drawing::Point(191, 104);
			this->Player2Type->Name = L"Player2Type";
			this->Player2Type->Size = System::Drawing::Size(121, 21);
			this->Player2Type->TabIndex = 4;
			// 
			// Player1Name
			// 
			this->Player1Name->Location = System::Drawing::Point(191, 46);
			this->Player1Name->Name = L"Player1Name";
			this->Player1Name->Size = System::Drawing::Size(121, 20);
			this->Player1Name->TabIndex = 5;
			// 
			// InputSinglePlayer
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(386, 244);
			this->Controls->Add(this->Player1Name);
			this->Controls->Add(this->Player2Type);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->CancelButton);
			this->Controls->Add(this->OkButton);
			this->Name = L"InputSinglePlayer";
			this->Text = L"InputSinglePlayer";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: void ManualInitialize(){
				this->Player2Type->Items->Add("MiniMax");
				this->Player2Type->Items->Add("AlphaBeta");
				this->Player2Type->Text = "MiniMax";
			}
	private: System::Void OkButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->DialogResult = Windows::Forms::DialogResult::OK;
				 this->Close();
			 }
	private: System::Void CancelButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->DialogResult = Windows::Forms::DialogResult::Cancel;
				 this->Close();
			 }
	};
}
