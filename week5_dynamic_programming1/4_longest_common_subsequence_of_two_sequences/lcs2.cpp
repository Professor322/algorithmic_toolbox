#include <iostream>
#include <vector>

using namespace std;
using std::vector;

int lcs2(vector<int> &a, vector<int> &b) {
	int n = a.size() + 1, m = b.size() + 1;
	vector<vector<int>> dp(n, vector<int>(m, 0));

	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < m; ++j) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}


	return dp[n - 1][m - 1];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
