#include <iostream>
#include <vector>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;
    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

std::vector<long long> PisanoPeriod(long long m) {
	std::vector<long long> result;
	long long previous = 0, current = 1;
	result.push_back(0); result.push_back(1);

	for (int i = 0; i < m * m; ++i) {
		long long temp = (previous + current) % m;
		previous = current; current = temp;
		if (previous == 0 && current == 1) {
			result.pop_back();
			return result;
		}
		result.push_back(current);
	}
	return result;
}

int fibonacci_sum_fast(long long n) {
	if (n <= 1) {
		return n;
	}
	std::vector<long long> pisano_period = PisanoPeriod(10);
	std::vector<long long> sums(pisano_period.size() + 1);
	sums[0] = 0;
	for (int i = 1; i < sums.size(); ++i) {
		sums[i] = (sums[i - 1] + pisano_period[i - 1]) % 10;
	}
	long long size = sums.size();
	long long full_periods = n / size;
	long long partial_period = n % pisano_period.size() + 1;

	return (full_periods * sums[size - 1] +
				sums[partial_period]) % 10;
}

void test() {
	for (int i = 0; i < 30; ++i) {
		if (fibonacci_sum_fast(i) == fibonacci_sum_naive(i)) {
			std::cout << "OK" << '\n';
		} else {
			std::cout << "Failed: " << i << '\n';
		}
	}
	std::cout << "Done\n";
}

int main() {
    long long n = 0;
//    test();
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
}
