
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

using namespace std;

class Solution {
public:
	int solution(string input) {
		int i = 0;
		bool two_times = false;
		bool three_times = false;
		int nb_twos = 0;
		int nb_threes = 0;
		int value;
		while (i < input.length()) {
			string line;
			unordered_map<char, int> hash;
			while (input[i] != '\n' && (i < input.length())) {
				hash[input[i]] += 1;
				i++;
			}
			for (const auto& [first, second] : hash) {
				if (second == 3)
					two_times = true;
				if (second == 2)
					three_times = true;
			}
			if (two_times)
				nb_twos += 1;
			if (three_times)
				nb_threes += 1;
			two_times = false;
			three_times = false;
			i++;  // next line
		}
		return nb_twos * nb_threes;
	}
};

int main(int argc , char **argv) {
	Solution s;

	cout << s.solution(argv[1]) << endl;
}
