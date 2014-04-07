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

int dx[] = {1, 0, -1, 0, 2, 0, -2, 0, 0};
int dy[] = {0, 1, 0, -1, 0, 2, 0, -2, 0};
int cx[] = {0, 1, 0, 1};
int cy[] = {0, 0, 1, 1};

struct state {
	int d, x, y, ul, ur, dl, dr;
	state(int d, int x, int y, int ul, int ur, int dl, int dr) : 
		d(d), x(x), y(y), ul(ul), ur(ur), dl(dl), dr(dr) {};
};

bool isProperXY(int x, int y) {
	return 0<=x && x<=2 && 0<=y && y<=2;
}

bool isProperF(int ul, int ur, int dl, int dr) {
	return ul<7 && ur<7 && dl<7 && dr<7;
}

bool visited[366][3][3][7][7][7][7];

int main() {
	int N;
	while(cin >> N, N) {
		vector<vvi> f(N, vvi(4, vi(4)));
		REP(i, N) {
			REP(j, 4) {
				REP(k, 4) {
					cin >> f[i][j][k];
				}
			}
		}

		stack<state> S;
		memset(visited, false, sizeof(visited));
		bool ok = true;
		REP(c, 4) {
			if(f[0][1+cy[c]][1+cx[c]]) {
				ok = false;
				break;
			}
		}
		if(ok) {
			S.push(state(1, 1, 1, 1, 1, 1, 1));
			visited[1][1][1][1][1][1][1] = true;
		}
		bool finished = false;
		while(!S.empty()) {
			state st = S.top();
			S.pop();
			
			if(st.d == N) {
				finished = true;
				break;
			}

			int nd = st.d+1;
			REP(d, 9) {
				int nx = st.x+dx[d], ny = st.y+dy[d];
				if(isProperXY(nx, ny)) {
					ok = true;
					REP(c, 4) {
						if(f[st.d][ny+cy[c]][nx+cx[c]]) {
							ok = false;
							break;
						}
					}
					int nul = st.ul+1, nur = st.ur+1, ndl = st.dl+1, ndr = st.dr+1;
					if(nx == 0) {
						if(ny == 0) {
							nul = 0;
						} else if(ny == 2) {
							ndl = 0;
						}
					} else if(nx == 2) {
						if(ny == 0) {
							nur = 0;
						} else if(ny == 2) {
							ndr = 0;
						}
					}
					if(ok && isProperF(nul, nur, ndl, ndr)) {
						if(!visited[nd][nx][ny][nul][nur][ndl][ndr]) {
							visited[nd][nx][ny][nul][nur][ndl][ndr] = true;
							S.push(state(nd, nx, ny, nul, nur, ndl, ndr));
						}
					}
				}
			}
		}

		cout << (finished ? 1 : 0 ) << endl;
	}

	return 0;
}