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
const double EPS = 1e-10;
const double PI = acos(-1.0);
const int INF = INT_MAX/10;

#define LE(x,y) ((x)-(y)<EPS)
typedef vector<double> vd;

vs split(string str, string delim) {
	vs result;
	int pos;

	while((pos = str.find_first_of(delim)) != str.npos) {
		if(pos > 0) {
			result.push_back(str.substr(0, pos));
		}
		str = str.substr(pos+1);
	}
	if(str.length() > 0) {
		result.push_back(str);
	}

	return result;
}

double diff(int r1, int r2) {
	return 2*sqrt(r1*r2)-r1+r2;
}

int main() {
	string line;
	while(getline(cin, line)) {
		vs data = split(line, " ");
		double size = toInt(data[0]);
		int n = data.size()-1;
		vi r(n);
		REP(i, n) {
			r[i] = toInt(data[i+1]);
		}

		vector<vd> dp(1<<n, vd(n, INF));
		REP(i, n) {
			dp[1<<i][i] = 2*r[i];
		}
		REP(i, 1<<n) {
			REP(j, n) {
				if(i&(1<<j)) {
					REP(k, n) {
						int ni = i|(1<<k);
						if(i != ni) {
							dp[ni][k] = min(dp[ni][k], dp[i][j]+diff(r[j], r[k]));
						}
					}
				}
			}
		}

		bool ok = false;
		REP(i, n) {
			if(LE(dp[(1<<n)-1][i], size)) {
				ok = true;
			}
		}

		cout << (ok ? "OK" : "NA") << endl;
	}

	return 0;
}