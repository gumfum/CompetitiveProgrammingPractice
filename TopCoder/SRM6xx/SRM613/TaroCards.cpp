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

typedef vector<ll> vl;
typedef vector<vl> vvl;

int bitnum(int n) {
	int res = 0;
	REP(i, 10) {
		if(n&(1<<i)) {
			res++;
		}
	}
	return res;
}


class TaroCards {
public:
long long getNumber( vector <int> first, vector <int> second, int K ) {
	int n = first.size();
	vector<vvl> dp(n+1, vvl(1<<10, vl(n+1, 0)));
	dp[0][0][0] = 1;
	FOR(i, 1, n) {
		int mask = 1<<(second[i-1]-1), num = 0;
		if(first[i-1] <= 10) {
			mask |= 1<<(first[i-1]-1);
		} else {
			num++;
		}
		REP(j, 1<<10) {
			REP(k, n) {
				dp[i][j][k] += dp[i-1][j][k];
				dp[i][j|mask][k+num] += dp[i-1][j][k];
			}
		}
	}

	ll ans = 0;
	REP(i, 1<<10) {
		int bit = bitnum(i);
		REP(j, n) {
			if(bit+j > K) {
				break;
			}
			ans += dp[n][i][j];
		}
	}
	
	return ans;
}
};



// Powered by FileEdit
// Powered by moj 4.18 [modified TZTester]
// Powered by CodeProcessor
