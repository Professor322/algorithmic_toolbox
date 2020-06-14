#include <iostream>
#include <vector>
#include <limits>

using namespace std;


int get_change(int m) {
	vector<int> coins{1, 3, 4};
	vector<int> dp(m + 1, numeric_limits<int>::max());
	dp[0] = 0;
	for (int i = 1; i < dp.size(); ++i) {
		for (int coin : coins) {
			if (i - coin < 0) {
				continue;
			}
			dp[i] = min(dp[i - coin] + 1, dp[i]);
		}
	}


	return dp[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';

  return 0;
}
