#ifndef FUNCTION_H
#define FUNCTION_H

#include "Library.h"
#include "MyForm.h"

System::String^ formatTime(DWORD timeInMilliseconds)
{
	int seconds = (timeInMilliseconds / 1000) % 60;
	int minutes = (timeInMilliseconds / (1000 * 60)) % 60;
	std::wostringstream oss;
	oss << std::setfill(L'0') << std::setw(2) << minutes << L":" << std::setfill(L'0') << std::setw(2) << seconds;
	return gcnew System::String(oss.str().c_str());
}
#endif // FUNCTION_H
