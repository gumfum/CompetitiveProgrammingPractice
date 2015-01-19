#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <utility>
#include <functional>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <fstream>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n) FOR(i,0,(n)-1)
const int INF = INT_MAX / 10;

class TheConsecutiveIntegersDivTwo {
public:
	int find(vector <int> numbers, int k) {
		sort(ALL(numbers));
		int ans = INF;
		if (k == 1) {
			ans = 0;
		}
		else {
			int size = numbers.size();
			REP(i, size - 1) {
				ans = min(ans, (numbers[i + 1] - numbers[i] - 1));
			}
		}

		return ans;
	}
};



// Powered by FileEdit
// Powered by moj 4.18 [modified TZTester]
// Powered by CodeProcessor
