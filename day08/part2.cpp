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

	std::pair<int, int> index_end_tree(vector<int> &tree, int index) {
		int child = tree[index];
		int data = tree[index + 1];
		int last_child_index = index + 1;
		int sum = 0;

		unordered_map<int, int> node_reference;
		for (int i = 0 ; i < child; i++) {
			pair<int, int> res = index_end_tree(tree, last_child_index + 1);
			last_child_index = res.first;
			node_reference[i] = res.second;
		}
		for (int i = last_child_index + 1; i <= last_child_index + data; i++) {
			if (child) {
				if (node_reference.count(tree[i] - 1))
					sum += node_reference[tree[i] - 1];
			}
			else
				sum += tree[i];
		}
		return make_pair(last_child_index + data, sum);
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
		cout << index_end_tree(tree, 0).second << endl;
	}
};

int main(int argc, char **argv) {
	Solution s;
	s.solution(argv[1]);
}
