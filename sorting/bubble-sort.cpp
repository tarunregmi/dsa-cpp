#include <type_traits>

/**
 * @param array array (int || char || float || double) to be sort using Bubble Sort algorithm
 * @param n lenght of array
 */
template <typename T, typename = std::enable_if_t<
	std::is_same<T, int>::value || 
	std::is_same<T, char>::value ||
	std::is_same<T, float>::value ||
	std::is_same<T, double>::value
>>
void BubbleSort(T array[], int n) {
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n-i; j++) {         // run (n-1) + (n-2) + (n-3) + ... + 2 + 1 times
			if (array[j+1] < array[j]) {        // swap
				int small = array[j+1];         // store small value 
				array[j+1] = array[j];
				array[j] = small;
			}
		}
	}
}