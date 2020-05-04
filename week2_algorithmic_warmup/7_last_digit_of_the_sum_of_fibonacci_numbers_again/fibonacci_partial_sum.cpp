#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

vector<long long> PisanoPeriod(long long m) {
	vector<long long> result;
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


int fibonacci_sum_fast(long long n, const vector<long long>& sums) {
	if (n <= 1) {
		return n;
	}
	long long size = sums.size();
	long long full_periods = n / size;
	long long partial_period = n % (sums.size()) + 1;

	return (full_periods * sums[size - 1] +
			sums[partial_period]) % 10;
}

int get_fibonacci_partial_sum_fast(long long n, long long m) {
	std::vector<long long> pisano_period = PisanoPeriod(10);
	std::vector<long long> sums(pisano_period.size() + 1);
	sums[0] = 0;
	for (int i = 1; i < sums.size(); ++i) {
		sums[i] = (sums[i - 1] + pisano_period[i - 1]) % 10;
	}
//	for (auto sum : sums ) {
//		std::cout << sum << ' ';
//	}
//	std::cout << '\n';
	auto it = fibonacci_sum_fast(m, sums);
	auto i2 = fibonacci_sum_fast(n, sums);
	return abs(fibonacci_sum_fast(m + 1, sums) - fibonacci_sum_fast(n, sums));
}

void test() {
	for (int i = 0; i < 20; ++i) {
		for (int j = i + 1; j < 20; ++j) {
			if (get_fibonacci_partial_sum_fast(i, j) ==
			get_fibonacci_partial_sum_naive(i, j)) {
				std::cout << "OK\n";
			} else {
				std::cout << "Failed: " << i << ' ' << j << '\n';
				std::cout << get_fibonacci_partial_sum_naive(i, j) << "!="
				<< get_fibonacci_partial_sum_fast(i, j) << '\n';
			}
		}
	}
	std::cout << "Done\n";
}

int main() {
    long long from, to;
	test();
    std::cin >> from >> to;
	std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
