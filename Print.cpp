#include<iostream>
using std::cout;
using std::cin;
using std::endl;

template<typename T>
void Print(T arr[], const int c)
{
	for (int i = 0; i < c; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

template<typename T>
void Print(T** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << *(*(arr + i) + j) << "\t";
		}
		cout << endl;
	}
	cout << endl;
}
