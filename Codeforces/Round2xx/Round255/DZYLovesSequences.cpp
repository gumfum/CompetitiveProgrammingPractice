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
	int n;
	cin >> n;
	vi a(n + 2);
	FOR(i, 1, n) {
		cin >> a[i];
	}
	a[0] = -INF, a[n + 1] = INF;
	vi r(n + 2), l(n + 2);
	for (int i = n; i >= 1; i--) {
		if (a[i] < a[i + 1]) {
			r[i] = r[i + 1] + 1;
		}
		else {
			r[i] = 1;
		}
	}
	FOR(i, 1, n) {
		if (a[i - 1] < a[i]) {
			l[i] = l[i - 1] + 1;
		}
		else {
			l[i] = 1;
		}
	}

	int ans = 1;
	FOR(i, 1, n) {
		if (i == 1) {
			ans = max(ans, r[i + 1] + 1);
		}
		else if (i == n) {
			ans = max(ans, l[i - 1] + 1);
		}
		else {
			if (a[i - 1] + 1 < a[i + 1]) {
				ans = max(ans, l[i - 1] + 1 + r[i + 1]);
			}
			else {
				ans = max(ans, max(l[i - 1] + 1, r[i + 1] + 1));
			}
		}
	}

	cout << ans << endl;
	return 0;
}