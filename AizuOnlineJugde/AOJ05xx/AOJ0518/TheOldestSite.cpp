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

bool existPt[5001][5001];

bool validSuffix(int x) {
	return !(x < 0 || 5000 < x);
}

bool existPillar(pii a, pii b) {
	int dx = b.first - a.first, dy = b.second - a.second;
	if (validSuffix(a.first + dy) && validSuffix(a.second - dx) && validSuffix(b.first + dy) && validSuffix(b.second - dx)) {
		return existPt[a.first + dy][a.second - dx] && existPt[b.first + dy][b.second - dx];
	}
	else {
		return false;
	}
}

int area(pii a, pii b) {
	int dx = b.first - a.first, dy = b.second - a.second;
	return dx*dx + dy*dy;
}

int main() {
	int n;
	while (cin >> n, n) {
		memset(existPt, false, sizeof(existPt));
		int x, y;
		vector<pii> pts(n);
		REP(i, n) {
			cin >> x >> y;
			pts[i] = pii(x, y);
			existPt[x][y] = true;
		}

		int ans = 0;
		REP(i, n) {
			REP(j, n) {
				if (existPillar(pts[i], pts[j])) {
					ans = max(ans, area(pts[i], pts[j]));
				}
			}
		}

		cout << ans << endl;
	}
}