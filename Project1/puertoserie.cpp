#include "MyForm.h"					//            The header file of the form

using namespace Project1;			//            The name of the namespace in MyForm.h
[STAThreadAttribute]				//            Run this program in STA mode
int main() {
	//MyForm SP;					//            The form to be created and shown
	//SP.ShowDialog();				//            Show the form
	
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	//Application::SetCompatibleTextRenderingDefault(false);

	// Create the main window and run it
	Application::Run(gcnew MyForm());

	
	return 0;
}