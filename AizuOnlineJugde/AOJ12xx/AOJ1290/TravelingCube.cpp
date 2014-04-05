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

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

struct dice {
	int top, bottom, north, south, east, west;
	dice(int top, int bottom, int north, int south, int east, int west) :
		top(top), bottom(bottom), north(north), south(south), east(east), west(west) {};
};

struct state {
	dice d;
	int x, y, r, s;
	state(dice d, int x, int y, int r, int s) : d(d), x(x), y(y), r(r), s(s) {};
};

struct dice rotate(struct dice old, int dir) {
	struct dice res = old;
	switch(dir) {
	case 0:
		res.top = old.west;
		res.west = old.bottom;
		res.bottom = old.east;
		res.east = old.top;
		break;
	case 1:
		res.top = old.north;
		res.north = old.bottom;
		res.bottom = old.south;
		res.south = old.top;
		break;
	case 2:
		res.top = old.east;
		res.east = old.bottom;
		res.bottom = old.west;
		res.west = old.top;
		break;
	case 3:
		res.top = old.south;
		res.south = old.bottom;
		res.bottom = old.north;
		res.north = old.top;
		break;
	default:
		break;
	}

	return res;
}

int conv(char c) {
	switch(c) {
	case 'r':
		return 0;
	case 'c':
		return 1;
	case 'g':
		return 2;
	case 'm':
		return 3;
	case 'b':
		return 4;
	case 'y':
		return 5;
	}
	return -1;
}

bool isProperXY(int x, int y, int d, int w) {
	return 0<=x && x<w && 0<=y && y<d;
}

typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;

void show_dice(dice d) {
	cout << "top    : " << d.top << endl;
	cout << "bottom : " << d.bottom << endl;
	cout << "north  : " << d.north << endl;
	cout << "south  : " << d.south << endl;
	cout << "east   : " << d.east << endl;
	cout << "west   : " << d.west << endl;
}

int main() {
	int w, d;
	while(cin >> w >> d, w) {
		vs c(d);
		int sx, sy;
		REP(i, d) {
			cin >> c[i];
			REP(j, w) {
				if(c[i][j] == '#') {
					sx = j, sy = i;
					c[i][j] = 'w';
				}
			}
		}
		string v;
		cin >> v;

		queue<state> Q;
		dice od(conv('r'), conv('c'), conv('g'), conv('m'), conv('b'), conv('y')); 
		Q.push(state(od, sx, sy, 0, 0));
		vector<vvvvi> visited(d, vvvvi(w, vvvi(6, vvi(6, vi(6, 0)))));
		visited[sy][sx][od.top][od.north][0] = 1;
		int ans = -1;
		while(!Q.empty()) {
			state st = Q.front();
			Q.pop();

			REP(dir, 4) {
				int nx = st.x+dx[dir], ny = st.y+dy[dir];
				if(!isProperXY(nx, ny, d, w)) {
					continue;
				}
				int nr = st.r, ns = st.s+1;
				dice nd = rotate(st.d, dir);

				if(c[ny][nx] == 'w') {
					if(!visited[ny][nx][nd.top][nd.north][nr]) {
						visited[ny][nx][nd.top][nd.north][nr] = 1;
						Q.push(state(nd, nx, ny, nr, ns));
					}
				} else if(conv(c[ny][nx]) == nd.top && conv(v[nr]) == nd.top) {
					nr++;
					if(nr == 6) {
						ans = ns;
						goto show;
					}
					if(!visited[ny][nx][nd.top][nd.north][nr]) {
						visited[ny][nx][nd.top][nd.north][nr] = 1;
						Q.push(state(nd, nx, ny, nr, ns));
					}
				}
			}
		}

show:
		if(ans == -1) {
			cout << "unreachable" << endl;
		} else {
			cout << ans << endl;
		}
	}
}