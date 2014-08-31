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

struct state {
	int c, p;
	string s;
	state(int c, int p, string s) : c(c), p(p), s(s) {};
};

int main() {
	int n;
	while (cin >> n, n) {
		string st, en;
		cin >> st >> en;

		stack<state> S;
		S.push(state(0, 0, st));
		int ans = INT_MAX;
		while (!S.empty()) {
			state st = S.top();
			S.pop();
			if (st.p == n) {
				ans = min(ans, st.c);
				continue;
			}

			if (st.s[st.p] == en[st.p]) {
				S.push(state(st.c, st.p + 1, st.s));
				continue;
			}

			REP(i, n - st.p) {
				string ns = st.s;
				int diff = en[st.p] - st.s[st.p] + 10;
				REP(j, i + 1) {
					ns[st.p + j] = (ns[st.p + j] - '0' + diff) % 10 + '0';
				}
				S.push(state(st.c + 1, st.p + 1, ns));
			}
		}
		cout << ans << endl;
	}
}