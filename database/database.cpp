// database.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Functions.h"

int _stateMenu;
void Menu() {
	cout << "Выберите действие: " << endl
		<< "(0) Выход из программы" << endl
		<< "(1) Ввод данных" << endl
		<< "(2) Вывод" << endl
		<< "(3) Изменение" << endl
		<< "(4) Удаление" << endl
		<< "(5) Добавление" << endl
		<< "(6) Сортировка" << endl
		<< "(7) Сохранение" << endl
		<< "Ваш выбор: ";
	cin >> _stateMenu;
}

int main() {
	//руссификация консоли ввода/вывода 
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);

	Menu();

	//инициализация данных 
	int _actions,
		amoutOfData = 0;
	string filName;

	//массив данных 
	Data* d = new Data[amoutOfData];

	while (_stateMenu != 0)
	{
		switch (_stateMenu)
		{
		case 1:
			system("cls"); //очистка консоли

			cout << "Ввод вручную или из файла?: ";
			cin >> _actions;

			system("cls"); //очистка консоли

			if (_actions == 1) {
				//ввод вручную
				DataEntry(d, amoutOfData);
			}
			else {
				//ввод из файла
				
				//Вслучае ввода названия файла с данными 
				cout << "Введите название файла: ";
				cin >> filName;//Input.txt
				

				ReadingData(d, amoutOfData, filName);
			}

			system("pause"); //задержка консоли 
			system("cls"); //очистка консоли
			Menu();
			break;
		//////////////////////////////////////////
		case 2:
			system("cls"); //очистка консоли 

			if (amoutOfData != 0) {
				Print(d, amoutOfData);
			}
			else 
				cout << "Данные пусты!" << endl;

			system("pause"); //задержка консоли 
			system("cls"); //очистка консоли 
			Menu();
			break;
		///////////////////////////////////////////
		case 3:
			system("cls"); //очистка консоли 

			if (amoutOfData != 0) {
				DataChange(d, amoutOfData);
			}
			else
				cout << "Данные пусты!" << endl;

			system("pause"); //задержка консоли 
			system("cls"); //очистка консоли 
			Menu();
			break;
		///////////////////////////////////////////
		case 4:
			system("cls"); //очистка консоли 

			if (amoutOfData != 0) {
				DeleteData(d, amoutOfData);
			}
			else
				cout << "Данные пусты!" << endl;

			system("pause"); //задержка консоли 
			system("cls"); //очистка консоли 
			Menu();
			break;
		///////////////////////////////////////////
		case 5:
			system("cls"); //очистка консоли 

			if (amoutOfData != 0) {
				AddData(d, amoutOfData);
			}
			else
				cout << "Данные пусты!" << endl;

			system("pause"); //задержка консоли 
			system("cls"); //очистка консоли 
			Menu();
			break;
		///////////////////////////////////////////
		case 6:
			system("cls"); //очистка консоли 

			if (amoutOfData != 0) {
				DataSorting	(d, amoutOfData);
			}
			else
				cout << "Данные пусты!" << endl;

			system("pause"); //задержка консоли 
			system("cls"); //очистка консоли 
			Menu();
			break;
		///////////////////////////////////////////
		case 7:
			system("cls"); //очистка консоли 

			cout << "Введите название файла: ";
			cin >> filName;

			if (amoutOfData != 0) {
				SavingData(d, amoutOfData, filName);
			}
			else
				cout << "Данные пусты!" << endl;

			system("pause"); //задержка консоли 
			system("cls"); //очистка консоли 
			Menu();
			break;
		///////////////////////////////////////////
		default:
			cout << "Неверно введен номер действия!" << endl;
			system("pause"); //задержка консоли 
			system("cls"); //очистка консоли 
			Menu();
			break;
		}
	}
}