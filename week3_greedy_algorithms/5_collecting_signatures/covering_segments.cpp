#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <list>
#include <algorithm>

using std::vector;
using std::list;

struct Segment {
  int start, end;
};

vector<int> optimal_points(list<Segment> &segments) {

	vector<int> points;

  segments.sort(
  [](const Segment& lhs, const Segment& rhs){
  	return lhs.end < rhs.end;
  });

  while (!segments.empty()) {
 	int point = segments.front().end;
 	segments.pop_front();
 	points.push_back(point);
 	segments.remove_if([point](const Segment& elem) {
 		return point >= elem.start && point <= elem.end;
 	});
  }

  return points;
}

int main() {
  int n;
  std::cin >> n;
  list<Segment> segments;
  for (size_t i = 0; i < n; ++i) {
  	int start, end;
  	std::cin >> start >> end;
  	segments.push_back({start, end});
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
