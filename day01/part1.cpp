
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
	int solution(std::string input) {
		int i = 0;
		int sum = 0;
		while (i < input.length()) {
			std::string value;
			while (input[i] != '\n' && (i < input.length())) {
				value.append(1, input[i]);
				i++;
			}
			sum += atoi(value.c_str());
			i++;
		}
		return sum;
	}
};

int main(int argc , char **argv) {
	Solution s;
	std::cout << s.solution(argv[1]) << std::endl;
}
