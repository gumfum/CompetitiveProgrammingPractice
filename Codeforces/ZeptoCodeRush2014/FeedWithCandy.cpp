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
	int n, x;
	cin >> n >> x;
	vvi candy(n, vi(3));
	REP(i, n) {
		REP(j, 3) {
			cin >> candy[i][j];
		}
	}

	int ans = 0;
	REP(t, 2) {
		vi used(n);
		int ct = t, cx = x, ca = 0;
		while (true) {
			int cp = -1, cm = -1;
			REP(i, n) {
				if (!used[i] && candy[i][0] == ct && candy[i][1] <= cx && cm < candy[i][2]) {
					cp = i;
					cm = candy[i][2];
				}
			}

			if (cp == -1) {
				break;
			}
			else {
				ca++;
				cx += candy[cp][2];
				ct = 1 - ct;
				used[cp] = 1;
			}
		}
		ans = max(ans, ca);
	}

	cout << ans << endl;
	return 0;
}