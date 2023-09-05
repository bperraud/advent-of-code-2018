
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


struct claim {
	int x;
	int y;
	int width;
	int height;
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
		std::unordered_set<position> visited;
		std::unordered_set<position> overlap;

		unordered_map<int, claim> claims;

		for (string s; getline(cin, s);) {
			std::regex pattern("#(\\d+) @ (\\d+),(\\d+): (\\d+)x(\\d+)");
			std::smatch matches;
			if (std::regex_match(s, matches, pattern)) {
				int id = stoi(matches[1]);
				int x = stoi(matches[2]);
				int y = stoi(matches[3]);
				int width = stoi(matches[4]);
				int height = stoi(matches[5]);
				claims[id] = {x, y, width, height};
				for (int i = x; i < x + width ; i++) {
					for (int j = y; j < y + height ; j++) {
						struct position pos {i, j};
						if (!visited.count(pos)) {
							visited.insert(pos);
						}
						else {
							overlap.insert(pos);
						}
					}
				}
			}
		}

		for (auto it = claims.begin(); it != claims.end(); it++) {
			bool b_overlap = false;
			struct claim c = it->second;
			for (int i = c.x; i < c.x + c.width ; i++) {
				for (int j = c.y; j < c.y + c.height ; j++) {
					struct position pos {i, j};
					if (overlap.count(pos))
						b_overlap = true;
				}
			}
			if (!b_overlap)
				return it->first;
		}
		return -1;
	}
};

int main(int argc , char **argv) {
	Solution s;

	cout << s.solution() << endl;
}
