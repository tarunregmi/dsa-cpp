#include <iostream>

/**
 * @param array
 * @param n lenght of array
 */
template <typename T>
void DisplayArray(T array[], int n) {
	for (int i=0; i<n; i++) std::cout << array[i] << ", ";
	std::cout << std::endl;
}