//
// Created by professor on 6/8/20.
//

#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie();

	int n;

	cin >> n;
	vector<int> ans(n);
	for (int& an : ans) {
		cin >> an;
	}
	sort(ans.begin(), ans.end());
	int m;

	cin >> m;
	for (int i = 0; i < m; ++i) {
		int target;
		cin >> target;
		auto it = lower_bound(ans.begin(), ans.end(), target);
		if (it == ans.end()) {
			it -= 1;
		}
		cout << *it << '\n';
	}
	return 0;
}