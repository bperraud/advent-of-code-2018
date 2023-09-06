#include <iostream>
#include <typeinfo>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <cmath>
#include <numeric>
#include <sstream>
#include <cstring>
#include <utility>
#include <regex>
#include <climits>

using namespace std;

struct Point {
		int i;
		int j;

		bool operator <(const Point &b) const {
			if (j < b.j) return true;
			if (j > b.j) return false;
			return i < b.i;
		}
};

ostream& operator<<(ostream& out, const Point& s) {
    out << "{ " << s.i << ", " << s.j << " }";
    return out;
}

class Solution {

private:
	int min_i, max_i, min_j, max_j;

public:

	int manhattan(const Point &a, const Point &b) {
		return abs(a.i - b.i) + abs(a.j - b.j);
	}

	int solution() {

		vector<Point> points;
		int x, y;
		char comma;

		min_i = INT_MAX;
		max_i = 0;
		min_j = INT_MAX;
		max_j = 0;

		while (cin >> x >> comma >> y) {
			points.push_back({x, y});
			min_i = min(min_i, x);
			max_i = max(max_i, x);
			min_j = min(min_j, y);
			max_j = max(max_j, y);
		}

		unordered_map<int, int> map_count;  // map closest point with his corresponding count;
		unordered_set<int> infine_point;

		for (int x = 0; x <= max_i; x++) {
			for (int y = 0; y <= max_j; y++) {
				int closest_point = -1;
				int min_distance = INT_MAX;
				bool is_tied = false;
				for (int i = 0; i < points.size(); i++) {
					int distance = manhattan(points[i], {x, y});
					if (distance < min_distance) {
						closest_point = i;
						min_distance = distance;
						is_tied = false;
					} else if (distance == min_distance) {
						is_tied = true;
					}
				}
				if (!is_tied) {
					if (x == 0 || x == max_i || y == 0 || y == max_j)
						infine_point.insert(closest_point);
					map_count[closest_point] += 1;
				}
			}
		}

		int largestFiniteArea = 0;
		for (int i = 0; i < points.size(); i++) {
			if (!infine_point.count(i))
				largestFiniteArea = max(largestFiniteArea, map_count[i]);
		}

		return largestFiniteArea;
	}
};

int main(int argc, char **argv) {

	Solution s;
	cout << s.solution() << endl;
}
