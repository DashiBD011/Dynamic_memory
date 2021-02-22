#include"dynamic_memory.h"

template<typename T>
void Random(T& variable)
{
	if (typeid(variable) == typeid(int))
	{
		variable = rand() % 100;
	}
	else if (typeid(variable) == typeid(float) || typeid(variable) == typeid(double))
	{
		variable = double(rand() % 10000) / 100;
	}
	else if (typeid(variable) == typeid(char))
	{
		variable = rand();
	}
	else
	{
		variable = T();
	}
}

template<typename T>
void FillRand(T arr[], const int c)
{
	for (int i = 0; i < c; i++)
	{
		//arr[i] = rand() % 100;
		Random(arr[i]);
	}

}

template<typename T>
void FillRand(T** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//arr[i][j] = rand() % 100;
			Random(arr[i][j]);
		}
	}

}

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

template<typename T>
T** Allocate(const int m, const int n)
{
	T** arr = new T * [m] {};
	for (int i = 0; i < m; i++)arr[i] = new T[n];
	return arr;
}

template<typename T>
void Clear(T** arr, const int m)
{
	for (int i = 0; i < m; i++)	delete arr[i];
	delete[] arr;
}

template<typename T>
void push_back_mutable(T*& arr, int& c, int value)
{
	T* buffer = new T[c + 1]{};
	for (int i = 0; i < c; i++)	buffer[i] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[c] = value;
	c++;

}

template<typename T>
void push_front_mutable(T*& arr, int& c, int value)
{
	T* buffer = new T[c + 1]{};
	for (int i = 0; i < c; i++)	buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	c++;
}

template<typename T>
void insert(T*& arr, int& c, int index, int value)
{
	if (index >= c)return;
	T* buffer = new T[++c];
	for (int i = 0; i < c; i++)
	{
		i < index ? buffer[i] = arr[i] : buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = value;
}

template<typename T>
void pop_back(T*& arr, int& c)
{
	T* buffer = new T[--c];
	for (int i = 0; i < c; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;

}

template<typename T>
void pop_front(T*& arr, int& c)
{
	T* buffer = new T[--c];
	for (int i = 0; i < c; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
}

template<typename T>
void erase(T*& arr, int& c, int index)
{
	if (index >= c)return;
	T* buffer = new T[--c];
	for (int i = 0; i < c; i++)
	{
		i < index ? buffer[i] = arr[i] : buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
}


template<typename T>
void push_row_back(T**& arr, int& m, const int n)
{

	//1)������� �������� ������ ����������
	T** buffer = new T * [m + 1];
	//2)�������� ������ ����� ��������� ������� � �������� ������ ����������
	for (int i = 0; i < m; i++)	buffer[i] = arr[i];

	delete[]arr;
	arr = buffer;
	arr[m] = new T[n]{ 0 };
	m++;
}

template<typename T>
void push_row_front(T**& arr, int& m, const int n)
{
	T** buffer = new T * [m + 1]{};
	for (int i = 0; i < m; i++)	buffer[i + 1] = arr[i];

	delete[]arr;
	arr = buffer;
	arr[0] = new T[n]{};
	m++;
}

template<typename T>
void insert_row(T**& arr, int& m, const int n, int index)
{
	if (index > m)return;
	T** buffer = new T * [m + 1]{};

	for (int i = 0; i < index; i++)	buffer[i] = arr[i];

	for (int i = index; i < m; i++)	buffer[i + 1] = arr[i];

	delete[]arr;
	arr = buffer;
	arr[index] = new T[n]{};
	m++;
}

template<typename T>
void pop_row_back(T**& arr, int& m, const int n)
{
	T** buffer = new T * [--m]{};
	for (int i = 0; i < m; i++)	buffer[i] = arr[i];

	delete[] arr[m];
	delete[]arr;
	arr = buffer;
}

template<typename T>
void pop_row_front(T**& arr, int& m, const int n)
{
	T** buffer = new T * [--m]{};
	for (int i = 0; i < m; i++)	buffer[i] = arr[i + 1];

	delete[] arr[0];
	delete[]arr;
	arr = buffer;
}

template<typename T>
void erase_row(T**& arr, int& m, const int n, int index)
{
	if (index > m)return;
	T** buffer = new T * [--m]{};

	for (int i = 0; i < index; i++)	buffer[i] = arr[i];

	for (int i = index; i < m; i++)	buffer[i] = arr[i + 1];

	delete[] arr[index];
	delete[]arr;
	arr = buffer;
}

template<typename T>
void push_col_back(T** arr, const int m, int& n)
{

	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n + 1]{};
		for (int j = 0; j < n; j++)	buffer[j] = arr[i][j];

		delete arr[i];
		arr[i] = buffer;
	}
	n++;
}

template<typename T>
void push_col_front(T** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{

		T* buffer = new T[n + 1]{};
		for (int j = 0; j < n; j++)	buffer[j + 1] = arr[i][j];

		delete arr[i];
		arr[i] = buffer;
	}
	n++;

}

template<typename T>
void insert_col(T** arr, const int m, int& n, int index)
{
	if (index > n)return;
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n + 1]{};

		for (int j = 0; j < index; j++)	buffer[j] = arr[i][j];

		for (int j = index; j < n; j++)	buffer[j + 1] = arr[i][j];

		delete arr[i];
		arr[i] = buffer;
	}

	n++;

}

template<typename T>
void pop_col_back(T** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n - 1]{};
		for (int j = 0; j < n - 1; j++) buffer[j] = arr[i][j];

		delete arr[i];
		arr[i] = buffer;
	}
	n--;
}

template<typename T>
void pop_col_front(T** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n - 1]{};
		for (int j = 0; j < n - 1; j++)	buffer[j] = arr[i][j + 1];

		delete arr[i];
		arr[i] = buffer;
	}
	n--;
}

template<typename T>
void erase_col(T** arr, const int m, int& n, int index)
{
	if (index > n)return;
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n - 1]{};

		for (int j = 0; j < index; j++)	buffer[j] = arr[i][j];

		for (int j = index; j < n - 1; j++) buffer[j] = arr[i][j + 1];

		delete arr[i];
		arr[i] = buffer;
	}
	n--;
}