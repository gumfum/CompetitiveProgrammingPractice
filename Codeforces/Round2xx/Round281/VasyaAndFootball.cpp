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
	vs teams(2);
	cin >> teams[0] >> teams[1];

	int n;
	cin >> n;
	vvi num(2, vi(100));
	vvi getout(2, vi(100));

	REP(i, n) {
		int t, m;
		char tea, col;
		cin >> t >> tea >> m >> col;
		
		int tt;
		tt = tea == 'h' ? 0 : 1;

		if (getout[tt][m] == 1) {
			continue;
		}
		if (tea == 'h') {
			if (col == 'y') {
				num[0][m]++;
				if (num[0][m] > 1) {
					cout << teams[0] << " " << m << " " << t << endl;
					getout[tt][m] = 1;
				}
			}
			else {
				cout << teams[0] << " " << m << " " << t << endl;
				getout[tt][m] = 1;
			}
		}
		else {
			if (col == 'y') {
				num[1][m]++;
				if (num[1][m] > 1) {
					cout << teams[1] << " " << m << " " << t << endl;
					getout[tt][m] = 1;
				}
			}
			else {
				cout << teams[1] << " " << m << " " << t << endl;
				getout[tt][m] = 1;
			}
		}
	}

	return 0;
}