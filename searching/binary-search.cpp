#include <type_traits>

/**
 * @param array sorted array of item of data-type (int || char || float || double)
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
int BinarySearch(T array[], int n, T target) {
	int lb = 0;       // lower bound
	int ub = n - 1;   // upper bound
	int mp;           // mid point
	T mv;             // mid value

	while (lb <= ub) {
		mp = lb + (ub-lb)/2;
		mv = array[mp];

		if (target == mv) return mp;
		else if (target < mv) ub = mp - 1;
		else lb = mp + 1;
	}

	return -1; // if target not found
}