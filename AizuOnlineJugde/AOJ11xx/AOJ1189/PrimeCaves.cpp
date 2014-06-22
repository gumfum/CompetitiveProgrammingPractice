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

const int MAX_N = 1000000;
const int MAX_F = 1000;
int num[1001][1001];
int dp[1001][1001], last[1001][1001];

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

bool isProperXY(int x, int y, int m) {
	return 0 <= x && x <= MAX_F && 0 <= y && y <= MAX_F && 0 < num[y][x] && num[y][x] <= m;
}

int main() {
	vi isPrime(MAX_N + 1, true);
	isPrime[0] = isPrime[1] = false;
	FOR(i, 2, 1000) {
		for (int j = i*i; j <= MAX_N; j += i) {
			isPrime[j] = false;
		}
	}

	memset(num, INF, sizeof(num));
	int x = 500, y = 500, cur = 1, step = 1;
	while (cur <= MAX_N) {
		REP(i, (step + 1) / 2) {
			num[y][x] = cur;
			cur++;
			x += dx[step % 4];
			y += dy[step % 4];
		}
		step++;
	}

	int m, n;
	while (cin >> m >> n, m) {
		int stx, sty;
		FOR(i, 0, MAX_F) {
			FOR(j, 0, MAX_F) {
				if (num[i][j] == n) {
					sty = i, stx = j;
				}
			}
		}
		//		cout << sty << " " << stx << endl;

		memset(dp, 0, sizeof(dp));
		memset(last, 0, sizeof(last));
		if (isPrime[num[sty][stx]]) {
			dp[sty][stx] = 1;
			last[sty][stx] = num[sty][stx];
		}
		int ans = dp[sty][stx], lastp = last[sty][stx], minx = stx, maxx = stx;
		bool cont = true;
		y = sty;
		while (cont) {
			cont = false;
			int nminx = INF, nmaxx = -INF;
			FOR(x, minx, maxx) {
				FOR(d, 1, 3) {
					int nx = x + dx[d], ny = y + 1;
					if (isProperXY(nx, ny, m)) {
						cont = true;
						nminx = min(nminx, nx);
						nmaxx = max(nmaxx, nx);
						if (isPrime[num[ny][nx]]) {
							last[ny][nx] = num[ny][nx];
						}
						else {
							last[ny][nx] = last[y][x];
						}
						int ndp = dp[y][x] + (isPrime[num[ny][nx]] ? 1 : 0);
						if (ans == ndp && lastp < last[ny][nx]) {
							lastp = last[ny][nx];
						}
						else if (ans < ndp) {
							ans = ndp;
							lastp = last[ny][nx];
						}
						dp[ny][nx] = max(dp[ny][nx], ndp);
						//						cout << num[y][x] << " " << num[ny][nx] << " " << dp[ny][nx] << endl;
					}
				}
			}
			minx = nminx, maxx = nmaxx;
			y++;
		}

		cout << ans << " " << lastp << endl;
	}

	return 0;
}