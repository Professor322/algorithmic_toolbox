#include <iostream>
#include <vector>
#include <limits>

long long MaxPairwiseProductFast(const std::vector<int>& nums) {
	int mx1_idx = -1;
	int mx1 = std::numeric_limits<int>::min();
	int n = nums.size();
	for (size_t i = 0; i < n; ++i) {
		if (nums[i] > mx1) {
			mx1 = nums[i];
			mx1_idx = i;
		}
	}
	int mx2 = std::numeric_limits<int>::min();
	for (size_t i = 0; i < n; ++i) {
		if (nums[i] > mx2 && i != mx1_idx) {
			mx2 = nums[i];
		}
	}
	return static_cast<long long>(mx1) * mx2;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProductFast(numbers) << "\n";
    return 0;
}
