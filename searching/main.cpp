#include <iostream>
#include "./binary-search.cpp" // import your sorting function here

int main() {
	int unsortedArray[] = {0};
	int sortedArray[] = {-1, 5, 6, 18, 19, 25, 46, 78, 102, 114};

	int length = sizeof(sortedArray) / sizeof(sortedArray[0]);
	
	int target = 18;
	int result = BinarySearch(sortedArray, length, target); // call sorting function here

	if (result == -1) std::cout << "not found" << std::endl;
	else std::cout << target << " is at index: " << result << std::endl;
	
	return 0;
}