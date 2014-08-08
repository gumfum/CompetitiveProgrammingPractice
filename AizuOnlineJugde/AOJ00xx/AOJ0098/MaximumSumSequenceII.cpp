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
	int n;
	cin >> n;
	vvi matrix(n + 1, vi(n + 1, 0));
	FOR(i, 1, n) {
		FOR(j, 1, n) {
			cin >> matrix[i][j];
		}
	}

	if (n == 1) {
		cout << matrix[1][1] << endl;
		return 0;
	}

	FOR(i, 1, n) {
		FOR(j, 2, n) {
			matrix[i][j] += matrix[i][j - 1];
		}
	}
	FOR(i, 2, n) {
		FOR(j, 1, n) {
			matrix[i][j] += matrix[i - 1][j];
		}
	}

	int ans = INT_MIN;
	FOR(ye, 1, n) {
		FOR(xe, 1, n) {
			REP(ys, ye) {
				REP(xs, xe) {
					ans = max(ans, matrix[ye][xe] - matrix[ys][xe] - matrix[ye][xs] + matrix[ys][xs]);
				}
			}
		}
	}

	cout << ans << endl;
	return 0;
}