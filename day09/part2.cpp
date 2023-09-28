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
private:
	long marble_index, current_marble_index ;
	vector<long> player_score;
	vector<long> marbles;
	friend ostream& operator<<(ostream &out, const Solution& s);

public:

	long solution(string input) {
		long players, points;

		istringstream input_stream(input);
		for (string line; getline(input_stream, line);) {
			regex pattern("(\\d+) players; last marble is worth (\\d+) points");
			smatch matchs;
			if (regex_match(line, matchs, pattern)) {
				players = stoi(matchs[1]);
				points = stoi(matchs[2]);
			}
		}
		player_score.resize(players, 0);
		marble_index = 0;
		current_marble_index = 0;
		while (1) {
			for (int player = 0; player < players ; player++ ) {
				if (marble_index > points) {
					return *max_element(player_score.begin(), player_score.end());
				}
				if (marble_index == 0 || marble_index == 1) {
					marbles.push_back(marble_index);
					current_marble_index = marble_index;
				}
				else if (!(marble_index % 23)) {
					current_marble_index = (current_marble_index - 7 + marbles.size()) % marbles.size();
					player_score[player] += marbles[current_marble_index] + marble_index;
					marbles.erase(marbles.begin() + current_marble_index);
				}
				else {
					current_marble_index = (current_marble_index + 2) % marbles.size();
					marbles.insert(marbles.begin() + current_marble_index, marble_index);
				}
				marble_index++;
			}
		}
		return -1;
	}
};

ostream & operator<<(ostream &out, const Solution& s) {
		cout << "current marble index : " << s.current_marble_index << endl;
		cout << "marble_index : " << s.marble_index << endl;

		cout << " [ ";
		for (auto const &elem : s.marbles) {
			cout << elem << " " ;
		}
		cout << " ] ";
		return out;
}

int main(int argc, char **argv) {
	Solution s;

	cout << s.solution(argv[1]) << endl;
}
