#include "MyForm.h"
#include "mmstream.h"
//include <msclr/marshal.h>
#include <string>

//Windows stuff
#include <Windows.h>
#define WIN32_LEAN_AND_MEAN  
#define _WIN32_WINNT _WIN32_WINNT_VISTA

// SDL2 stuff


using namespace System;
using namespace System::Windows::Forms;



[STAThreadAttribute]
int main(array<String^>^ args)
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles;
	MusicPlayer::MyForm form;
	Application::Run(% form);

}
