#include "CustomWaveformControl.h"

CustomWaveformControl::CustomWaveformControl()
{
    this->SetStyle(ControlStyles::UserPaint, true);
    this->SetStyle(ControlStyles::OptimizedDoubleBuffer, true);
    waveform_data = nullptr;
}
void CustomWaveformControl::SetWaveformData(array<float>^ data)
{
    waveform_data = data;
    this->Invalidate(); // Forces the control to redraw itself
}

void CustomWaveformControl::OnPaint(PaintEventArgs^ e)
{
    Control::OnPaint(e);

    // Drawing logic for the waveform
    if (waveform_data == nullptr || waveform_data->Length == 0)
        return;

    Graphics^ g = e->Graphics;
    int width = this->ClientSize.Width;
    int height = this->ClientSize.Height;

    Pen^ pen = gcnew Pen(Color::Black);
    float x_scale = static_cast<float>(width) / waveform_data->Length;
    float y_scale = height / 2.0f;

    for (int i = 0; i < waveform_data->Length - 1; ++i)
    {
        float x1 = i * x_scale;
        float y1 = height / 2 - waveform_data[i] * y_scale;
        float x2 = (i + 1) * x_scale;
        float y2 = height / 2 - waveform_data[i + 1] * y_scale;
        g->DrawLine(pen, x1, y1, x2, y2);
    }
}