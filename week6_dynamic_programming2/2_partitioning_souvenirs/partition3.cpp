#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>


using namespace std;
using std::vector;

vector<vector<int>> optimal_weight(int W, const vector<int> &w) {
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


	return values;
}

int findSubset(int size, vector<int>& A) {
	vector<vector<int>> f1 = optimal_weight(size, A);
	int i = f1.size() - 1, j = f1[0].size();
	while (f1[i][j] != 0) {

		if (f1[i][j] == f1[i - 1][j]) {
		}
	}

	return f1[f1.size() - 1][f1[0].size() - 1];
}

int partition3(vector<int>& A) {
	int sum = accumulate(A.begin(), A.end(), 0);
	vector<bool> used(A.size(), true);
	if (sum % 3) {
		return 0;
	}
	return findSubset(sum / 3, used, A) == sum / 3 &&
	       findSubset(sum / 3, used ,A) == sum / 3 &&
	       findSubset(sum / 3, used ,A) == sum / 3;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (int& elem : A) {
  	cin >> elem;
  }
  std::cout << partition3(A) << '\n';
}
