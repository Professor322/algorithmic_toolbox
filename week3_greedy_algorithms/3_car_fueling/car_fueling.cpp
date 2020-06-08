#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
	int counter = 0;
	int can_travel = tank;
	int i = 0;

	while (i < stops.size()) {
		if (can_travel >= dist) {
			return counter;
		}
		int prev = i;
		while (i + 1 < stops.size() && can_travel - stops[i + 1] >= 0) {
			i++;
		}
		if (i == prev) {
			break ;
		}
		if (i < stops.size()) {
			can_travel = stops[i] + tank;
			counter++;
		}
	}

    return -1;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n + 1);
    stops[0] = 0;
    for (size_t i = 1; i < stops.size(); ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
