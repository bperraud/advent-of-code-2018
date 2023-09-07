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

class Solution {

public:

	void solution() {

		map<char, set<char>> waiting_letter;
		set<char> left_letters;
		set<char> right_letters;

		for (string s; getline(cin, s);) {
			regex pattern("Step (.) must be finished before step (.) can begin.");
			std::smatch matchs ;
			if (regex_match(s, matchs, pattern)) {
				char left = matchs[1].str()[0];
				char right = matchs[2].str()[0];
				left_letters.insert(left);
				right_letters
				.insert(right);
				waiting_letter[right].insert(left);
			}
		}

		vector<char> available_letter;
		for (const auto left : left_letters) {
			if (!right_letters.count(left))
				available_letter.push_back(left);
		}

		vector<char> letter_to_do;
		while (!available_letter.empty()) {
			auto min_elem = min_element(available_letter.begin(), available_letter.end());
			char next_letter = *min_elem;

			//cout << endl;
			cout << "[ " ;
			for ( const auto elem : available_letter) {
				cout << elem << " ";
			}
			cout << " ]" << endl;

			available_letter.erase(min_elem);
			letter_to_do.push_back(next_letter);
			for (auto &key : waiting_letter) {
				if (key.second.count(next_letter)) {
					key.second.erase(next_letter);
					if (key.second.empty())
						available_letter.push_back(key.first);
				}
			}
		}
		//cout << endl;
		cout << "[ " ;
		for ( const auto elem : letter_to_do) {
			cout << elem << " ";
		}
		cout << " ]" << endl;

		// 5 later
		//char - 4 = time to do char
		// - 60 for test purpose
		int nb_workers = 2;
		int total_time = 0;

		std::array<char, 2> worker_on_task('');

		for (const auto &elem : worker_on_task) {
			if (elem == '') {

			}
		}

		//while (!letter_to_do.empty()) {

		//}

	}
};

int main(int argc, char **argv) {

	Solution s;
	s.solution();
}
