#pragma once
#include "Grid.h"
#include "Node.h"
#include "stdafx.h"
#include "common.h"
#include <string>
#include <fstream>
#include <iostream>

namespace game {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	//int runMinMax(Grid& board,const PlayerType player, int depth,MoveType &move,game::Point &pt, bool isMaximizing=true );
	int runMinMax(Grid& board,const PlayerType player, int depth,MoveType &move,Point &pt, bool isMaximizing, int &nodesExpanded );
	int runMinMax2(Grid& board,const PlayerType player, int depth,MoveType &move,game::Point &pt, bool isMaximizing=true );
	//int runAlphaBeta(Grid& board,const PlayerType player, int depth,MoveType &move,game::Point &pt, bool isMaximizing,int alpha=-1e7, int beta=1e7 );
	int runAlphaBeta(Grid& board,const PlayerType player, int depth,MoveType &move,Point &pt, bool isMaximizing,int &nodesExpanded,int alpha=-1e7, int beta=1e7 );

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void) : GRIDSIZE(6)
		{
			InitializeComponent();
			player1Name = "player1";
			player2Name = "player2";
			AutoInitialization();
			//ManualInitialization();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	protected: 
	private: System::Windows::Forms::Button^  player1Color;
	private: System::Windows::Forms::TextBox^  player1Score;
	private: System::Windows::Forms::TextBox^  player2Score;
	private: System::Windows::Forms::Button^  player2Color;


	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::TextBox^  statusBar;

	private: System::Windows::Forms::Panel^  panel3;



	public: System::Windows::Forms::Label^  player2Label;
	private: 
	public: System::Windows::Forms::Label^  player1Label;



	private: System::Windows::Forms::TextBox^  movesBox;
	public: System::Windows::Forms::Button^  startButton;
	private: 

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::Button^  button12;
	private: System::Windows::Forms::Button^  button13;
	private: System::Windows::Forms::Button^  button14;
	private: System::Windows::Forms::Button^  button15;
	private: System::Windows::Forms::Button^  button16;
	private: System::Windows::Forms::Button^  button17;
	private: System::Windows::Forms::Button^  button18;
	private: System::Windows::Forms::Button^  button19;
	private: System::Windows::Forms::Button^  button20;
	private: System::Windows::Forms::Button^  button21;
	private: System::Windows::Forms::Button^  button22;
	private: System::Windows::Forms::Button^  button23;
	private: System::Windows::Forms::Button^  button24;
	private: System::Windows::Forms::Button^  button25;
	private: System::Windows::Forms::Button^  button26;
	private: System::Windows::Forms::Button^  button27;
	private: System::Windows::Forms::Button^  button28;
	private: System::Windows::Forms::Button^  button29;
	private: System::Windows::Forms::Button^  button30;
	private: System::Windows::Forms::Button^  button31;
	private: System::Windows::Forms::Button^  button32;
	private: System::Windows::Forms::Button^  button33;
	private: System::Windows::Forms::Button^  button34;
	private: System::Windows::Forms::Button^  button35;
	private: System::Windows::Forms::Button^  button36;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RadioButton^  blitzRadio;

	private: System::Windows::Forms::RadioButton^  paraDropRadio;



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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->startButton = (gcnew System::Windows::Forms::Button());
			this->player2Label = (gcnew System::Windows::Forms::Label());
			this->player1Label = (gcnew System::Windows::Forms::Label());
			this->player1Color = (gcnew System::Windows::Forms::Button());
			this->player1Score = (gcnew System::Windows::Forms::TextBox());
			this->player2Score = (gcnew System::Windows::Forms::TextBox());
			this->player2Color = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->statusBar = (gcnew System::Windows::Forms::TextBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->blitzRadio = (gcnew System::Windows::Forms::RadioButton());
			this->paraDropRadio = (gcnew System::Windows::Forms::RadioButton());
			this->movesBox = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->button20 = (gcnew System::Windows::Forms::Button());
			this->button21 = (gcnew System::Windows::Forms::Button());
			this->button22 = (gcnew System::Windows::Forms::Button());
			this->button23 = (gcnew System::Windows::Forms::Button());
			this->button24 = (gcnew System::Windows::Forms::Button());
			this->button25 = (gcnew System::Windows::Forms::Button());
			this->button26 = (gcnew System::Windows::Forms::Button());
			this->button27 = (gcnew System::Windows::Forms::Button());
			this->button28 = (gcnew System::Windows::Forms::Button());
			this->button29 = (gcnew System::Windows::Forms::Button());
			this->button30 = (gcnew System::Windows::Forms::Button());
			this->button31 = (gcnew System::Windows::Forms::Button());
			this->button32 = (gcnew System::Windows::Forms::Button());
			this->button33 = (gcnew System::Windows::Forms::Button());
			this->button34 = (gcnew System::Windows::Forms::Button());
			this->button35 = (gcnew System::Windows::Forms::Button());
			this->button36 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->startButton);
			this->panel1->Controls->Add(this->player2Label);
			this->panel1->Controls->Add(this->player1Label);
			this->panel1->Controls->Add(this->player1Color);
			this->panel1->Controls->Add(this->player1Score);
			this->panel1->Controls->Add(this->player2Score);
			this->panel1->Controls->Add(this->player2Color);
			this->panel1->Location = System::Drawing::Point(1, 1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(488, 45);
			this->panel1->TabIndex = 0;
			// 
			// startButton
			// 
			this->startButton->Location = System::Drawing::Point(197, 13);
			this->startButton->Name = L"startButton";
			this->startButton->Size = System::Drawing::Size(96, 21);
			this->startButton->TabIndex = 9;
			this->startButton->Text = L"Start";
			this->startButton->UseVisualStyleBackColor = true;
			this->startButton->Click += gcnew System::EventHandler(this, &Form1::startButton_Click);
			// 
			// player2Label
			// 
			this->player2Label->AutoSize = true;
			this->player2Label->Location = System::Drawing::Point(310, 17);
			this->player2Label->Name = L"player2Label";
			this->player2Label->Size = System::Drawing::Size(42, 13);
			this->player2Label->TabIndex = 8;
			this->player2Label->Text = L"Player2";
			this->player2Label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->player2Label->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// player1Label
			// 
			this->player1Label->AutoSize = true;
			this->player1Label->Location = System::Drawing::Point(11, 17);
			this->player1Label->Name = L"player1Label";
			this->player1Label->Size = System::Drawing::Size(42, 13);
			this->player1Label->TabIndex = 7;
			this->player1Label->Text = L"Player1";
			this->player1Label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// player1Color
			// 
			this->player1Color->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->player1Color->Location = System::Drawing::Point(59, 13);
			this->player1Color->Name = L"player1Color";
			this->player1Color->Size = System::Drawing::Size(49, 20);
			this->player1Color->TabIndex = 6;
			this->player1Color->UseVisualStyleBackColor = false;
			// 
			// player1Score
			// 
			this->player1Score->Location = System::Drawing::Point(114, 13);
			this->player1Score->Name = L"player1Score";
			this->player1Score->Size = System::Drawing::Size(64, 20);
			this->player1Score->TabIndex = 5;
			this->player1Score->Text = L"0";
			this->player1Score->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// player2Score
			// 
			this->player2Score->Location = System::Drawing::Point(413, 14);
			this->player2Score->Name = L"player2Score";
			this->player2Score->Size = System::Drawing::Size(64, 20);
			this->player2Score->TabIndex = 4;
			this->player2Score->Text = L"0";
			this->player2Score->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// player2Color
			// 
			this->player2Color->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->player2Color->Location = System::Drawing::Point(358, 14);
			this->player2Color->Name = L"player2Color";
			this->player2Color->Size = System::Drawing::Size(49, 20);
			this->player2Color->TabIndex = 3;
			this->player2Color->UseVisualStyleBackColor = false;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->statusBar);
			this->panel2->Location = System::Drawing::Point(1, 407);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(488, 27);
			this->panel2->TabIndex = 1;
			// 
			// statusBar
			// 
			this->statusBar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->statusBar->Location = System::Drawing::Point(0, 1);
			this->statusBar->Name = L"statusBar";
			this->statusBar->Size = System::Drawing::Size(488, 23);
			this->statusBar->TabIndex = 0;
			this->statusBar->Text = L"Player1 to move";
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->groupBox1);
			this->panel3->Controls->Add(this->movesBox);
			this->panel3->Location = System::Drawing::Point(360, 52);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(129, 328);
			this->panel3->TabIndex = 2;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->blitzRadio);
			this->groupBox1->Controls->Add(this->paraDropRadio);
			this->groupBox1->Location = System::Drawing::Point(7, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(99, 58);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"MoveType";
			// 
			// blitzRadio
			// 
			this->blitzRadio->AutoSize = true;
			this->blitzRadio->Location = System::Drawing::Point(6, 35);
			this->blitzRadio->Name = L"blitzRadio";
			this->blitzRadio->Size = System::Drawing::Size(44, 17);
			this->blitzRadio->TabIndex = 1;
			this->blitzRadio->Text = L"Blitz";
			this->blitzRadio->UseVisualStyleBackColor = true;
			this->blitzRadio->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton1_CheckedChanged);
			// 
			// paraDropRadio
			// 
			this->paraDropRadio->AutoSize = true;
			this->paraDropRadio->Checked = true;
			this->paraDropRadio->Location = System::Drawing::Point(6, 19);
			this->paraDropRadio->Name = L"paraDropRadio";
			this->paraDropRadio->Size = System::Drawing::Size(73, 17);
			this->paraDropRadio->TabIndex = 0;
			this->paraDropRadio->TabStop = true;
			this->paraDropRadio->Text = L"Para Drop";
			this->paraDropRadio->UseVisualStyleBackColor = true;
			// 
			// movesBox
			// 
			this->movesBox->Location = System::Drawing::Point(7, 67);
			this->movesBox->Multiline = true;
			this->movesBox->Name = L"movesBox";
			this->movesBox->Size = System::Drawing::Size(99, 250);
			this->movesBox->TabIndex = 2;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(46, 81);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(50, 50);
			this->button1->TabIndex = 3;
			this->button1->Text = L"1";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(93, 81);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(50, 50);
			this->button2->TabIndex = 4;
			this->button2->Text = L"1";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(138, 81);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(50, 50);
			this->button3->TabIndex = 5;
			this->button3->Text = L"1";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(185, 81);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(50, 50);
			this->button4->TabIndex = 6;
			this->button4->Text = L"1";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(231, 81);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(50, 50);
			this->button5->TabIndex = 7;
			this->button5->Text = L"1";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(278, 81);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(50, 50);
			this->button6->TabIndex = 8;
			this->button6->Text = L"1";
			this->button6->UseVisualStyleBackColor = true;
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(278, 128);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(50, 50);
			this->button7->TabIndex = 14;
			this->button7->Text = L"1";
			this->button7->UseVisualStyleBackColor = true;
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(231, 128);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(50, 50);
			this->button8->TabIndex = 13;
			this->button8->Text = L"1";
			this->button8->UseVisualStyleBackColor = true;
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(185, 128);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(50, 50);
			this->button9->TabIndex = 12;
			this->button9->Text = L"1";
			this->button9->UseVisualStyleBackColor = true;
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(138, 128);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(50, 50);
			this->button10->TabIndex = 11;
			this->button10->Text = L"1";
			this->button10->UseVisualStyleBackColor = true;
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(93, 128);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(50, 50);
			this->button11->TabIndex = 10;
			this->button11->Text = L"1";
			this->button11->UseVisualStyleBackColor = true;
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(46, 128);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(50, 50);
			this->button12->TabIndex = 9;
			this->button12->Text = L"1";
			this->button12->UseVisualStyleBackColor = true;
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(278, 174);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(50, 50);
			this->button13->TabIndex = 20;
			this->button13->Text = L"1";
			this->button13->UseVisualStyleBackColor = true;
			// 
			// button14
			// 
			this->button14->Location = System::Drawing::Point(231, 174);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(50, 50);
			this->button14->TabIndex = 19;
			this->button14->Text = L"1";
			this->button14->UseVisualStyleBackColor = true;
			// 
			// button15
			// 
			this->button15->Location = System::Drawing::Point(185, 174);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(50, 50);
			this->button15->TabIndex = 18;
			this->button15->Text = L"1";
			this->button15->UseVisualStyleBackColor = true;
			// 
			// button16
			// 
			this->button16->Location = System::Drawing::Point(138, 174);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(50, 50);
			this->button16->TabIndex = 17;
			this->button16->Text = L"1";
			this->button16->UseVisualStyleBackColor = true;
			// 
			// button17
			// 
			this->button17->Location = System::Drawing::Point(93, 174);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(50, 50);
			this->button17->TabIndex = 16;
			this->button17->Text = L"1";
			this->button17->UseVisualStyleBackColor = true;
			// 
			// button18
			// 
			this->button18->Location = System::Drawing::Point(46, 174);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(50, 50);
			this->button18->TabIndex = 15;
			this->button18->Text = L"1";
			this->button18->UseVisualStyleBackColor = true;
			// 
			// button19
			// 
			this->button19->Location = System::Drawing::Point(278, 220);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(50, 50);
			this->button19->TabIndex = 26;
			this->button19->Text = L"1";
			this->button19->UseVisualStyleBackColor = true;
			// 
			// button20
			// 
			this->button20->Location = System::Drawing::Point(231, 220);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(50, 50);
			this->button20->TabIndex = 25;
			this->button20->Text = L"1";
			this->button20->UseVisualStyleBackColor = true;
			// 
			// button21
			// 
			this->button21->Location = System::Drawing::Point(185, 220);
			this->button21->Name = L"button21";
			this->button21->Size = System::Drawing::Size(50, 50);
			this->button21->TabIndex = 24;
			this->button21->Text = L"1";
			this->button21->UseVisualStyleBackColor = true;
			// 
			// button22
			// 
			this->button22->Location = System::Drawing::Point(138, 220);
			this->button22->Name = L"button22";
			this->button22->Size = System::Drawing::Size(50, 50);
			this->button22->TabIndex = 23;
			this->button22->Text = L"1";
			this->button22->UseVisualStyleBackColor = true;
			// 
			// button23
			// 
			this->button23->Location = System::Drawing::Point(93, 220);
			this->button23->Name = L"button23";
			this->button23->Size = System::Drawing::Size(50, 50);
			this->button23->TabIndex = 22;
			this->button23->Text = L"1";
			this->button23->UseVisualStyleBackColor = true;
			// 
			// button24
			// 
			this->button24->Location = System::Drawing::Point(46, 220);
			this->button24->Name = L"button24";
			this->button24->Size = System::Drawing::Size(50, 50);
			this->button24->TabIndex = 21;
			this->button24->Text = L"1";
			this->button24->UseVisualStyleBackColor = true;
			// 
			// button25
			// 
			this->button25->Location = System::Drawing::Point(278, 267);
			this->button25->Name = L"button25";
			this->button25->Size = System::Drawing::Size(50, 50);
			this->button25->TabIndex = 32;
			this->button25->Text = L"1";
			this->button25->UseVisualStyleBackColor = true;
			// 
			// button26
			// 
			this->button26->Location = System::Drawing::Point(231, 267);
			this->button26->Name = L"button26";
			this->button26->Size = System::Drawing::Size(50, 50);
			this->button26->TabIndex = 31;
			this->button26->Text = L"1";
			this->button26->UseVisualStyleBackColor = true;
			// 
			// button27
			// 
			this->button27->Location = System::Drawing::Point(185, 267);
			this->button27->Name = L"button27";
			this->button27->Size = System::Drawing::Size(50, 50);
			this->button27->TabIndex = 30;
			this->button27->Text = L"1";
			this->button27->UseVisualStyleBackColor = true;
			// 
			// button28
			// 
			this->button28->Location = System::Drawing::Point(138, 267);
			this->button28->Name = L"button28";
			this->button28->Size = System::Drawing::Size(50, 50);
			this->button28->TabIndex = 29;
			this->button28->Text = L"1";
			this->button28->UseVisualStyleBackColor = true;
			// 
			// button29
			// 
			this->button29->Location = System::Drawing::Point(93, 267);
			this->button29->Name = L"button29";
			this->button29->Size = System::Drawing::Size(50, 50);
			this->button29->TabIndex = 28;
			this->button29->Text = L"1";
			this->button29->UseVisualStyleBackColor = true;
			// 
			// button30
			// 
			this->button30->Location = System::Drawing::Point(46, 267);
			this->button30->Name = L"button30";
			this->button30->Size = System::Drawing::Size(50, 50);
			this->button30->TabIndex = 27;
			this->button30->Text = L"1";
			this->button30->UseVisualStyleBackColor = true;
			// 
			// button31
			// 
			this->button31->Location = System::Drawing::Point(278, 314);
			this->button31->Name = L"button31";
			this->button31->Size = System::Drawing::Size(50, 50);
			this->button31->TabIndex = 38;
			this->button31->Text = L"1";
			this->button31->UseVisualStyleBackColor = true;
			// 
			// button32
			// 
			this->button32->Location = System::Drawing::Point(231, 314);
			this->button32->Name = L"button32";
			this->button32->Size = System::Drawing::Size(50, 50);
			this->button32->TabIndex = 37;
			this->button32->Text = L"1";
			this->button32->UseVisualStyleBackColor = true;
			// 
			// button33
			// 
			this->button33->Location = System::Drawing::Point(185, 314);
			this->button33->Name = L"button33";
			this->button33->Size = System::Drawing::Size(50, 50);
			this->button33->TabIndex = 36;
			this->button33->Text = L"1";
			this->button33->UseVisualStyleBackColor = true;
			// 
			// button34
			// 
			this->button34->Location = System::Drawing::Point(138, 314);
			this->button34->Name = L"button34";
			this->button34->Size = System::Drawing::Size(50, 50);
			this->button34->TabIndex = 35;
			this->button34->Text = L"1";
			this->button34->UseVisualStyleBackColor = true;
			// 
			// button35
			// 
			this->button35->Location = System::Drawing::Point(93, 314);
			this->button35->Name = L"button35";
			this->button35->Size = System::Drawing::Size(50, 50);
			this->button35->TabIndex = 34;
			this->button35->Text = L"1";
			this->button35->UseVisualStyleBackColor = true;
			// 
			// button36
			// 
			this->button36->Location = System::Drawing::Point(46, 314);
			this->button36->Name = L"button36";
			this->button36->Size = System::Drawing::Size(50, 50);
			this->button36->TabIndex = 33;
			this->button36->Text = L"1";
			this->button36->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(67, 367);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(13, 13);
			this->label2->TabIndex = 39;
			this->label2->Text = L"a";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(113, 367);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(13, 13);
			this->label3->TabIndex = 40;
			this->label3->Text = L"b";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(156, 367);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(13, 13);
			this->label4->TabIndex = 41;
			this->label4->Text = L"c";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(205, 367);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(13, 13);
			this->label5->TabIndex = 42;
			this->label5->Text = L"d";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(249, 367);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(13, 13);
			this->label6->TabIndex = 43;
			this->label6->Text = L"e";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(296, 367);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(10, 13);
			this->label7->TabIndex = 44;
			this->label7->Text = L"f";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(27, 333);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(13, 13);
			this->label8->TabIndex = 45;
			this->label8->Text = L"1";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(27, 286);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(13, 13);
			this->label9->TabIndex = 46;
			this->label9->Text = L"2";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(27, 239);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(13, 13);
			this->label10->TabIndex = 47;
			this->label10->Text = L"3";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(27, 193);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(13, 13);
			this->label11->TabIndex = 48;
			this->label11->Text = L"4";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(27, 147);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(13, 13);
			this->label12->TabIndex = 49;
			this->label12->Text = L"5";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(27, 100);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(13, 13);
			this->label13->TabIndex = 50;
			this->label13->Text = L"6";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(491, 433);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button31);
			this->Controls->Add(this->button32);
			this->Controls->Add(this->button33);
			this->Controls->Add(this->button34);
			this->Controls->Add(this->button35);
			this->Controls->Add(this->button36);
			this->Controls->Add(this->button25);
			this->Controls->Add(this->button26);
			this->Controls->Add(this->button27);
			this->Controls->Add(this->button28);
			this->Controls->Add(this->button29);
			this->Controls->Add(this->button30);
			this->Controls->Add(this->button19);
			this->Controls->Add(this->button20);
			this->Controls->Add(this->button21);
			this->Controls->Add(this->button22);
			this->Controls->Add(this->button23);
			this->Controls->Add(this->button24);
			this->Controls->Add(this->button13);
			this->Controls->Add(this->button14);
			this->Controls->Add(this->button15);
			this->Controls->Add(this->button16);
			this->Controls->Add(this->button17);
			this->Controls->Add(this->button18);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Form1::Form1_FormClosed);
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: array<System::Windows::Forms::Button^, 2>^ button;		//2D Array of Buttons
	private: const int GRIDSIZE;									//Currently 6*6 grid
	public: int turn;												//1 = player1, 2 = player2
	public: int player1Type, player2Type;							//0 = minimax, 1 = alphabeta, 2 = human
	public: String ^player1Name, ^player2Name;						//PlayerNames
	public: int gameStarted;										//0 = Not Started, 1 = Started, 2 = Finished
	public: int gameType;											//0 = singlePlayer, 1 = Multiplayer, 2 = comp vs comp
	public: game::Grid *board;
	public: int moveNumber;

			/// <summary>
			/// Do Not Modify!!
			/// </summary>
	private: Void addButtonReference(){
				 this->button[0,0] = this->button1;
				 this->button[0,1] = this->button2;
				 this->button[0,2] = this->button3;
				 this->button[0,3] = this->button4;
				 this->button[0,4] = this->button5;
				 this->button[0,5] = this->button6;

				 this->button[1,0] = this->button12;
				 this->button[1,1] = this->button11;
				 this->button[1,2] = this->button10;
				 this->button[1,3] = this->button9;
				 this->button[1,4] = this->button8;
				 this->button[1,5] = this->button7;

				 this->button[2,0] = this->button18;
				 this->button[2,1] = this->button17;
				 this->button[2,2] = this->button16;
				 this->button[2,3] = this->button15;
				 this->button[2,4] = this->button14;
				 this->button[2,5] = this->button13;

				 this->button[3,0] = this->button24;
				 this->button[3,1] = this->button23;
				 this->button[3,2] = this->button22;
				 this->button[3,3] = this->button21;
				 this->button[3,4] = this->button20;
				 this->button[3,5] = this->button19;

				 this->button[4,0] = this->button30;
				 this->button[4,1] = this->button29;
				 this->button[4,2] = this->button28;
				 this->button[4,3] = this->button27;
				 this->button[4,4] = this->button26;
				 this->button[4,5] = this->button25;

				 this->button[5,0] = this->button36;
				 this->button[5,1] = this->button35;
				 this->button[5,2] = this->button34;
				 this->button[5,3] = this->button33;
				 this->button[5,4] = this->button32;
				 this->button[5,5] = this->button31;
			 }


	private: Void AutoInitialization(){
				 this->movesBox->ScrollBars = ScrollBars::Vertical;
				 gameStarted=0;
				 this->startButton->ForeColor = Color::Green;

				 int i,j;
				 button = gcnew cli::array<System::Windows::Forms::Button^, 2>(GRIDSIZE, GRIDSIZE);
				 addButtonReference();

				 for(i=0;i<GRIDSIZE;i++){
					 for(j=0;j<GRIDSIZE;j++){
						 this->button[i,j]->Click += gcnew System::EventHandler(this, &Form1::cell_Click);
					 }
				 }

				 this->player1Color->BackColor = Color::Blue;
				 this->player2Color->BackColor = Color::Green;
			 }

			 /// <summary>
			 /// Initialize the required variables, buttons
			 /// </summary>
	private: Void ManualInitialization(){
				 turn=1;
				 moveNumber=1;

				 //TODO
				 this->player1Label->Text = player1Name;
				 this->player2Label->Text = player2Name;
				 this->statusBar->Text = L""+player1Name+" to move!!";

				 if(gameType == 1 || gameType == 0){
					 gameStarted = 1;
				 }

				 board = new Grid();
				 for (int i = 0; i < GRIDSIZE; ++i){
					 for (int j = 0; j < GRIDSIZE; ++j){
						 board->cell[i][j].value =  int::Parse(button[i,j]->Text);
					 }
				 }
				 board->calculateTotalValue();

				 int nodesExpanded;
				 PlayerType p1 = BLUE;
				 PlayerType p2 = GREEN;
				 MoveType move;
				 game::Point pt;
				 if(gameType == 0 && turn ==1 && player1Type !=2 ){
					 
					 if(player1Type==0){
						 runMinMax( *board,p1, treeDepthMin, move, pt, true,nodesExpanded );
					 }else if(player1Type==1){
						 runAlphaBeta( *board,p1, treeDepthAlpha, move, pt, true,nodesExpanded );
					 }
					 updateBoard(pt.x,pt.y,move);
				 }
				 //runAlphaBeta( *board,p1, treeDepthAlpha, move, pt, true,nodesExpanded );
				 //updateBoard(pt.x,pt.y,move);

			 }


	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }

			 /// <summary>
			 /// Event Handler for clicking a cell on the grid
			 /// </summary>
	private: System::Void cell_Click(System::Object^  sender, System::EventArgs^  e) {
				 int row,col,i,j;

				 for(i=0;i<GRIDSIZE;i++){
					 for(j=0;j<GRIDSIZE;j++){
						 if(this->button[i,j]==sender){
							 row=i; col=j;
						 }
					 }
				 }

				 sqaure_Clicked(row, col);

			 }

	public: bool checkBlitz(int x, int y, OccupiedType player){
				for (int k = 0; k < 4; ++k)
				{	
					if(board->cell[x][y].next[k]!=NULL && board->cell[x][y].next[k]->whoOccupy==player)
					{							
						return true;
					}
				}
				return false;
			}

			/// <summary>
			/// Action when clicked on the cell (i,j)
			/// </summary>
	public: void sqaure_Clicked(int i, int j){
				if(gameStarted==1){
					if(board->cell[i][j].whoOccupy != UNOCCUPIED){
						return;
					}
					if(gameType==1){
						if(this->blitzRadio->Checked){
							if(!checkBlitz(i,j,turn==1?BLUE:GREEN)){
								MessageBox::Show("Illegal BLITZ Move",
									"Error!!", MessageBoxButtons::OKCancel,
									MessageBoxIcon::Asterisk);
								return;
							}
							updateBoard(i,j,BLITZ);
						}else{
							updateBoard(i,j,PARADROP);
						}
					}else if(gameType==0){
						if((turn==1 && player1Type==2)||(turn==2 && player2Type==2)){
							if(this->blitzRadio->Checked){
								if(!checkBlitz(i,j,turn==1?BLUE:GREEN)){
									MessageBox::Show("Illegal BLITZ Move",
										"Error!!", MessageBoxButtons::OKCancel,
										MessageBoxIcon::Asterisk);
									return;
								}
								updateBoard(i,j,BLITZ);
							}else{
								updateBoard(i,j,PARADROP);
							}
						}
						PlayerType p1 = BLUE;
						PlayerType p2 = GREEN;
						MoveType move;
						game::Point pt;
						int nodesExpanded;

						if(player1Type==0){
							runMinMax( *board,p1, treeDepthMin, move, pt, true,nodesExpanded );
						}else if(player1Type==1){
							runAlphaBeta( *board,p1, treeDepthAlpha, move, pt, true,nodesExpanded );
						}else if(player2Type==0){
							runMinMax( *board,p2, treeDepthMin, move, pt, true,nodesExpanded );
						}else if(player2Type==1){
							runAlphaBeta( *board,p2, treeDepthAlpha, move, pt, true,nodesExpanded );
						}
						updateBoard(pt.x,pt.y,move);
					}
				}
			}

	public: bool finishedGame(){
				for(int i=0;i<GRIDSIZE;i++){
					for(int j=0;j<GRIDSIZE;j++){
						if(board->cell[i][j].whoOccupy == UNOCCUPIED){
							return false;
						}
					}
				}
				return true;
			}

	public: void updateBoard(int x, int y, MoveType move){
				PlayerType p1 = BLUE;
				PlayerType p2 = GREEN;

				if(turn==1){
					board->cell[x][y].whoOccupy = p1;
					button[x,y]->BackColor = Color::Blue;
					this->statusBar->Text = L""+player2Name+" to move!!";
					turn=2;
				}else{
					board->cell[x][y].whoOccupy = p2;
					button[x,y]->BackColor = Color::Green;
					this->statusBar->Text = L""+player1Name+" to move!!";
					turn=1;
				}
				char carr[] = "a";
				carr[0] = (char)('a'+y);
				String^ stringPos = gcnew String(carr);
				if(turn==2)this->movesBox->AppendText((moveNumber) + ". "+ ((moveNumber)<10?" ":"")+ "p1: " + stringPos + (int)(6-x));
				else this->movesBox->AppendText((moveNumber) + ". "+ ((moveNumber)<10?" ":"")+ "p2: " + stringPos + (int)(6-x));
				if(move == BLITZ) {
					this->movesBox->AppendText(" B\r\n");
					std::queue<Point*> *p = board->doBlitz(x,y);
					while (!p->empty()){
						button[p->front()->x,p->front()->y]->BackColor = (turn==2)?Color::Blue: Color::Green;
						p->pop();
					}
				}else{
					this->movesBox->AppendText(" D\r\n");
				}
				String^ p1Score = board->calculatePlayerValue(p1).ToString();
				String^ p2Score = board->calculatePlayerValue(p2).ToString();
				this->player1Score->Text = p1Score;
				this->player2Score->Text = p2Score;
				if(finishedGame()){
					this->statusBar->ForeColor = System::Drawing::Color::Green;
					if(int::Parse(p1Score) > int::Parse(p2Score)){
						this->statusBar->Text = L""+player1Name +" Wins!!";
					}else if(int::Parse(p1Score) < int::Parse(p2Score)){
						this->statusBar->Text = L""+player2Name +" Wins!!";
					}else{
						this->statusBar->Text = L" Game Drawn!!";
					}
					gameStarted=2;
					this->startButton->ForeColor = Color::Green;
					this->startButton->Text = "New Game";
					this->startButton->Enabled = true;
				}
				this->Refresh();
				moveNumber++;
			}

			/// <summary>
			/// Initialize the values of cell of the grid by reading from a file
			/// </summary>
	public: void initialize_Squares(string filename){
				string line;
				ifstream myfile (filename);
				if (myfile.is_open()){
					int num, i=0;
					while(myfile >> num){
						button[i/6,i%6]->Text = num+"";
						i++;
					}
					myfile.close();
				}
				else{
					MessageBox::Show("Error in reading the file");
				}
				ManualInitialization();
			}

			/// <summary>
			/// Start Button Click
			/// </summary>
	private: System::Void startButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 if(gameStarted==0){
					 this->movesBox->Text = "";
					 this->startButton->ForeColor = Color::Red;
					 this->startButton->Text = "Pause";
					 this->Refresh();
					 gameStarted=1;
					 if(gameType == 2){
						 this->blitzRadio->Enabled = false;
						 this->paraDropRadio->Enabled = false;
						 computerVsComputer();
					 }
				 }else if(gameStarted==1){
					 //TODO
				 }else{
					 //Game Finished
					 gameStarted = 2;
					 this->Close();
				 }
			 }

	public: void runMinOrAlphaBeta(int choice){
				if(choice==1){
				}else{
				}
			}

			 /// <summary>
			 /// Run the Game!!!
			 /// </summary>
	public: void computerVsComputer(){
				//Grid board;

				PlayerType p1 = BLUE;
				PlayerType p2 = GREEN;
				MoveType move;
				game::Point pt;
				int nodesExpanded;

				for (int i = 0; i < 18; ++i)
				{
					//Player1 Moves
					if(player1Type==0){
						runMinMax( *board,p1, treeDepthMin, move, pt, true,nodesExpanded );
					}else{
						runAlphaBeta( *board,p1, treeDepthAlpha, move, pt, true,nodesExpanded );
					}
					updateBoard(pt.x,pt.y,move);

					//Player2 Moves
					if(player2Type==0){
						runMinMax( *board,p2, treeDepthMin, move, pt, true,nodesExpanded );
					}else{
						runAlphaBeta( *board,p2, treeDepthAlpha, move, pt, true,nodesExpanded );
					}
					updateBoard(pt.x,pt.y,move);

				}
			}

	private: System::Void Form1_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
				 if(gameStarted!=2){
					 Application::Exit();
				 }
			 }
	private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
	};
}

