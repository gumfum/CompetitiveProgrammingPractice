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
const double EPS = 1e-12;
const double PI = acos(-1.0);
const int INF = INT_MAX / 10;

class LightSwitchingPuzzle {
public:
	int minFlips(string state) {
		int size = state.size();
		int minpos = INF;
		REP(i, size) {
			if (state[i] == 'Y') {
				minpos = i;
				break;
			}
		}
		int ans = 0;
		if (minpos == INF) {
			return ans;
		}

		while (minpos != INF) {
			ans++;
			for (int i = minpos; i < size; i += (minpos + 1)) {
				if (state[i] == 'Y') {
					state[i] = 'N';
				}
				else {
					state[i] = 'Y';
				}
			}
			minpos = INF;
			REP(i, size) {
				if (state[i] == 'Y') {
					minpos = i;
					break;
				}
			}
		}

		return ans;
	}
};



// Powered by FileEdit
// Powered by moj 4.18 [modified TZTester]
// Powered by CodeProcessor