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
	while (cin >> n, n) {
		int a, b;
		char c;
		vi d(n), t(n), p(n);
		vector<char> e(n);
		int maxp = -1;
		REP(i, n) {
			cin >> a >> c >> b;
			d[i] = a * 100 + b;
			cin >> a >> c >> b;
			t[i] = a * 60 + b;
			cin >> e[i] >> p[i];
			maxp = max(maxp, p[i]);
		}

		vi isIn(maxp + 1), inTime(maxp + 1), sum(maxp + 1);
		REP(i, n) {
			if (e[i] == 'I') {
				isIn[p[i]] = 1;
				inTime[p[i]] = t[i];
				if (p[i] == 0) {
					FOR(j, 1, maxp) {
						inTime[j] = t[i];
					}
				}
			}
			else {
				isIn[p[i]] = 0;
				if (p[i] == 0) {
					FOR(j, 1, maxp) {
						if (isIn[j]) {
							sum[j] += t[i] - inTime[j];
						}
					}
				}
				if (isIn[0]) {
					sum[p[i]] += t[i] - inTime[p[i]];
				}
			}
		}

		int ans = 0;
		FOR(i, 1, maxp) {
			ans = max(ans, sum[i]);
		}

		cout << ans << endl;
	}

	return 0;
}