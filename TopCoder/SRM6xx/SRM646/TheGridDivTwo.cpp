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
typedef vector<int> vi;
typedef vector<vi>  vvi;
typedef pair<int, int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n) FOR(i,0,(n)-1)
const double EPS = 1e-12;
const double PI = acos(-1.0);
const int INF = INT_MAX / 10;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

class TheGridDivTwo {
public:
	int find(vector <int> x, vector <int> y, int k) {
		vvi field(2001, vi(2001));
		int size = x.size();
		REP(i, size) {
			field[x[i] + 1000][y[i] + 1000] = -1;
		}

		queue<pii> Q;
		Q.push(pii(1000, 1000));
		int ans = 0;
		while (!Q.empty()) {
			pii p = Q.front();
			Q.pop();

			int x = p.first, y = p.second, t = field[x][y];
			ans = max(ans, x - 1000);
			if (t == k) {
				continue;
			}

			REP(d, 4) {
				int nx = x + dx[d], ny = y + dy[d];
				if (field[nx][ny] == 0) {
					field[nx][ny] = t + 1;
					Q.push(pii(nx, ny));
				}
			}
		}

		return ans;
	}
};



// Powered by FileEdit
// Powered by moj 4.18 [modified TZTester]
// Powered by CodeProcessor
