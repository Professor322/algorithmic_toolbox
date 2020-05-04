#include <iostream>
#include <vector>
#include <cassert>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long PisanoPeriod(long long m) {
	long long previous = 0, current = 1;

	for (int i = 0; i < m * m; ++i) {
		long long temp = (previous + current) % m;
		previous = current; current = temp;
		if (previous == 0 && current == 1) {
			return i + 1;
		}
	}
	return 0;
}

long long get_fibonacci_huge_fast(long long n, long long m) {
	if (n <= 1) {
		return n % m;
	}
	long long size = n % PisanoPeriod(m);
	long long previous = 0, current = 1;
	if (size == 0) {
		return previous % m;
	}
	for (int i = 0; i < size - 1; ++i) {
		long long temp = (current + previous) % m;
		previous = current;
		current = temp;
	}

	return (current % m);
}

void test() {
	for (int i = 1; i < 20; ++i) {
		for (int j = 2; j <= 10 ; ++j) {
			if (get_fibonacci_huge_fast(i, j) ==
			get_fibonacci_huge_naive(i, j)) {
				std::cout << "OK\n";
			} else {
				std::cout << "Failed "<< i << ' ' << j << '\n';
			}
		}
	}
	std::cout << "Done\n";
}

int main() {
    long long n, m;
//    test();
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
    return 0;
}
