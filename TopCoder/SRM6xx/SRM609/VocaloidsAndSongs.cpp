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
const double EPS = 1e-12;
const double PI = acos(-1.0);
const int INF = INT_MAX/10;

int dp[51][51][51][51];

class VocaloidsAndSongs {
public:
void init() {
	REP(a, 51) {
		REP(b, 51) {
			REP(c, 51) {
				REP(d, 51) {
					dp[a][b][c][d] = 0;
				}
			}
		}
	}
}

void update(int ng, int ni, int nm, int g, int i, int m, int S) {
	dp[S+1][ng][ni][nm] += dp[S][g][i][m];
	dp[S+1][ng][ni][nm] %= 1000000007;
}

int count( int S, int gumi, int ia, int mayu ) {
	init();
	dp[0][0][0][0] = 1;
	REP(s, S) {
		FOR(g, 0, gumi) {
			FOR(i, 0, ia) {
				FOR(m, 0, mayu) {
					if(g < gumi) update(g+1, i, m, g, i, m, s);
					if(i < ia)   update(g, i+1, m, g, i, m, s);
					if(m < mayu) update(g, i, m+1, g, i, m, s);
					if(g < gumi && i < ia)   update(g+1, i+1, m, g, i, m, s);
					if(i < ia && m < mayu)   update(g, i+1, m+1, g, i, m, s);
					if(m < mayu && g < gumi) update(g+1, i, m+1, g, i, m, s);
					if(g < gumi && i < ia && m < mayu) update(g+1, i+1, m+1, g, i, m, s);
				}
			}
		}
	}

	return dp[S][gumi][ia][mayu];
}
};