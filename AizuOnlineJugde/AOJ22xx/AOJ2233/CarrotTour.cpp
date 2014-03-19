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

#include <complex>
typedef complex<double> P;
typedef vector<double> vd;
typedef vector<vd> vvd;

#define EQ(x,y) (abs((x)-(y))<EPS)
#define LT(x,y) ((x)-(y)<=-EPS)

double dot(P a, P b) {
	return a.real()*b.real()+a.imag()*b.imag();
}

double angle_ls(P a, P b, P c) {
	P v1 = b-a, v2 = c-b;
	return acos(dot(v1, v2)/(abs(v1)*abs(v2)));
}

double to_radian(double degree) {
	return degree*PI/180;
}

double to_degree(double radian) {
	return radian*180/PI;
}

int main() {
	int n;
	double r, t;
	cin >> n >> r >> t;

	vector<P> pts(n);
	REP(i, n) {
		double x, y;
		cin >> x >> y;
		pts[i] = P(x, y);
	}

	vector<vvd> dist(n, vvd(n, vd(n, INF)));
	REP(i, n) {
		REP(j, n) {
			if(i == j) {
				continue;
			}
			REP(k, n) {
				if(i == k || j == k) {
					continue;
				}
				double angle = to_degree(angle_ls(pts[i], pts[j], pts[k]));
				if(LT(angle, t)) {
					dist[i][j][k] = abs(pts[k]-pts[j]);
				}
			}
		}
	}

	vector<vvd> dp(10000+1, vvd(n, vd(n, INF)));
	int ans = 0;
	FOR(i, 1, n-1) {
		double d = abs(pts[i]-pts[0]);
		if(LT(d, r)) {
			dp[1][0][i] = d;
			ans = 1;
		}
	}

	FOR(c, 2, 10000) {
		bool updated = false;
		REP(i, n) {
			REP(j, n) {
				double d = dp[c-1][i][j];
				if(EQ(d, INF)) {
					continue;
				}

				REP(k, n) {
					double nd = d + dist[i][j][k];
					if(LT(nd, r) && LT(nd, dp[c][j][k])) {
						ans = c;
						dp[c][j][k] = nd;
						updated = true;
					}
				}
			}
		}

		if(!updated) {
			break;
		}
	}
	
	cout << ans << endl;
	return 0;
}