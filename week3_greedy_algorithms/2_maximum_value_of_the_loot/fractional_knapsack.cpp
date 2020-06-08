#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using std::vector;
using std::pair;
using std::cout;

double get_optimal_value(int capacity, vector<int>& weights, vector<int>& values) {
  double value = 0.0;
  vector<pair<int, int>> ratio(values.size());
  for (int i = 0; i < ratio.size(); ++i) {
  	ratio[i].first = values[i];
  	ratio[i].second = weights[i];
  }
  sort(ratio.begin(), ratio.end(),
  		[](const pair<int, int>& lhs, const pair<int, int>& rhs) {
  			double value_lhs = lhs.first;
  			double weight_lhs = lhs.second;
  			double value_rhs = rhs.first;
  			double weight_rhs = rhs.second;
  			return value_lhs / weight_lhs > value_rhs / weight_rhs;
  });

  for (int i = 0; i < values.size(); ++i) {
  	if (capacity == 0) {
  		return value;
  	}
  	double a = std::min(capacity, ratio[i].second);
  	value += a * (static_cast<double>(ratio[i].first) /
  			static_cast<double >(ratio[i].second));

  	capacity -= static_cast<int>(a);

  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
