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
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n) FOR(i,0,(n)-1)

class MountainRanges {
public:
	int countPeaks(vector <int> heights) {
		int size = heights.size();
		if (size == 1) {
			return 1;
		}
		int ans = 0;
		REP(i, size) {
			if (i == 0) {
				if (heights[i] > heights[i + 1]) {
					ans++;
				}
			}
			else if (i == size - 1) {
				if (heights[i] > heights[i - 1]) {
					ans++;
				}
			}
			else {
				if (heights[i] > heights[i + 1] && heights[i] > heights[i - 1]) {
					ans++;
				}
			}
		}
		return ans;
	}
};



// Powered by FileEdit
// Powered by moj 4.18 [modified TZTester]
// Powered by CodeProcessor
