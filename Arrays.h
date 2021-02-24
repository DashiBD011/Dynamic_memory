#pragma once
#include"Arrays.cpp"

template<typename T> void push_back_mutable(T*& arr, int& c, int value);
template<typename T> void push_front_mutable(T*& arr, int& c, int value);
template<typename T> void insert(T*& arr, int& c, int index, int value);

template<typename T> void pop_back(T*& arr, int& c);
template<typename T> void pop_front(T*& arr, int& c);
template<typename T> void erase(T*& arr, int& c, int index);

template<typename T> void push_row_back(T**& arr, int& m, const int n);
template<typename T> void push_row_front(T**& arr, int& m, const int n);
template<typename T> void insert_row(T**& arr, int& m, const int n, int index);

template<typename T> void pop_row_back(T**& arr, int& m, const int n);
template<typename T> void pop_row_front(T**& arr, int& m, const int n);
template<typename T> void erase_row(T**& arr, int& m, const int n, int index);

template<typename T> void push_col_back(T** arr, const int m, int& n);
template<typename T> void push_col_front(T** arr, const int m, int& n);
template<typename T> void insert_col(T** arr, const int m, int& n, int index);

template<typename T> void pop_col_back(T** arr, const int m, int& n);
template<typename T> void pop_col_front(T** arr, const int m, int& n);
template<typename T> void erase_col(T** arr, const int m, int& n, int index);

