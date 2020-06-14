#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <tuple>
#include <limits>

using namespace std;

long long eval(long long a, char op, long long b) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

pair<long long, long long> findMinMax(int i, int j,
		vector<vector<long long>>& m, vector<vector<long long>>& M,
		const string& ops) {
	pair<long long, long long> res;
	res.first = numeric_limits<long long>::max();
	res.second = numeric_limits<long long>::min();

	for (int k = i; k < j; ++k) {
		long long a = eval(M[i][k], ops[k], M[k + 1][j]);
		long long b = eval(M[i][k], ops[k], m[k + 1][j]);
		long long c = eval(m[i][k], ops[k], M[k + 1][j]);
		long long d = eval(m[i][k], ops[k], m[k + 1][j]);
		res.first = min(res.first, min(min(a, b), min(c, d)));
		res.second = max(res.second, max(max(a, b), max(c, d)));
	}

	return res;
}

long long get_maximum_value(const string &exp) {
	int n = exp.size() / 2 + 1;
	vector<vector<long long>> M(n, vector<long long>(n, 0));
	vector<vector<long long>> m(n, vector<long long>(n, 0));
	string ops;
	for (int i = 0, j = 0; i < exp.size(); i += 2, ++j) {
		M[j][j] = exp[i] - '0';
		m[j][j] = exp[i] - '0';
	}
	for (int i = 1; i < exp.size(); i += 2) {
		ops.push_back(exp[i]);
	}
	for (int s = 0; s < n - 1; ++s) {
		for (int i = 0; i < n - s - 1; ++i) {
			int j = i + s + 1;
			auto MinMax = findMinMax(i, j, m, M, ops);
			m[i][j] = MinMax.first;
			M[i][j] = MinMax.second;
		}
	}


  return M[0][n - 1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
