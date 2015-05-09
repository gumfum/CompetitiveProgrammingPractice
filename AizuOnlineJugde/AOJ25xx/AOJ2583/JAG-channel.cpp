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
		vs s(n);
		REP(i, n) {
			cin >> s[i];
		}

		vi depth(n);
		REP(i, n) {
			REP(j, s[i].size()) {
				if (s[i][j] == '.') {
					depth[i]++;
					s[i][j] = ' ';
				}
				else {
					break;
				}
			}
		}

		REP(i, n) {
			if (depth[i] != 0) {
				s[i][depth[i] - 1] = '+';
				FOR(j, i + 1, n - 1) {
					if (depth[i] > depth[j]) {
						break;
					}
					if (depth[i] == depth[j]) {
						FOR(k, i + 1, j - 1) {
							s[k][depth[i] - 1] = '|';
						}
					}
				}
			}
		}
		REP(i, n) {
			cout << s[i] << endl;
		}
	}
	return 0;
}