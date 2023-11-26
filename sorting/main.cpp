#include "../utils/display.cpp"
#include "./bubble-sort.cpp" // import your algorithms here

int main() {
	int arrayLength = 0;

	int intArray[] = {53, 78, 12, 89, 34, 78};
	char charArray[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!'};
	float floatArray[] = {1.2, 3.5, -5, .6, 9, 45.234};

	arrayLength = sizeof(charArray) / sizeof(charArray[0]);
	BubbleSort(charArray, arrayLength); // call your function here
	DisplayArray(charArray, arrayLength); // display sorted array

	return 0;
}