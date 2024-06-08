#define SDL_MAIN_HANDLED
#include "MyForm.h"
#include <SDL.h>

#undef main
using namespace System;
using namespace System::Windows::Forms;
using namespace MusicPlayer;

[STAThreadAttribute]

int main(Platform::Array<Platform::String^>^ argv)
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles;
	MusicPlayer::MyForm form;
	Application::Run(gcnew MyForm());
	if (SDL_Init( SDL_INIT_AUDIO) != 0) {
		MessageBox::Show("SDL Initialization Failed", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return 1;
	}
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Hello", "Suc" , NULL);
	return 0;

	
}
