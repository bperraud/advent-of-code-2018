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

	struct moment {
		int day;
		int hour;
		int minute;
		int id;

		bool operator<(const moment& other) const {
			if (day < other.day) return true;
			if (day > other.day) return false;
			if (hour < other.hour) return true;
			if (hour > other.hour) return false;
			return minute < other.minute;
		}
	};

	int repose_record() {
		vector<moment> v;
		for (string s; getline(cin, s);) {
			int id;
			std::regex pattern(R"(\[(\d{4})-(\d{2})-(\d{2}) (\d{2}):(\d{2})\] (.+))");
			std::smatch matches;
			if (std::regex_match(s, matches, pattern)) {
				int year = stoi(matches[1]);
				int month = stoi(matches[2]);
				int day = stoi(matches[3]);
				int hour = stoi(matches[4]);
				int minute = stoi(matches[5]);
				day = year * 365 + day + (month - 1) * 30;
				if (matches[6] == "falls asleep")
					id = -1;
				else if (matches[6] == "wakes up")
					id = -2;
				else{
					regex pattern("Guard #(\\d+) begins shift");
					string s = matches[6];
					std::smatch matchs;
					if (regex_match(s, matchs, pattern))
						id = stoi(matchs[1]);
				}
				moment m = {day, hour, minute, id};
				v.insert(v.begin(), m);
			}
		}

		sort(v.begin(), v.end());
		unordered_map<int, std::array<int, 61>> map;
		int current_guard ;
		int fall_asleep;
		int max_sleep_id = -1;
		for (int i = 0; i < v.size(); i++) {
			if (v[i].id > 0)
				current_guard = v[i].id;
			else if (v[i].id == -1)
				fall_asleep = v[i].minute;
			else if (v[i].id == -2) {
				map[current_guard][60] += v[i].minute - fall_asleep;
				if (map[current_guard][60] > map[max_sleep_id][60])
					max_sleep_id = current_guard;
				for (int minute = fall_asleep; minute < v[i].minute; minute++)
					map[current_guard][minute] += 1;
			}
		}

		auto array = map[max_sleep_id];
		auto max_iterator = std::max_element(array.begin(), array.end() - 1);
		return (std::distance(array.begin(), max_iterator)) * max_sleep_id;
	}
};

int main() {

	Solution s;
    std::cout << s.repose_record() << std::endl;
}
