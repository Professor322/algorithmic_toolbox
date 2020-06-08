#include <iostream>
#include <vector>
#include <cstdlib>
#include <tuple>

using std::vector;
using std::swap;
using std::pair;

pair<int, int> partition3(vector<int> &a, int l, int r) {
  int x = a[l];
  int lt = l, gt = r, i = l + 1;

  while (i <= gt) {
  	if (a[i] < x) {
		swap(a[i], a[lt]);
		++i;
		++lt;
  	} else if (a[i] > x) {
		swap(a[i], a[gt]);
		--gt;
  	} else {
  		++i;
  	}
  }

  return {lt, gt};
}


void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  auto m = partition3(a, l, r);

  randomized_quick_sort(a, l, m.first - 1);
  randomized_quick_sort(a, m.second + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
