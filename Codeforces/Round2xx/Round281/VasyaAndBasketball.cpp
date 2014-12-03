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
	int n;
	cin >> n;
	vi a(n);
	REP(i, n) {
		cin >> a[i];
	}
	int m;
	cin >> m;
	vi b(m);
	REP(i, m) {
		cin >> b[i];
	}

	vvi dist(n+m, vi(2));
	REP(i, n) {
		dist[i][0] = a[i];
		dist[i][1] = 0;
	}
	REP(i, m) {
		dist[i + n][0] = b[i];
		dist[i + n][1] = 1;
	}

	sort(ALL(dist));

	int ansa = 3 * n, ansb = 3 * m, ansd = ansa - ansb;
	int tmpa = ansa, tmpb = ansb, tmpd = tmpa - tmpb;
	REP(i, n + m) {
		if (dist[i][1] == 1) {
			tmpb--;
		}
		else {
			tmpa--;
		}
		tmpd = tmpa - tmpb;
		if (tmpd > ansd) {
			ansa = tmpa, ansb = tmpb, ansd = tmpd;
		}
		else if (tmpd == ansd && tmpa > ansa) {
			ansa = tmpa, ansb = tmpb, ansd = tmpd;
		}
	}

	cout << ansa << ":" << ansb << endl;

	return 0;
}