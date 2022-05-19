#pragma once

#include "Signal.h"

typedef vector < complex < double > > iq_signal;

struct SignalGenerationParameters
{
	//����� ������� ������
	double start_timestamp;
	//��������� ����
	double start_phase;
	//�����������������
	double duration;

	double n_samples;
	//������� �������������
	double sampling_frequency;
	//�������� �������� ������
	double bitrate;
	//�������������� ��������
	double additional_parameter;
};

class SignalGenerator
{
public:
	void GenerateSignal(SignalType type, SignalGenerationParameters params, Signal& dst);
	static double carriers[51];
	iq_signal buffer;
private:
	void GenerateBPSKSignal(SignalGenerationParameters params, Signal& dst);
	void GenerateMSKSignal(SignalGenerationParameters params, Signal& dst);
	void GenerateFHSSSignal(SignalGenerationParameters params, Signal& dst);
	bool RandomBit(double low_chance);
	void FHSSGenerate(SignalGenerationParameters params, Signal& ret_signal);

	void MSKManipulation(SignalGenerationParameters params, const vector <bool>& data, iq_signal& buffer);
};