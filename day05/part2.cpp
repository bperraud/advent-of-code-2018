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
#include <limits.h>

using namespace std;

class Solution {
public:

	int solution(string input_str) {
		std::vector<int> myArray(26);
    	std::iota(myArray.begin(), myArray.end(), 97);
		int min_len = INT_MAX;
		for (int num : myArray) {
			int react = reacting(input_str, num);
			if ( react < min_len )
				min_len = react;
		}
		return min_len;
	}

	int reacting(string input_str, char a) {
		int i = 0;

		while (input_str[i]) {
			if ( a == tolower(input_str[i])) {
				input_str.erase(i, 1);
				if (i > 0)
					i--;
			}
			else
				i++;
		}
		return reacting_total(input_str);
	}

	int reacting_total(string &input_str) {
		int i = 0;
		while (input_str[i]) {
			if (abs(input_str[i] - input_str[i + 1]) == 32) {
				input_str.erase(i, 2);
				if (i > 0)
					i--;
			}
			else
				i++;
		}
		return input_str.length();
	}
};

int main(int argc, char **argv) {

	Solution s;
	if (argc == 2)
    	cout << s.solution(argv[1]) << endl;
}
