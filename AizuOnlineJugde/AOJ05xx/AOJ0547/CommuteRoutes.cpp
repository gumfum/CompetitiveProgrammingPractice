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
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string toStr(T x) { ostringstream sout; sout << x; return sout.str(); }
typedef vector<int> vi;
typedef vector<vi>  vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n) FOR(i,0,(n)-1)
const double EPS = 1e-10;
const double PI = acos(-1.0);
const int INF = INT_MAX / 10;

const int MOD = 100000;

int main() {
	int w, h;
	while (cin >> w >> h, w) {
		vector<vvi> dp(h, vvi(w, vi(4)));
		// 0:horizontal 1:vertical

		dp[0][0][0] = 1;
		FOR(i, 1, h - 1) {
			dp[i][0][3] = 1;
		}
		FOR(i, 1, w - 1) {
			dp[0][i][0] = 1;
		}

		FOR(i, 1, h - 1) {
			FOR(j, 1, w - 1) {
				dp[i][j][0] = (dp[i][j - 1][0] + dp[i][j - 1][2]) % MOD;
				dp[i][j][1] = dp[i - 1][j][0] % MOD;
				dp[i][j][2] = dp[i][j - 1][3] % MOD;
				dp[i][j][3] = (dp[i - 1][j][1] + dp[i - 1][j][3]) % MOD;
			}
		}

		int ans = 0;
		REP(i, 4) {
			ans += dp[h - 1][w - 1][i];
		}

		cout << ans%MOD << endl;
	}
}