#pragma once

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Text;
	using namespace System::Threading;
	using namespace System::Drawing;
	using namespace System::IO::Ports;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:

		MyForm(void)
		{
			InitializeComponent();
			findPorts();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::IO::Ports::SerialPort^  serialPort1;
	private: System::Windows::Forms::ComboBox^  ComSelect;
	private: System::Windows::Forms::ComboBox^  BaudSelect;


	private: System::Windows::Forms::Button^  OpenButton;
	private: System::Windows::Forms::Button^  CloseButton;




	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::TextBox^  LogBox;

	private: System::Windows::Forms::TextBox^  CommandBar;
	private: System::Windows::Forms::Button^  SendButton;
	private: System::Windows::Forms::Button^  ResetButton;



	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->ComSelect = (gcnew System::Windows::Forms::ComboBox());
			this->BaudSelect = (gcnew System::Windows::Forms::ComboBox());
			this->OpenButton = (gcnew System::Windows::Forms::Button());
			this->CloseButton = (gcnew System::Windows::Forms::Button());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->LogBox = (gcnew System::Windows::Forms::TextBox());
			this->CommandBar = (gcnew System::Windows::Forms::TextBox());
			this->SendButton = (gcnew System::Windows::Forms::Button());
			this->ResetButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// serialPort1
			// 
			this->serialPort1->DataReceived += gcnew System::IO::Ports::SerialDataReceivedEventHandler(this, &MyForm::serialPort1_DataReceived);
			// 
			// ComSelect
			// 
			this->ComSelect->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->ComSelect->FormattingEnabled = true;
			this->ComSelect->Location = System::Drawing::Point(12, 23);
			this->ComSelect->Name = L"ComSelect";
			this->ComSelect->Size = System::Drawing::Size(121, 21);
			this->ComSelect->TabIndex = 0;
			// 
			// BaudSelect
			// 
			this->BaudSelect->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->BaudSelect->FormattingEnabled = true;
			this->BaudSelect->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"9600", L"115200" });
			this->BaudSelect->Location = System::Drawing::Point(202, 22);
			this->BaudSelect->Name = L"BaudSelect";
			this->BaudSelect->Size = System::Drawing::Size(121, 21);
			this->BaudSelect->TabIndex = 1;
			// 
			// OpenButton
			// 
			this->OpenButton->Location = System::Drawing::Point(426, 73);
			this->OpenButton->Name = L"OpenButton";
			this->OpenButton->Size = System::Drawing::Size(75, 23);
			this->OpenButton->TabIndex = 2;
			this->OpenButton->Text = L"OPEN";
			this->OpenButton->UseVisualStyleBackColor = true;
			this->OpenButton->Click += gcnew System::EventHandler(this, &MyForm::OpenButton_Click);
			// 
			// CloseButton
			// 
			this->CloseButton->Enabled = false;
			this->CloseButton->Location = System::Drawing::Point(426, 120);
			this->CloseButton->Name = L"CloseButton";
			this->CloseButton->Size = System::Drawing::Size(75, 23);
			this->CloseButton->TabIndex = 3;
			this->CloseButton->Text = L"CLOSE";
			this->CloseButton->UseVisualStyleBackColor = true;
			this->CloseButton->Click += gcnew System::EventHandler(this, &MyForm::CloseButton_Click);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(401, 20);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(100, 23);
			this->progressBar1->TabIndex = 4;
			// 
			// LogBox
			// 
			this->LogBox->Location = System::Drawing::Point(12, 120);
			this->LogBox->Multiline = true;
			this->LogBox->Name = L"LogBox";
			this->LogBox->ReadOnly = true;
			this->LogBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->LogBox->Size = System::Drawing::Size(311, 327);
			this->LogBox->TabIndex = 5;
			// 
			// CommandBar
			// 
			this->CommandBar->Location = System::Drawing::Point(12, 76);
			this->CommandBar->Name = L"CommandBar";
			this->CommandBar->Size = System::Drawing::Size(311, 20);
			this->CommandBar->TabIndex = 6;
			this->CommandBar->Click += gcnew System::EventHandler(this, &MyForm::CommandBar_click);
			this->CommandBar->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::EnterKeyBar);
			// 
			// SendButton
			// 
			this->SendButton->Enabled = false;
			this->SendButton->Location = System::Drawing::Point(330, 73);
			this->SendButton->Name = L"SendButton";
			this->SendButton->Size = System::Drawing::Size(52, 23);
			this->SendButton->TabIndex = 7;
			this->SendButton->Text = L"Send";
			this->SendButton->UseVisualStyleBackColor = true;
			this->SendButton->Click += gcnew System::EventHandler(this, &MyForm::SendButton_Click);
			// 
			// ResetButton
			// 
			this->ResetButton->Location = System::Drawing::Point(426, 166);
			this->ResetButton->Name = L"ResetButton";
			this->ResetButton->Size = System::Drawing::Size(75, 23);
			this->ResetButton->TabIndex = 8;
			this->ResetButton->Text = L"reset";
			this->ResetButton->UseVisualStyleBackColor = true;
//			this->ResetButton->Click += gcnew System::EventHandler(this, &MyForm::ResetButton_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(550, 459);
			this->Controls->Add(this->ResetButton);
			this->Controls->Add(this->SendButton);
			this->Controls->Add(this->CommandBar);
			this->Controls->Add(this->LogBox);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->CloseButton);
			this->Controls->Add(this->OpenButton);
			this->Controls->Add(this->BaudSelect);
			this->Controls->Add(this->ComSelect);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void findPorts();
	
	private: System::Void OpenButton_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void AfterEvent();

	private: System::Void CloseButton_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void CommandBar_click(System::Object^  sender, System::EventArgs^  e);
	
	private: System::Void EnterKeyBar(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);

	private: System::Void SendButton_Click(System::Object^  sender, System::EventArgs^  e);

	delegate void DelegateType(System::String ^);

	private: System::Void serialPort1_DataReceived(System::Object^  sender, System::IO::Ports::SerialDataReceivedEventArgs^  e);
	
	private: System::Void DataReceived(String ^myString);

	private: System::Void ResetButton_Click(System::Object^  sender, System::EventArgs^  e);

};
}
