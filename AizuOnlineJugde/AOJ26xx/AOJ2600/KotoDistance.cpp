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
	int N, W, H;
	cin >> N >> W >> H;

	int x, y, w;
	vector<pii> xl, yl;
	REP(i, N) {
		cin >> x >> y >> w;
		xl.push_back(pii(x - w, x + w));
		yl.push_back(pii(y - w, y + w));
	}
	xl.push_back(pii(0, 0));
	xl.push_back(pii(W, W));
	yl.push_back(pii(0, 0));
	yl.push_back(pii(H, H));
	sort(ALL(xl));
	sort(ALL(yl));

	bool xok = true, yok = true;
	int xm = 0, ym = 0;
	REP(i, N + 2) {
		if (xm < xl[i].first) {
			xok = false;
		}
		else {
			xm = max(xm, xl[i].second);
		}
		if (ym < yl[i].first) {
			yok = false;
		}
		else {
			ym = max(ym, yl[i].second);
		}
	}

	cout << (xok | yok ? "Yes" : "No") << endl;
	return 0;
}