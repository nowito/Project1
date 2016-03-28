#include "MyForm.h"
using namespace Project1;


System::Void MyForm::findPorts()
{
	// get port names
	array<Object^>^ objectArray = SerialPort::GetPortNames();
	this->ComSelect->Items->AddRange(objectArray);
}

System::Void MyForm::OpenButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (this->ComSelect->Text == String::Empty || this->BaudSelect->Text == String::Empty)
		this->LogBox->AppendText("Please Select Port Settings\r\n");
	else {
		try {
			// make sure port isn't open	
			if (!this->serialPort1->IsOpen) {
				this->serialPort1->PortName = this->ComSelect->Text;
				this->serialPort1->BaudRate = Int32::Parse(this->BaudSelect->Text);
				this->serialPort1->Parity = IO::Ports::Parity::None;
				this->serialPort1->StopBits = IO::Ports::StopBits::One;
				this->serialPort1->DataBits = 8;
				this->serialPort1->Open();
				this->CommandBar->Text = "Enter Message Here";
				this->LogBox->AppendText("\r\n**** Connected to " + ComSelect->Text + " at " + BaudSelect->Text + " Baud ****\r\n");
				//open serial port 
				this->progressBar1->Value = 100;
				// Disable the init button 
				this->OpenButton->Enabled = false;
				this->ComSelect->Enabled = false;
				this->BaudSelect->Enabled = false;
				this->CloseButton->Enabled = true;
				this->SendButton->Enabled = true;
				AfterEvent(); // Send ctrl-x 
			}
			else
				this->LogBox->AppendText("\r\nPort isn't openned\r\n");
		}
		catch (UnauthorizedAccessException^) {
			this->LogBox->AppendText("\r\nUnauthorizedAccess\r\n");
		}
	}
}

System::Void MyForm::AfterEvent()
{
	auto data = gcnew array<System::Byte> {0x18}; //send ctrl-x
	this->serialPort1->Write(data, 0, data->Length);
}

System::Void MyForm::CloseButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	//close serialPort
	if (this->serialPort1->IsOpen)
	{
		//this->serialPort1->WriteLine("\u0018"); //Send ctrl-x to reset
		this->serialPort1->Close();
		// update progress bar
		this->progressBar1->Value = 0;
		// Enable the init button
		this->OpenButton->Enabled = true;
		this->ComSelect->Enabled = true;
		this->BaudSelect->Enabled = true;
		this->CloseButton->Enabled = false;
		this->SendButton->Enabled = false;
		this->LogBox->AppendText("\r\n**** Connection Closed ****\r\n\r\n");
		//this->LogBox->Text = String::Empty;
	}
	else
		this->LogBox->AppendText("\r\nPort Not Opened\r\n");

}

	System::Void MyForm::CommandBar_click(System::Object^  sender, System::EventArgs^  e)
	{
		this->CommandBar->Text = String::Empty;
	}

	System::Void MyForm::EnterKeyBar(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		if (e->KeyCode == Keys::Enter)
		{
			// add sender name
			//String^ name = this->serialPort1->PortName;
			// grab text and store in send buffer
			String^ message = this->CommandBar->Text;
			// write to serial
			if (this->serialPort1->IsOpen)
			{
				//this->_serialPort->WriteLine(String::Format("<{0}>: {1}",name,message));
				this->serialPort1->WriteLine(message);
				this->LogBox->AppendText(">>>> " + message + "\r\n");
				this->CommandBar->Text = String::Empty;
			}
			else
				this->LogBox->AppendText("\r\nPort Not Opened\r\n");
		}
	}

	System::Void MyForm::SendButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		// grab text and store in send buffer
		String^ message = this->CommandBar->Text;
		// write to serial
		if (this->serialPort1->IsOpen)
		{
			this->serialPort1->WriteLine(message);
			this->CommandBar->Text = String::Empty;
			this->LogBox->AppendText(">>>> " + message + "\r\n");
		}
		else
			this->LogBox->AppendText("\r\nPort Not Opened\r\n");
	}

	System::Void MyForm::serialPort1_DataReceived(System::Object^  sender, System::IO::Ports::SerialDataReceivedEventArgs^  e)
	{
		// richLogBox->Text = "Received Event";
		String^ myString = serialPort1->ReadExisting();
		DelegateType ^pfnDelegate = gcnew DelegateType(this, &MyForm::DataReceived);
		this->LogBox->BeginInvoke(pfnDelegate, myString);
	}

	System::Void MyForm::DataReceived(String ^myString)
	{
		try
		{
			this->LogBox->AppendText(myString);
			//LogBox->ScrollToCaret();
		}
		catch (Win32Exception^ ex)
		{
			this->LogBox->Text = ex->Message;
		}
	}

	System::Void MyForm::ResetButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (this->serialPort1->IsOpen)
		{
			AfterEvent(); // send ctrl-x
			/*auto data = gcnew array<System::Byte> {0x18};
			this->serialPort1->Write(data, 0, data->Length);*/
		}
		else
			this->LogBox->Text = "Port Not Opened\r\n";
	}