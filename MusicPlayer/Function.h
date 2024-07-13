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
//set audio library
IAudioEndpointVolume* pEndpointVolume = nullptr;

void InitializeEndpointVolume()
{
    CoInitialize(nullptr);

    IMMDeviceEnumerator* pEnumerator = nullptr;
    IMMDevice* pDevice = nullptr;

    HRESULT hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), nullptr, CLSCTX_INPROC_SERVER, __uuidof(IMMDeviceEnumerator), (void**)&pEnumerator);
    if (FAILED(hr)) throw std::runtime_error("Failed to create MMDeviceEnumerator instance.");

    hr = pEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &pDevice);
    if (FAILED(hr)) throw std::runtime_error("Failed to get default audio endpoint.");

    hr = pDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_INPROC_SERVER, nullptr, (void**)&pEndpointVolume);
    if (FAILED(hr)) throw std::runtime_error("Failed to activate IAudioEndpointVolume.");

    pEnumerator->Release();
    pDevice->Release();
}

void SetSystemVolume(float volume)
{
    if (pEndpointVolume == nullptr) InitializeEndpointVolume();

    HRESULT hr = pEndpointVolume->SetMasterVolumeLevelScalar(volume, nullptr);
    if (FAILED(hr)) throw std::runtime_error("Failed to set master volume level.");
}
#endif // FUNCTION_H
