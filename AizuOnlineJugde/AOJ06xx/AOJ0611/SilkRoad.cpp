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
const int INF = INT_MAX / 2;
const int MOD = 1000000007;

int main() {
	int N, M;
	cin >> N >> M;
	vi D(N), C(M);
	REP(i, N) {
		cin >> D[i];
	}
	REP(i, M) {
		cin >> C[i];
	}

	vvi dp(M + 1, vi(N + 1, INF));
	dp[0][0] = 0;
	REP(day, M) {
		REP(city, N) {
			dp[day + 1][city] = min(dp[day + 1][city], dp[day][city]);
			dp[day + 1][city + 1] = min(dp[day + 1][city + 1], dp[day][city] + D[city] * C[day]);
		}
	}

	int ans = INF;
	FOR(day, 0, M) {
		ans = min(ans, dp[day][N]);
	}
	cout << ans << endl;
	return 0;
}