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

int dx[] = {1, 0, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 0, -1, -1};

bool isProperXY(int x, int y, int N) {
	if(0 <= x && 0 <= y && x+y<N) {
		return true;
	} else {
		return false;
	}
}

int main() {
	int N, C;
	while(cin >> N >> C, N) {
		vvi board(N, vi(N));
		vector<pii> emptyPoint;
		REP(i, N) {
			REP(j, i+1) {
				cin >> board[i-j][j];
				if(board[i-j][j] == 0) {
					emptyPoint.push_back(pii(i-j, j));
				}
			}
		}

		int size = emptyPoint.size(), ans = -INF;
		REP(i, size) {
			vvi field = board;
			field[emptyPoint[i].first][emptyPoint[i].second] = C;
			vvi visited(N, vi(N));
			int pts = 0;
			REP(i, N) {
				REP(j, i+1) {
					if(!visited[i-j][j] && field[i-j][j] != 0) {
						int num = field[i-j][j], node = 0;
						bool live = false;
						queue<pii> Q;
						Q.push(pii(i-j, j));
						visited[i-j][j] = 1;
						while(!Q.empty()) {
							pii p = Q.front();
							Q.pop();
							node++;
							REP(d, 6) {
								int ny = p.first+dy[d], nx = p.second+dx[d];
								if(isProperXY(nx, ny, N) && !visited[ny][nx]) {
									if(field[ny][nx] == 0) {
										live = true;
									} else if(field[ny][nx] == num) {
										visited[ny][nx] = 1;
										Q.push(pii(ny, nx));
									}
								}
							}
						}
						if(!live) {
							if(num == C) {
								pts -= node;
							} else {
								pts += node;
							}
						}
					}
				}
			}
			ans = max(ans, pts);
		}
		cout << ans << endl;
	} 

	return 0;
}