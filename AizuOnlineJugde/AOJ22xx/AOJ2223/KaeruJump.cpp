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

struct state {
	int x, y, dir;
	vs field;
	string command;
	state(int x, int y, int dir, vs field, string command) : x(x), y(y), dir(dir), field(field), command(command) {};
};

int getDir(char c) {
	switch(c) {
	case 'U':
		return 3;
	case 'D':
		return 1;
	case 'L':
		return 2;
	case 'R':
		return 0;
	}
}

char getDirChar(int dir) {
	switch(dir) {
	case 0:
		return 'R';
	case 1:
		return 'D';
	case 2:
		return 'L';
	case 3:
		return 'U';
	}
}

bool isProperXY(int x, int y, int H, int W) {
	return 0 <= x && x < W && 0 <= y && y < H;
}

bool isEmptyField(vs field) {
	REP(i, field.size()) {
		REP(j, field[i].size()) {
			if(field[i][j] != '.') {
				return false;
			}
		}
	}
	return true;
}

int main() {
	int H, W;
	cin >> H >> W;
	vs field(H);

	int x, y, dir;
	REP(i, H) {
		cin >> field[i];
		REP(j, field[i].size()) {
			if(field[i][j] != '.' && field[i][j] != 'o') {
				x = j;
				y = i;
				dir = getDir(field[i][j]);
				field[i][j] = '.';
			}
		}
	}

	string ans;
	stack<state> S;
	S.push(state(x, y, dir, field, ""));
	while(!S.empty()) {
		state st = S.top();
		S.pop();

		if(isEmptyField(st.field)) {
			ans = st.command;
			break;
		}

		FOR(d, -1, 1) {
			int nx = st.x, ny = st.y, ndir = (st.dir+d+4)%4;
			bool update = true;
			while(st.field[ny][nx] != 'o') {
				nx += dx[ndir], ny += dy[ndir];
				if(!isProperXY(nx, ny, H, W)) {
					update = false;
					break;
				}
			}

			if(update) {
				vs nfield = st.field;
				nfield[ny][nx] = '.';
				string ncommand = st.command;
				ncommand.push_back(getDirChar(ndir));
				S.push(state(nx, ny, ndir, nfield, ncommand));
			}
		}
	}

	cout << ans << endl;
	return 0;
}