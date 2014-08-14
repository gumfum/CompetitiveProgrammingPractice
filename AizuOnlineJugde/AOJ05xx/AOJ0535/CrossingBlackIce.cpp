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

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int m, n;
vvi field;

bool isProperXY(int x, int y) {
	return 0 <= x && x < m && 0 <= y && y < n;
}

int dfs(int x, int y) {
	int turn = 0;
	REP(d, 4) {
		int nx = x + dx[d], ny = y + dy[d];
		if (isProperXY(nx, ny) && field[ny][nx] == 1) {
			field[ny][nx] = 0;
			turn = max(turn, dfs(nx, ny));
			field[ny][nx] = 1;
		}
	}
	return turn + 1;
}

int main() {
	while (cin >> m >> n, m) {
		field = vvi(n, vi(m));

		REP(i, n) {
			REP(j, m) {
				cin >> field[i][j];
			}
		}

		int ans = 0;
		REP(y, n) {
			REP(x, m) {
				if (field[y][x] == 1) {
					field[y][x] = 0;
					ans = max(ans, dfs(x, y));
					field[y][x] = 1;
				}
			}
		}

		cout << ans << endl;
	}
}