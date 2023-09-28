
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

int main() {
    int res(0);
	int n = 0;
	while (std::cin >> n)
	{
		res += n;
	}
    std::cout << res << std::endl;
}
