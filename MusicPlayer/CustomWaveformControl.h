#pragma once

#include "Library.h"

public ref class CustomWaveformControl : public Control
{
public:
    CustomWaveformControl();

    void SetWaveformData(array<float>^ data);

protected:
    virtual void OnPaint(PaintEventArgs^ e) override;

private:
    array<float>^ waveform_data;
};