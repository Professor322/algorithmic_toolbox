#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits>

using namespace std;

using std::vector;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

void backtrack(vector<int>& ans, vector<int>& dp, int i) {
	if (i == 0) {
		return ;
	}
	ans.push_back(i);
	if (!(i % 2) && dp[i / 2] + 1 == dp[i]) {
		backtrack(ans, dp, i / 2);
	} else if (!(i % 3) && dp[i / 3] + 1 == dp[i]) {
		backtrack(ans, dp, i / 3);
	} else if (i - 1 >= 0 && dp[i - 1] + 1 == dp[i]) {
		backtrack(ans, dp, i - 1);
	}
}

vector<int> fast_optimal_sequence(int n) {
	vector<string> ops{"x2", "x3", "+1"};
	vector<int> dp(n + 1, numeric_limits<int>::max());
	dp[0] = 0;
	for (int i = 1; i < dp.size(); ++i) {
		for (string& op : ops) {
			if (op == "x2" && !(i % 2)) {

				dp[i] = min(dp[i / 2] + 1, dp[i]);

			} else if (op == "x3" && !(i % 3)) {

				dp[i] = min(dp[i / 3] + 1, dp[i]);

			} else if (op == "+1" && i - 1 >= 0) {

				dp[i] = min(dp[i - 1] + 1, dp[i]);

			}
		}
	}
	vector<int> ans;
	ans.reserve(dp[n]);
	backtrack(ans, dp, n);
	reverse(ans.begin(), ans.end());
	return ans;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = fast_optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
