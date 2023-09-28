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
#include <fstream>
#include <iostream>

using namespace std;

	struct Point {
		pair<int, int> pos;
		pair<int, int> velocity;
	};

	std::ostream& operator<<(std::ostream& os, const Point& obj) {
		cout << obj.pos.first << ", " << obj.pos.second << endl;
		cout << "velocity : " << endl;
		cout << obj.velocity.first << ", " << obj.velocity.second << endl;
		return os;
	}

	bool operator< (const Point &a, const Point &b)  {
		if (a.pos.first < b.pos.first) return true;
		if (a.pos.first > b.pos.first) return false;
		return a.pos.second < b.pos.second;
	}

// 2040
class Solution {

private:
	vector<Point> vec;

	Point top_left;
	Point bot_right;

	int last_diag;

	set<pair<int, int>> lst_st;

	friend ostream& operator<<(ostream &out, const Solution& s);

	int distance_diag(set<pair<int, int>> st) {
		return std::sqrt(std::pow(top_left.pos.first - bot_right.pos.first, 2) + std::pow(top_left.pos.second - bot_right.pos.second, 2));
	}

public:

	int solution(string input) {

		istringstream input_stream(input);
		for (string line; getline(input_stream, line);) {
			std::regex pattern("position=<\\s*(-?\\d+),\\s*(-?\\d+)> velocity=<\\s*(-?\\d+),\\s*(-?\\d+)>");
			smatch matchs;
			if (regex_match(line, matchs, pattern)) {
				pair<int, int> pos = make_pair(stoi(matchs[1]), stoi(matchs[2]));
				pair<int, int> velocity = make_pair(stoi(matchs[3]), stoi(matchs[4]));
				vec.push_back(Point{pos, velocity}) ;
			}
		}

		last_diag = std::numeric_limits<int>::max();
		while (true)
		{
			set<pair<int, int>> st;

			for (auto &elem : vec) {
				elem.pos.first += elem.velocity.first;
				elem.pos.second += elem.velocity.second;
				st.insert(elem.pos);
			}

			auto min_x = min_element(st.begin(), st.end(),
			[](pair<int, int> a, pair<int, int> b) {
				return a.first < b.first ;
			});
			top_left.pos.first = min_x->first;
			auto min_y = min_element(st.begin(), st.end(),
			[](pair<int, int> a, pair<int, int> b) {
				return a.second < b.second ;
			});
			top_left.pos.second = min_x->second;
			auto max_x = max_element(st.begin(), st.end(),
			[](pair<int, int> a, pair<int, int> b) {
				return a.first < b.first ;
			});
			bot_right.pos.first = max_x->first;
			auto max_y = max_element(st.begin(), st.end(),
			[](pair<int, int> a, pair<int, int> b) {
				return a.second < b.second ;
			});
			bot_right.pos.second = max_y->second;

			int actual_diag = distance_diag(st);
			if (actual_diag > last_diag) {
				cout << "--------MESSAGE----------" << endl;
				cout << *this << endl;
				break;
			}

			last_diag = actual_diag;
			lst_st = st;
		}

		return -1;
	}
};

ostream & operator<<(ostream &out, const Solution& s) {

	cout << s.top_left << endl;
	cout << s.bot_right << endl;

	for (int y = s.top_left.pos.second; y < s.bot_right.pos.second ; y++)
	{
		for (int x = s.top_left.pos.first ; x < s.bot_right.pos.first; x++) {
			if (s.lst_st.count(make_pair(x, y)))
				cout << "#" ;
			else
				cout << "." ;
		}
		cout << "\n" ;
	}
	return out;
}

int main(int argc, char **argv) {
	Solution s;

	cout << "------------" << endl;
	cout << s.solution(argv[1]) << endl;
}
