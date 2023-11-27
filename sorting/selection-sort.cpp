#include <type_traits>

/**
 * @param array array (int || char || float || double) to be sort using Selection Sort algorithm
 * @param n lenght of array
 */
template <typename T, typename = std::enable_if_t<
	std::is_same<T, int>::value || 
	std::is_same<T, char>::value ||
	std::is_same<T, float>::value ||
	std::is_same<T, double>::value
>>
void SelectionSort(T array[], int n) {
	for (int i = 0; i < n; i++) {
		int smallestItemIndex = i;
		for (int j = i+1; j < n; j++) {
			if (array[j] < array[smallestItemIndex]) smallestItemIndex = j;
		}

		if (smallestItemIndex != i) {
			T tmp = array[i];
			array[i] = array[smallestItemIndex];
			array[smallestItemIndex] = tmp;
		}
	}
}