#pragma once
#include <vector>
#include <complex>


using namespace std;

enum SignalType
{
	//�������� ������� ���������
	BPSK,
	//������������������ ������� �
	QPSK,
	//��������� ���������
	MSK,
	//������������������� � ������������� ��������� ����������� �������
	OFDM,
	//��������������� ����������� ������� �������
	FHSS,
};

struct Signal
{
	vector<complex<double>> signal;
	vector<double> keys;

	string name;
	//��������
	string description;

	double sampling;
	double timestamp;
	double duration;
};

struct Signal2D
{
	vector<vector<complex<double>>> signal;
	vector<double> keysX;
	vector<double> keysY;

	string name;
	string description;

	double sampling;
};