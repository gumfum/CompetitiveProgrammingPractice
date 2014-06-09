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
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v;}
template<class T> inline string toStr(T x) { ostringstream sout; sout << x; return sout.str();}
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
const int INF = INT_MAX/10;

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

void showLand(vs land) {
	REP(i, land.size()) {
		cout << land[i] << endl;
	}
}

struct state {
	int t, x, y;
	vs land;
	state(int t, int x, int y, vs land) : t(t), x(x), y(y), land(land) {};
};

bool isProperXY(int x, int y, int n) {
	return 0<=x && x<n && 0<=y && y<n;
}

bool isDisinfectedLand(vs land, int n) {
	REP(i, n) {
		REP(j, n) {
			if(land[i][j] == '#') {
				return false;
			}
		}
	}
	return true;
}

vs updateLand(vs land, int n) {
	vs nland = land;
	REP(x, n) {
		REP(y, n) {
			int count = 0;
			REP(d, 8) {
				int nx = x+dx[d], ny = y+dy[d];
				if(isProperXY(nx, ny, n) && land[ny][nx] != '.') {
					count++;
				}
			}
			if(land[y][x] == '#' && (count == 2 || count == 3)) {
				nland[y][x] = '#';
			} else if(land[y][x] == '.' && count == 3) {
				nland[y][x] = '#';
			} else if(land[y][x] != '@') {
				nland[y][x] = '.';
			}
		}
	}
	return nland;
}

int main() {
	int n;
	while(cin >> n, n) {
		vs land(n);
		int sx, sy;
		REP(i, n) {
			cin >> land[i];
			REP(j, n) {
				if(land[i][j] == '@') {
					sy = i, sx = j;
				}
			}
		}

		queue<state> Q;
		Q.push(state(0, sx, sy, land));
		map<vs, int> memo;
		memo[land] = 1;
		int ans = -1;
		while(!Q.empty()) {
			state st = Q.front();
			Q.pop();

			if(isDisinfectedLand(st.land, n)) {
				ans = st.t;
				break;
			}

			REP(d, 8) {
				int nx = st.x+dx[d], ny = st.y+dy[d];
				if(isProperXY(nx, ny, n) && st.land[ny][nx] == '.') {
					vs nland = st.land;
					nland[st.y][st.x] = '.';
					nland[ny][nx] = '@';
					nland = updateLand(nland, n);
					if(!memo[nland]) {
						memo[nland] = 1;
						Q.push(state(st.t+1, nx, ny, nland));
					}
				}
			}
		}

		cout << ans << endl;
	}

	return 0;
}