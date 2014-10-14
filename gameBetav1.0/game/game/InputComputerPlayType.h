#pragma once

namespace game {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for InputComputerPlayType
	/// </summary>
	public ref class InputComputerPlayType : public System::Windows::Forms::Form
	{
	public:
		InputComputerPlayType(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			ManualInitialize();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~InputComputerPlayType()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  OkButton;
	protected: 
	private: System::Windows::Forms::Button^  CancelButton;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	public: System::Windows::Forms::ComboBox^  Player1Type;
	private: 
	public: System::Windows::Forms::ComboBox^  Player2Type;



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
			this->Player1Type = (gcnew System::Windows::Forms::ComboBox());
			this->Player2Type = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// OkButton
			// 
			this->OkButton->Location = System::Drawing::Point(71, 156);
			this->OkButton->Name = L"OkButton";
			this->OkButton->Size = System::Drawing::Size(82, 31);
			this->OkButton->TabIndex = 0;
			this->OkButton->Text = L"OK";
			this->OkButton->UseVisualStyleBackColor = true;
			this->OkButton->Click += gcnew System::EventHandler(this, &InputComputerPlayType::OkButton_Click);
			// 
			// CancelButton
			// 
			this->CancelButton->Location = System::Drawing::Point(194, 156);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(82, 31);
			this->CancelButton->TabIndex = 1;
			this->CancelButton->Text = L"Cancel";
			this->CancelButton->UseVisualStyleBackColor = true;
			this->CancelButton->Click += gcnew System::EventHandler(this, &InputComputerPlayType::CancelButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(87, 46);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(42, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Player1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(87, 102);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(42, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Player2";
			// 
			// Player1Type
			// 
			this->Player1Type->FormattingEnabled = true;
			this->Player1Type->Location = System::Drawing::Point(177, 43);
			this->Player1Type->Name = L"Player1Type";
			this->Player1Type->Size = System::Drawing::Size(121, 21);
			this->Player1Type->TabIndex = 4;
			// 
			// Player2Type
			// 
			this->Player2Type->FormattingEnabled = true;
			this->Player2Type->Location = System::Drawing::Point(177, 94);
			this->Player2Type->Name = L"Player2Type";
			this->Player2Type->Size = System::Drawing::Size(121, 21);
			this->Player2Type->TabIndex = 5;
			// 
			// InputComputerPlayType
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(363, 224);
			this->Controls->Add(this->Player2Type);
			this->Controls->Add(this->Player1Type);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->CancelButton);
			this->Controls->Add(this->OkButton);
			this->Name = L"InputComputerPlayType";
			this->Text = L"InputComputerPlayType";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: void ManualInitialize(){
				this->Player1Type->Items->Add("MiniMax");
				this->Player1Type->Items->Add("AlphaBeta");
				this->Player2Type->Items->Add("MiniMax");
				this->Player2Type->Items->Add("AlphaBeta");
				this->Player1Type->Text = "MiniMax";
				this->Player2Type->Text = "AlphaBeta";
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
