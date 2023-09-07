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

	int index_end_tree(vector<int> &tree, int index, int &sum) {
		int child = tree[index];
		int data = tree[index + 1];
		int last_child_index = index + 1;
		while (child--) {
			last_child_index = index_end_tree(tree, last_child_index + 1, sum);
		}
		for (int i = last_child_index + 1; i <= last_child_index + data; i++) {
			sum += tree[i];
		}
		return last_child_index + data;
	}

	void solution(string input_tree) {
		vector<int> tree;
		int v;

		istringstream input_stream(input_tree);
		for (string line; getline(input_stream, line);) {
			istringstream iss(line);
			int v;
			while (iss >> v) {
				tree.push_back(v);
			}
		}
		int sum = 0;
		index_end_tree(tree, 0, sum);
		cout << sum << endl;
	}
};

int main(int argc, char **argv) {
	Solution s;
	s.solution(argv[1]);
}
