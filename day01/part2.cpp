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

class Solution {
public:
	int solution(std::string input, std::unordered_set<int> set, int sum) {
		int i = 0;
		while (i < input.length()) {
			std::string value;
			while (input[i] != '\n' && (i < input.length())) {
				value.append(1, input[i]);
				i++;
			}
			if (set.count(sum))
				return sum;
			set.insert(sum);
			sum += atoi(value.c_str());
			i++;
		}
		return solution(input, set, sum);
	}
};

int main(int argc , char **argv) {
	Solution s;

	std::unordered_set<int> set;
	std::cout << s.solution(argv[1], set, 0) << std::endl;
}
