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
const double EPS = 1e-12;
const double PI = acos(-1.0);
const int INF = INT_MAX/10;

class BuildingHeightsEasy {
public:
int minimum( int M, vector <int> heights ) {
	int size = heights.size();
	sort(ALL(heights));
	int ans = INF;
	FOR(i, M-1, size - 1) {
		int cost = 0;
		FOR(j, i - M + 1, i) {
			cost += (heights[i] - heights[j]);
		}
		ans = min(ans, cost);
	}
	return ans;
}
};



// Powered by FileEdit
// Powered by moj 4.18 [modified TZTester]
// Powered by CodeProcessor
