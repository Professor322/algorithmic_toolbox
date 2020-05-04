#include <iostream>
#include <vector>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    std::vector<int> nums(n + 1);
    nums[0] = 0;
    nums[1] = 1;

    for (int i = 2; i <= n; ++i) {
    	nums[i] = (nums[i - 1] + nums[i - 2]) % 10;
    }
    return nums[n];
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_naive(n);
    std::cout << c << '\n';
    return 0;
}
