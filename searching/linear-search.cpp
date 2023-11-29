#include <type_traits>

/**
 * @param array array of item of data-type (int || char || float || double)
 * @param n lenght of array
 * @param target data to search for
 * @return int 
 */
template <typename T, typename = std::enable_if_t<
	std::is_same<T, int>::value || 
	std::is_same<T, char>::value ||
	std::is_same<T, float>::value ||
	std::is_same<T, double>::value
>>
int LinearSearch(T array[], int n, T target) {
	for (int i=0; i < n; i++) if (target == array[i]) return i;
	return -1; // if target not found
}