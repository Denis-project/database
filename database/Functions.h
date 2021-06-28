#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

/*
	������:
	1. �������� (���)
	2. ����
	3. �����
*/

	//��������� ���
struct Initial {
	string surname,
		patronymic,
		name;
};

	//��������� ����
struct Date {
	int day,
		month,
		year;
};

	//��������� �����
struct Address {
	string city;
	int home;
};

	//��������� ������
struct Data {
	Initial _initial;
	Date _date;
	Address _address;
};

void DataEntry(Data* (&d), int &n); //���� ������ ������
void ReadingData(Data* (&d), int& n, string filName); //������ ������ �� ����� 
void Print(Data* d, int n); //����� ������
void DataChange(Data* (&d), int n); //��������� ������ 
void DeleteData(Data* (&d), int& n); //�������� ������
void Copy(Data* (&d_n), Data* (&d_o), int n); //����� ������
void Copy(Data& d_n, Data& d_o); //����� ������ ��������
void AddData(Data* (&d), int &n); //�������� ������ 
void DataSorting(Data *d, int n); //���������� ������
void SavingData(Data* d, int n, string filName); //���������� ������

