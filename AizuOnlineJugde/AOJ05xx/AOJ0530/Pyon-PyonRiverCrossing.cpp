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
const double EPS = 1e-12;
const double PI = acos(-1.0);
const int INF = INT_MAX/10;

struct state {
	pii p;
	int c, j;
	state(pii p, int c, int j) : p(p), c(c), j(j) {};
	bool operator<(const state &o)const {
		return o.c<c;
	}
};

int risk(int cd, int nd, int dx) {
	return (cd+nd)*dx;
}

int stone[150][1000];
int field[150][1000][80];

int main() {
	int n, m;
	while(cin >> n >> m, n) {
		REP(i, 150) {
			REP(j, 1000) {
				stone[i][j] = -1;
			}
		}
		int maxx = 0;
		REP(i, n) {
			int k;
			cin >> k;
			REP(j, k) {
				int x, d;
				cin >> x >> d;
				stone[i][x-1] = d;
				maxx = max(maxx, x);
			}
		}

		REP(i, 150) {
			REP(j, 1000) {
				REP(k, 80) {
					field[i][j][k] = INT_MAX;
				}
			}
		}
		priority_queue<state> Q;
		REP(i, maxx) {
			if(stone[0][i] != -1) {
				field[0][i][0] = 0;
				Q.push(state(pii(0, i), 0, 0));
			}
		}
		if(n > 1 && m > 0) {
			REP(i, maxx) {
				if(stone[1][i] != -1) {
					field[1][i][1] = 0;
					Q.push(state(pii(1, i), 0, 1));
				}
			}
		}	

		int ans = INT_MAX;
		while(!Q.empty()) {
			state st = Q.top();
			Q.pop();

			int y = st.p.first, x = st.p.second;
			if(y+2 == n && st.j < m) {
				ans = min(ans, st.c);
				continue;
			}

			if(y+1 == n) {
				ans = min(ans, st.c);
				continue;
			}

			REP(i, maxx) {
				if(stone[y+1][i] != -1) {
					int nc = st.c+risk(stone[y][x], stone[y+1][i], abs(x-i));
					if(nc < field[y+1][i][st.j]) {
						field[y+1][i][st.j] = nc;
						Q.push(state(pii(y+1, i), nc, st.j));
					}
				}
			}

			if(st.j < m && y+2 < n) {
				REP(i, maxx) {
					if(stone[y+2][i] != -1) {
						int nc = st.c+risk(stone[y][x], stone[y+2][i], abs(x-i));
						if(nc < field[y+2][i][st.j+1]) {
							field[y+2][i][st.j+1] = nc;
							Q.push(state(pii(y+2, i), nc, st.j+1));
						}
					}
				}
			}
		}

		cout << ans << endl;
	}
}