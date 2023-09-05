
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

using namespace std;

class Solution {
public:

	int one_char_diff (string &str1, string &str2) {
		int num = 0;
		for (int i =0 ; i < str1.length() ; i++) {
			if ( str1[i] != str2[i])
				num += 1;
		}
		return num == 1;
	}

	string solution(const string &input_str) {
		istringstream input;
		input.str(input_str);
		vector<string> v;
		for (string line; getline(input, line);)
			v.push_back(line);
		for (int i=0 ; i < v.size() ; i++) {
			for (int j= i + 1 ; j < v.size() ; j ++) {
				if ( one_char_diff(v[i], v[j]) == 1) {
					string res;
					int k = 0;
					while (v[i][k] == v[j][k])k++;
					return v[i].erase(k, 1);
				}
			}
		}
		return "";
	}
};

int main(int argc , char **argv) {
	Solution s;
	if (argc == 2)
		cout << s.solution(argv[1]) << endl;
}
