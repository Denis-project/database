#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

/*
	Данных:
	1. Инициалы (ФИО)
	2. Дата
	3. Адрес
*/

	//структура ФИО
struct Initial {
	string surname,
		patronymic,
		name;
};

	//структура дата
struct Date {
	int day,
		month,
		year;
};

	//структура адрес
struct Address {
	string city;
	int home;
};

	//структура данных
struct Data {
	Initial _initial;
	Date _date;
	Address _address;
};

void DataEntry(Data* (&d), int &n); //ввод данных вручую
void ReadingData(Data* (&d), int& n, string filName); //чтение данных из файла 
void Print(Data* d, int n); //вывод данных
void DataChange(Data* (&d), int n); //изменение данных 
void DeleteData(Data* (&d), int& n); //удаление данных
void Copy(Data* (&d_n), Data* (&d_o), int n); //копия данных
void Copy(Data& d_n, Data& d_o); //копия данных элемента
void AddData(Data* (&d), int &n); //добавить данные 
void DataSorting(Data *d, int n); //сортировка данных
void SavingData(Data* d, int n, string filName); //сохранение данных

