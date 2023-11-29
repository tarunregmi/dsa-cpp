#include <iostream>

void toh(int n, char src, char help, char dest) {
	if (n == 1) {
		std::cout << "transfer disk " << n << " from " << src << " to " << dest << std::endl;
		return;
	}

	toh(n-1, src, dest, help);
	std::cout << "transfer disk " << n << " from " << src << " to " << dest << std::endl;
	toh(n-1, help, src, dest);
}

int main() {
	int n = 3;

	toh(n, 'S', 'H', 'D'); // Tower of Hanoi

	return 0;
}