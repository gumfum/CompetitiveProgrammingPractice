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
#include <list>
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

int main() {
	string s;
	while (cin >> s, s != "0") {
		int length = s.length(), ans = 0;

		vvi dp(length, vi(11, 0));
		REP(i, length) {
			int num = s[i] - '0';
			if (i != 0) {
				REP(j, 11) {
					dp[i][(j * 10 + num) % 11] += dp[i - 1][j];
				}
			}
			if (num != 0) {
				dp[i][num]++;
			}
			ans += dp[i][0];
		}

		cout << ans << endl;
	}

	return 0;
}