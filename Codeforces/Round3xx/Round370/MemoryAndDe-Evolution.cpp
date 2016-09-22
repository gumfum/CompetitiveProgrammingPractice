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

int main() {
	int x, y;
	cin >> x >> y;

	if (x == y) {
		cout << 0 << endl;
		return 0;
	}

	vi l(3, y);

	int ans = 0;
	while (!(l[0] == x && l[1] == x && l[2] == x)) {
		int nl = l[1] + l[2] - 1;
		if (nl > x) {
			nl = x;
		}
		l[0] = nl;
		sort(ALL(l));

		ans++;
	}

	cout << ans << endl;

	return 0;
}
