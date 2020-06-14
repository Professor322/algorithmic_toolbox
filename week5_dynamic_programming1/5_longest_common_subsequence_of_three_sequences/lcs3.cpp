#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
using std::vector;

vector<int> find_subseq(vector<int> &a, vector<int> &b) {
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
	vector<int> subsequence(dp[n - 1][m - 1]);
	int i = n - 1;
	int j = m - 1;
	for (int k = subsequence.size() - 1; k >= 0; --k) {
		while (a[i - 1] != b[j - 1]) {
			if (dp[i - 1][j] > dp[i][j - 1]) {
				--i;
			} else {
				--j;
			}
		}
		subsequence[k] = a[i - 1];
		--i;
		--j;
	}
	return subsequence;
}


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


int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
	vector<int> lcs = find_subseq(a, b);

	return lcs2(lcs, c);
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
