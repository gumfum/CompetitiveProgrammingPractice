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

		vs code(n);
		REP(i, n) {
			code[i].push_back(s[i][0]);
			int l = s[i].size();
			REP(j, l - 1) {
				char c = s[i][j];
				if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') {
					code[i].push_back(s[i][j + 1]);
				}
			}
		}

		int l = -1;
		REP(i, n) {
			l = max(l, (int)code[i].size());
		}

		int ans = -1;
		FOR(i, 1, l) {
			set<string> ss;
			REP(j, n) {
				ss.insert(code[j].substr(0, i));
			}
			if (ss.size() == n) {
				ans = i;
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
