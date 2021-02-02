#include<iostream>
using namespace std;

void Fillrand(int arr[], const int n);
void Print(int arr[], const int n);

void push_back_mutable(int*& arr, int& n, int value);
void push_front_mutable(int*& arr, int& n, int value);

void insert(int*& arr, int& n, int index, int value);
void erase(int*& arr, int& n, int index);

void pop_back(int*& arr, int& n);
void pop_front(int*& arr, int& n);

//#define PUSH_BACK_MUTABLE
//#define PUSH_FRONT_MUTABLE
//#define INSERT
//#define ERASE
//#define POP_BACK
//#define POP_FRONT

void main()
{
	setlocale(LC_ALL, "ru");

	int n;
	int value;
	int index;
	cout << "Введите размер массива:"; cin >> n;
	int* arr = new int[n];

	Fillrand(arr, n);
	Print(arr, n);


#ifdef PUSH_BACK_MUTABLE
	cout << "Введите добавляемое значение: "; cin >> value;
	push_back_mutable(arr, n, value);
	Print(arr, n);
#endif // PUSH_BACK_MUTABLE


#ifdef PUSH_FRONT_MUTABLE
	cout << "Введите добавляемое значение: "; cin >> value;
	push_front_mutable(arr, n, value);
	Print(arr, n);
#endif // PUSH_FRONT_MUTABLE


#ifdef INSERT
	cout << "Введите добавляемое значение: "; cin >> value;
	cout << "Введите индекс: "; cin >> index;
	insert(arr, n, index, value);
	Print(arr, n);
#endif // INSERT

#ifdef ERASE
	cout << "Удаление значения по индексу" << endl;
	cout << "Введите индекс: "; cin >> index;
	erase(arr, n, index);
	Print(arr, n);
#endif // ERASE


#ifdef POP_BACK
	cout << "Удаление последнего значения: " << endl;
	pop_back(arr, n);
	Print(arr, n);
#endif // POP_BACK


#ifdef POP_FRONT
	cout << "Удаление первого значения: " << endl;
	pop_front(arr, n);
	Print(arr, n);
#endif // POP_FRONT

}

void Fillrand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)	arr[i] = rand() % 100;
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)	cout << arr[i] << "\t";
	cout << "\n" << endl;
}

void push_back_mutable(int*& arr, int& n, int value)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)	buffer[i] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[n] = value;
	n++;
	
}

void push_front_mutable(int*& arr, int& n, int value)
{
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)	buffer[i+1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
}

void insert(int*& arr, int& n, int index, int value)
{
	if (index >= n)return;
	int* buffer = new int[n + 1]{};
	/*for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	*/
	for (int i = 0; i < n; i++)
	{
		(i < index ? buffer[i] : buffer[i + 1]) = arr[i];
	}
	delete[]arr;
	arr = buffer;
	arr[index] = value;
	n++;
}

void erase(int*& arr, int& n, int index)
{
	if (index >= n)return;
	int* buffer = new int[--n]{};
	for (int i = 0; i < n; i++)
	{
		i < index ? buffer[i] = arr[i] : buffer[i] = arr[i + 1];
	}
	delete[]arr;
	arr = buffer;
}

void pop_back(int*& arr, int& n)
{
	int* buffer = new int[--n]{};
	for (int i = 0; i < n; i++)	buffer[i] = arr[i];
	delete[] arr;
	arr = buffer;
	
}

void pop_front(int*& arr, int& n)
{
	int* buffer = new int[--n]{};
	for (int i = 0; i < n; i++)	buffer[i] = arr[i+1];
	delete[] arr;
	arr = buffer;
	
}