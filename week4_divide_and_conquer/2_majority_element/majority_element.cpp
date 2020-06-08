#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;


int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];

  int mid = left + (right - left) / 2;

  int l = get_majority_element(a, left, mid);
  int r = get_majority_element(a, mid, right);

  if (l == r) {
  	return l;
  }
  int count_l = std::count(a.begin() + left, a.begin() + mid, l);

  int count_r = std::count(a.begin() + mid, a.begin() + right, r);


  return count_l < count_r ? r : l;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  int ans = get_majority_element(a, 0, a.size());
  std::cout << (count(a.begin(), a.end(), ans) > a.size() / 2) << '\n';
}
