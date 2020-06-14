#include <iostream>
#include <string>
#include <vector>


using namespace std;
using std::string;

int edit_distance(const string &str1, const string &str2) {
	int n = str1.size(), m = str2.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

	for (int i = 0; i < n + 1; ++i) {
		dp[i][0] = i;
	}
	for (int i = 0; i < m + 1; ++i) {
		dp[0][i] = i;
	}
	for (int i = 1; i < n + 1; ++i) {
		for (int j = 1; j < m + 1; ++j) {
			int mismatch = dp[i - 1][j - 1];
			int insertion = dp[i - 1][j] + 1;
			int deletion = 	dp[i][j - 1] + 1;

			dp[i][j] = min(mismatch + static_cast<int>(str1[i - 1] != str2[j - 1]), insertion);
			dp[i][j] = min(dp[i][j], deletion);

		}
	}

	return dp[n][m];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
