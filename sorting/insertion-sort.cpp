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
void InsertionSort(T array[], int n) {
	int i, j;
	T pivot;

	for (i=1; i < n; i++) {
		pivot = array[i];
		for (j=i-1; j >= 0; j--) {
			if (pivot < array[j]) array[j+1] = array[j]; // right shift
			else break;
		}
		array[j+1] = pivot;
	}
}