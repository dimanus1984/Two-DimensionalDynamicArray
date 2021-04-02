#include<iostream>
using namespace std;

#define tab "\t"

int** CreateArr(int m, int n);
void FillRand(int** arr, int m, int n);
void Print(int** arr, const int m, const int n);
void Clear(int** arr, int m);
void push_row_back(int**& arr, int& m, int n);
void push_row_front(int**& arr, int& m, int n);
void insert_row(int**& arr, int& m, int n, int numPos);
void pop_row_back(int**& arr, int& m, int n);
void pop_row_front(int**& arr, int& m, int n);
void erase_row(int**& arr, int& m, int n, int numPos);

void main()
{
	setlocale(LC_ALL, "");
	int m;       // Количество строк
	int n;       // Количество столбцов
	int numMenu; // Меню выбора задания
	int numPos;  // Номер позиции в массиве
	cout << "Введите количество строк: "; cin >> m;
	cout << "Введите количество элементов строки (столбцов): "; cin >> n;
	system("cls");
	int** arr = CreateArr(m, n);
	FillRand(arr, m, n);
	Print(arr, m, n);
	do
	{
		cout << endl;
		cout << "Выберите номер задания: что Вы хотите сделать с массивом:" << endl;
		cout << "1.Добавить строку заполненную '0' в конец  двумерного массива " << endl;
		cout << "2.Добавить строку заполненную '0' в начало двумерного массива" << endl;
		cout << "3.Добавить строку заполненную '0' в двумерный массив по указанному индексу" << endl;
		cout << "4.Удалить  строку с конца двумерного массива" << endl;
		cout << "5.Удалить  строку с начала двумерного массива" << endl;
		cout << "6.Удалить  строку из двумерного массива по указанному индексу" << endl;
		cout << "0.Выход" << endl;
		cin >> numMenu;

		switch (numMenu)
		{
		case 0:
			break;
		case 1:
			system("cls");
			push_row_back(arr, m, n);
			Print(arr, m, n);
			break;
		case 2:
			system("cls");
			push_row_front(arr, m, n);
			Print(arr, m, n);
			break;
		case 3:
			cout << "Введите номер строки для вставки: "; cin >> numPos;
			if (numPos > m)
			{
				cout << "ОШИБКА - Не верный номер!!!";
				continue;
			}
			system("cls");
			insert_row(arr, m, n, numPos);
			Print(arr, m, n);
			break;
		case 4:
			system("cls");
			pop_row_back(arr, m, n);
			Print(arr, m, n);
			break;
		case 5:
			system("cls");
			pop_row_front(arr, m, n);
			Print(arr, m, n);
			break;
		case 6:
			cout << "Введите номер строки для удаления: "; cin >> numPos;
			if (numPos > m)
			{
				cout << "ОШИБКА - Не верный номер!!!";
				continue;
			}
			system("cls");
			erase_row(arr, m, n, numPos);
			Print(arr, m, n);
			break;
		default:
			cout << "ERROR - Нет такого номера задания!!!" << endl;
			break;
		}
	} while (numMenu != 0);
	Clear(arr, m);
}
//--------------------------------------------------------------------------
// Создаем массив указателей, и сохраняем его адрес в указатель на указатель
int** CreateArr(int m, int n)
{
	int** arr = new int* [m] {};
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n] {};
	}
	return arr;
}
//--------------------------------------------------------------------------
// Заполняем двумерный динамический массив случайными числами
void FillRand(int** arr, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
//--------------------------------------------------------------------------
// Вывод двумерного динамического массива
void Print(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
}
//--------------------------------------------------------------------------
// Удаление исходного динамического массива
void Clear(int** arr, int m)
{
	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}
//--------------------------------------------------------------------------
// Добавить строку заполненную '0' в конец  двумерного массива
void push_row_back(int**& arr, int& m, const int n)
{
	int** buffer = CreateArr(m + 1, n);
	for (int i = 0; i < m; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[m] = new int[n] {};
	m++;
}
//--------------------------------------------------------------------------
// Добавить строку заполненную '0' в начало двумерного массива
void push_row_front(int**& arr, int& m, const int n)
{
	int** buffer = CreateArr(m + 1, n);
	for (int i = 0; i < m; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = new int[n] {};
	m++;
}
//--------------------------------------------------------------------------
// Добавить строку заполненную '0' в двумерный массив по указанному индексу"
void insert_row(int**& arr, int& m, int n, int numPos)
{
	int** buffer = CreateArr(m + 1, n);
	for (int i = 0; i < m; i++)
	{
		(i < numPos ? buffer[i] : buffer[i + 1]) = arr[i];
	}
	delete[] arr;
	arr = buffer;
	m++;
}
//--------------------------------------------------------------------------
// Удалить строку с конца двумерного массива
void pop_row_back(int**& arr, int& m, const int n)
{
	int** buffer = CreateArr(--m, n);
	for (int i = 0; i < m; i++)
	{
		buffer[i] = arr[i];
	}
	//delete[] arr[m];
	delete[] arr;
	arr = buffer;
}
//--------------------------------------------------------------------------
// Удалить строку с начала двумерного массива
void pop_row_front(int**& arr, int& m, const int n)
{
	int** buffer = CreateArr(--m, n);
	for (int i = 0; i < m; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
}
//--------------------------------------------------------------------------
// Удалить строку из двумерного массива по указанному индексу
void erase_row(int**& arr, int& m, int n, int numPos)
{
	int** buffer = CreateArr(m - 1, n);
	for (int i = 0; i < m; i++)
	{
		buffer[i] = i < numPos ? arr[i] : arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	m--;
}