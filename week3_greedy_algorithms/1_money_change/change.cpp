#include <iostream>

int get_change(int m) {
	int counter = 0;
	const int TENS = 10;
	const int FIVERS = 5;
	const int ONES = 1;

	while (m != 0 && m - TENS >= 0) {
		m -= TENS;
		counter++;
	}
	while (m != 0 && m - FIVERS >= 0) {
		m -= FIVERS;
		counter++;
	}
	while (m != 0 && m - ONES >= 0) {
		m -= ONES;
		counter++;
	}
	return counter;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
