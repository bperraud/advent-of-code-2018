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

using namespace std;

class Solution {
public:

	struct Point {
		int i;
		int j;

		int distance (const Point &b) {
			return abs(i - b.i) + abs(j - b.j);
		}
	};

	friend std::ostream& operator<<(std::ostream& out, const Point& s) {
        out << "{ " << s.i << ", " << s.j << " }";
        return out;
    }

	// finite = haut gauche droite bas +

	int distance (const Point &a, const Point &b) {
		return abs(a.i - b.i) + abs(a.j - b.j);
	}

	int solution() {
		for (string s; getline(cin, s);){
			regex pattern("(\\d+), (\\d+)");
			smatch matches;
			if (regex_match(s, matches, pattern)) {
				Point p = { stoi(matches[1]), stoi(matches[2]) };
				cout << p << endl;
			}
		}

		return 0;
	}
};

int main(int argc, char **argv) {

	// start 1455
	// start after subject 1504
	Solution s;
	cout << s.solution() << endl;
}
