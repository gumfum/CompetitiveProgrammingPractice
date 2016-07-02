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
typedef vector<int> vi;
typedef vector<vi>  vvi;
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n) FOR(i,0,(n)-1)

class BiconnectedDiv1 {
public:
	int minimize(vector <int> w1, vector <int> w2) {
		int n = w1.size() + 1;
		vi dp(n, 0);
		int total = 0;
		REP(i, n - 1) {
			total += w1[i];
		}
		REP(i, n - 2) {
			total += w2[i];
		}
		FOR(i, 2, n - 2) {
			dp[i] = dp[i - 1] + w1[i - 1];
			if (i > 2) {
				dp[i] = max(dp[i], dp[i - 2] + w2[i - 2]);
			}
		}

		return total - dp[n - 2];
	}
};



// Powered by FileEdit
// Powered by moj 4.18 [modified TZTester]
// Powered by CodeProcessor

