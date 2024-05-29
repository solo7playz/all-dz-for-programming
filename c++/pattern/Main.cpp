#include "Pattern.h"

int main() {
	int* arr = new int[5] {7, 2, 3, 4, 5};
	std::string* arr1 = new std::string[5]{ "gadh","fdx","we","ertby","bcghchmm" };
	Matrix<int>* m1 = new Matrix<int>(arr, 5);
	Matrix<std::string>* m2 = new Matrix<std::string>(arr1, 5);
	m1->printArr();
	m1->sort();
	m1->printArr();
	m2->sort();
	m2->printArr();
}