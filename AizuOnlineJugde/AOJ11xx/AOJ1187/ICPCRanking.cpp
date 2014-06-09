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
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v;}
template<class T> inline string toStr(T x) { ostringstream sout; sout << x; return sout.str();}
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
const int INF = INT_MAX/10;

typedef vector<vvi> vvvi;

struct team {
	int n, q, t;
	team() : q(0), t(0) {};
	bool operator<(const team &o)const {
		return q!=o.q ? q<o.q : (t!=o.t ? o.t<t : n<o.n);
	}
};

int main() {
	int M, T, P, R;
	while(cin >> M >> T >> P >> R, M) {
		vvvi data(T, vvi(2, vi(P, 0)));
		REP(i, R) {
			int m, t, p, j;
			cin >> m >> t >> p >> j;
			if(j == 0) {
				data[t-1][0][p-1] = 1;
				data[t-1][1][p-1] += m;
			} else {
				data[t-1][1][p-1] += 20;
			}
		}
		vector<team> teams(T);
		REP(i, T) {
			teams[i].n = i+1;
			teams[i].q = teams[i].t = 0;
		}
		REP(i, T) {
			REP(j, P) {
				if(data[i][0][j]) {
					teams[i].q++;
					teams[i].t += data[i][1][j];
				}
			}
		}
		sort(RALL(teams));
		int curq = teams[0].q, curt = teams[0].t;
		cout << teams[0].n;
		FOR(i, 1, T-1) {
			if(curq == teams[i].q && curt == teams[i].t) {
				cout << "=";
			} else {
				cout << ",";
			}
			cout << teams[i].n;
			curq = teams[i].q;
			curt = teams[i].t;
		}
		cout << endl;
	}

	return 0;
}