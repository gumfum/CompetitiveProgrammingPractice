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

int main() {
	int n, m;
	cin >> n >> m;
	int x, y;
	vvi react(n, vi(n));
	REP(i, m) {
		cin >> x >> y;
		x--;
		y--;
		react[x][y] = react[y][x] = 1;
	}

	ll ans = 1;
	int count = 1;
	vi used(n);
	used[0] = 1;
	while (count < n) {
		int mini = INF;
		REP(i, n) {
			if (!used[i]) {
				REP(j, n) {
					if (used[j]) {
						if (react[i][j]) {
							used[i] = 1;
							ans *= (ll)2;
							goto next;
						}
						else {
							mini = min(mini, i);
						}
					}
				}
			}
		}
		used[mini] = 1;
	next:
		count++;
	}
	cout << ans << endl;
	return 0;
}