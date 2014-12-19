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
const double EPS = 1e-12;
const double PI = acos(-1.0);
const int INF = INT_MAX / 10;

int pos1(vi v, int p) {
	return lower_bound(ALL(v), p) - v.begin() - 1;
}

int pos2(vi v, int p) {
	return upper_bound(ALL(v), p) - v.begin() - 1;
}

int main() {
	int n, m;
	cin >> n >> m;
	vi x(n), y(n);
	vector<pii> xy(n);
	REP(i, n) {
		cin >> x[i] >> y[i];
		xy[i] = pii(x[i], y[i]);
	}

	x.push_back(INT_MIN);
	y.push_back(INT_MIN);
	sort(ALL(x));
	sort(ALL(y));
	x.erase(unique(ALL(x)), x.end());
	y.erase(unique(ALL(y)), y.end());

	int xsize = x.size(), ysize = y.size();
	vi xpos(n), ypos(n);
	REP(i, n) {
		REP(j, xsize) {
			if (xy[i].first == x[j]) {
				xpos[i] = j;
				break;
			}
		}
	}
	REP(i, n) {
		REP(j, ysize) {
			if (xy[i].second == y[j]) {
				ypos[i] = j;
				break;
			}
		}
	}

	vvi field(ysize, vi(xsize));
	REP(i, n) {
		field[ypos[i]][xpos[i]]++;
	}
	FOR(i, 1, ysize - 1) {
		FOR(j, 1, xsize - 1) {
			field[i][j] += field[i][j - 1];
		}
	}
	FOR(i, 1, ysize - 1) {
		FOR(j, 1, xsize - 1) {
			field[i][j] += field[i - 1][j];
		}
	}

	REP(i, m) {
		int xm1, ym1, xm2, ym2;
		cin >> xm1 >> ym1 >> xm2 >> ym2;
		int xp1 = pos1(x, xm1), yp1 = pos1(y, ym1), xp2 = pos2(x, xm2), yp2 = pos2(y, ym2);
		cout << field[yp2][xp2] - field[yp1][xp2] - field[yp2][xp1] + field[yp1][xp1] << endl;
	}
}
