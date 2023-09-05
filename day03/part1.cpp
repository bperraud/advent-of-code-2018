
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

struct position {
    int i;
    int j;

    bool operator==(const position& other) const {
        return i == other.i && j == other.j;
    }
};

namespace std {
    template <>
    struct hash<position> {
        std::size_t operator()(const position& p) const {
            return std::hash<int>()(p.i) ^ std::hash<int>()(p.j);
        }
    };
}

using namespace std;
class Solution {
public:

	int solution() {
		int res = 0;
		std::unordered_set<position> visited;
		std::unordered_set<position> overlap;
		for (string s; getline(cin, s);) {
			std::regex pattern("(\\d+),(\\d+): (\\d+)x(\\d+)");
			std::smatch matches;
			if (std::regex_search(s, matches, pattern)) {
				int x = stoi(matches[1]);
				int y = stoi(matches[2]);
				int width = stoi(matches[3]);
				int height = stoi(matches[4]);
				for (int i = x; i < x + width ; i++) {
					for (int j = y; j < y + height ; j++) {
						struct position pos {i, j};
						if (!visited.count(pos))
							visited.insert(pos);
						else {
							if (!overlap.count(pos))
								res += 1;
							overlap.insert(pos);
						}
					}
				}
			}
		}
		return res;
	}
};

int main(int argc , char **argv) {
	Solution s;

	cout << s.solution() << endl;
}
