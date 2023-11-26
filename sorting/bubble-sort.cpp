#include <type_traits>
#include "../utils/display.cpp"


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

	DisplayArray(array, n);
}


int main() {
	int ia[] = {53, 78, 12, 89, 34, 78};
	char ca[] = {'I', '\'', 'a', 'm', 'F'};
	float fa[] = {1.2, 3.5, -5, .6, 9};
	int n = 0;

	n = sizeof(ia) / sizeof(ia[0]);
	BubbleSort(ia, n);
	
	n = sizeof(ca) / sizeof(ca[0]);
	BubbleSort(ca, n);

	n = sizeof(fa) / sizeof(fa[0]);
	BubbleSort(fa, n);

	return 0;
}