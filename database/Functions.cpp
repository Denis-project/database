
#include "Functions.h"

void DataEntry(Data* (&d), int& n)
{
	cout << "������� ���������� ������: ";
	cin >> n;

	//������� ������
	d = new Data[n];

	for (int i = 0; i < n; i++) {
		cout << "������� ���: ";
		cin >> d[i]._initial.surname;
		cin >> d[i]._initial.patronymic;
		cin >> d[i]._initial.name;

		cout << "������� ����: ";
		cin >> d[i]._date.day;
		cin >> d[i]._date.month;
		cin >> d[i]._date.year;

		cout << "������� �����: ";
		cin >> d[i]._address.city;
		cin >> d[i]._address.home;

		cout << "______________________________" << endl;
	}
}

void ReadingData(Data* (&d), int& n, string filName)
{
	ifstream readig(filName);

	if (readig) {

		readig >> n;

		//������� ������
		d = new Data[n];

		for (int i = 0; i < n; i++) {
			cout << "������� ���: ";
			readig >> d[i]._initial.surname;
			readig >> d[i]._initial.patronymic;
			readig >> d[i]._initial.name;

			cout << "������� ����: ";
			readig >> d[i]._date.day;
			readig >> d[i]._date.month;
			readig >> d[i]._date.year;

			cout << "������� �����: ";
			readig >> d[i]._address.city;
			readig >> d[i]._address.home;

			cout << "������ �������!" << endl;
		}
	}
	else
		cout << "������ �������� �����!" << endl;

	readig.close();
}

void Print(Data* d, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "������ �" << i + i << ":" << endl;

		cout << "���: " << d[i]._initial.surname << " " << d[i]._initial.name << " " << d[i]._initial.patronymic << endl;
		cout << "���: " << d[i]._date.day << " " << d[i]._date.month << " " << d[i]._date.year	 << endl;
		cout << "���: " << d[i]._address.city << " " << d[i]._address.home << endl;

		cout << "______________________________" << endl;
	}
}

void DataChange(Data* (&d), int n)
{
	int _n;
	cout << "������� ����� �������� (0� 1 �� " << n << "): ";
	cin >> _n;
	_n--;

	system("cls");

	if (_n >= 0 && _n < n) {
		cout << "������� ���: ";
		cin >> d[_n]._initial.surname;
		cin >> d[_n]._initial.patronymic;
		cin >> d[_n]._initial.name;

		cout << "������� ����: ";
		cin >> d[_n]._date.day;
		cin >> d[_n]._date.month;
		cin >> d[_n]._date.year;

		cout << "������� �����: ";
		cin >> d[_n]._address.city;
		cin >> d[_n]._address.home;

		system("cls");

		cout << "������ ��������!" << endl;
	}
	else
		cout << "����� ������ �� �����!" << endl;
}

void DeleteData(Data* (&d), int& n)
{
	int _n;
	cout << "������� ����� �������� (0� 1 �� " << n << "): ";
	cin >> _n;
	_n--;

	system("cls");

	//��������, ��� ����� ���������� ��������
	if (_n >= 0 && _n < n) {

		//��������� ������ 
		Data* buf = new Data[n];

		Copy(buf, d, n);

		//�������� ����� ������
		--n;
		d = new Data[n];

		int q = 0;

		//��������� ������ ����� �� �������
		for (int i = 0; i < n; i++) {
			if (i != _n) {
				d[q] = buf[i];
				++q;
			}

		}

		system("cls");
		delete[]buf;

		cout << "������ �������!" << endl;
	}
	else
		cout << "����� ������ �� �����!" << endl;



}

void Copy(Data* (&d_n), Data* (&d_o), int n)
{
	for (int i = 0; i < n; i++)
	{
		d_n[i] = d_o[i];
	}
}

void Copy(Data& d_n, Data& d_o)
{
	d_n._initial.surname = d_o._initial.surname;
	d_n._initial.patronymic = d_o._initial.patronymic;
	d_n._initial.name = d_o._initial.name;

	d_n._date.day = d_o._date.day;
	d_n._date.month = d_o._date.month;
	d_n._date.year = d_o._date.year;

	d_n._address.city = d_o._address.city;
	d_n._address.home = d_o._address.home;

}

void AddData(Data* (&d), int& n)
{
	//��������� ������ ������
	Data* buf;
	buf = new Data[n];

	//��������� ������ �� ��������� ������
	Copy(buf, d, n);

	//�������� ����� ������
	n++;
	d = new Data[n];

	//���������� ������ 
	Copy(d, buf, --n);

	cout << "������� ���: ";
	cin >> d[n]._initial.surname >> d[n]._initial.name >> d[n]._initial.patronymic;

	cout << "������� ����: ";
	cin >> d[n]._date.day >> d[n]._date.month >> d[n]._date.year;

	cout << "������� �����: ";
	cin >> d[n]._address.city >> d[n]._address.home;

	system("cls");

	cout << "������ ���������!" << endl;

	delete[]buf;

}

void DataSorting(Data* d, int n)
{
	//��������� ���������� 
	Data buf;

	//���������� ������� �������� 
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (d[i]._initial.surname > d[j]._initial.surname) {
				Copy(buf, d[j]);
				Copy(d[j], d[j]);
				Copy(d[i], buf);
			}
		}
	}

	cout << "������ ��������������!" << endl;
}

void SavingData(Data* d, int n, string filName)
{
	ofstream record(filName, ios::out);

	if (record) {
		record << n << endl;

		for (int i = 0; i < n; i++)
		{
			record << d[i]._initial.surname << endl;
			record << d[i]._initial.name << endl;
			record << d[i]._initial.patronymic << endl;

			record << d[i]._date.day << " ";
			record << d[i]._date.month << " ";
			record << d[i]._date.year << " ";

			record << d[i]._address.city << " ";
			if (i < n - 1)
				record << d[i]._address.home << endl;
			else
				record << d[i]._address.home;
		}
	}
	else
		cout << "������ �������� �����!" << endl;

	record.close();
}