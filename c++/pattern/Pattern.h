#pragma once
#include <iostream>
#include <typeinfo>
#include <string>

template<typename T>

class Matrix {
	T* arr = new T;
	int len;
public:
	Matrix(T* arr, int len):arr(arr), len(len){}
	T* fillArr() {
		std::cin >> this->len;
		T* arr = new T[len];
		for (int i = 0; i < this->len; i++) {
			std::cout << "print new element: ";std::cin >> arr[i];
		}
		return arr;
	}
	void printArr() {
		for (int i = 0; i < this->len; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}
	void sort() {
		if (typeid(arr[0]) == typeid(int) || typeid(arr[0]) == typeid(double) || typeid(arr[0]) == typeid(float)) {
			T tmp = 0;
			for (int i = 0; i < this->len; i++) {
				for (int j = 1; j < this->len - i - 1; j++) {
					if (arr[j] < arr[j - 1]) {
						tmp = arr[j];
						arr[j] = arr[j - 1];
						arr[j - 1] = tmp;
					}
				}
			}
		}
		else if (typeid(arr[0]) == typeid(std::string)) {
			T tmp1;
			for (int i = 0; i < this->len; i++) {
				for (int j = 1; j < this->len - i - 1; j++) {
					if (arr[j] < arr[j - 1]) {
						tmp1 = arr[j];
						arr[j] = arr[j - 1];
						arr[j - 1] = tmp1;
					}
				}
			}
		}
	}
	void Clear() {
		this->len = 0;
		delete[] this->arr;
	}
	void findMax() {
		T tmp = arr[0];
		for (int i = 0; i < this->len; i++) {
			if (tmp < arr[i]) {
				tmp = arr[i];
			}
		}
	}
	void findMin() {
		T tmp = arr[0];
		for (int i = 0; i < this->len; i++) {
			if (tmp > arr[i]) {
				tmp = arr[i];
			}
		}
	}
};