#include <iostream>
#include <vector>


using namespace std;

int optimal_weight(int W, const vector<int> &w) {
	int n = w.size() + 1;
	int m = W + 1;
	vector<vector<int>> values(n, vector<int>(m, 0));

	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < m; ++j) {
			values[i][j] = values[i - 1][j];
			if (w[i - 1] <= j) {
				values[i][j] = max(values[i][j],
						values[i - 1][j - w[i - 1]] + w[i - 1]);
			}
		}
	}


	return values[n - 1][m - 1];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
