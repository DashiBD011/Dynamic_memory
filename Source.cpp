#include<iostream>
using namespace std;

void Fillrand(int arr[], const int n);
void Print(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "ru");
	int n;
	cout << "Введите размер массива:"; cin >> n;

	int m = n + 1;
	int* arr = new int[n];
	int* brr = new int[m];

	Fillrand(arr, n);
	Print(arr, n);

	for (int i = 0, i_buffer=0; i < n && i_buffer < m; i++,i_buffer++)
	{
		brr[i_buffer] = arr[i];
	}

	int value;
	cout << "Введите доп значение: "; cin >> value;
	brr[m-1] = value;

	Print(brr, m);

	delete[]arr;
	delete[]brr;
}

void Fillrand(int arr[], const int n)
{
	for ( int i = 0; i <n; i++)	arr[i] = rand() % 100;
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)	cout << arr[i] << "\t";
	cout <<"\n"<< endl;
}
