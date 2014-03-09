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

#define EQ(x,y) (abs((x)-(y))<EPS)
#define EQV(a,b) (EQ((a).real(),(b).real())&&EQ((a).imag(),(b).imag()))

namespace std {
	bool operator<(const P &a, const P &b) {
		return a.real()!=b.real() ? a.real()<b.real() : a.imag()<b.imag();
	}
}

double cross(P a, P b) {
	return a.real()*b.imag()-a.imag()*b.real();
}

int is_point_on_ls(P a, P b, P c) {
	return (abs(a-c)+abs(c-b)<abs(a-b)+EPS);
}

int is_intersection_ls(P a1, P a2, P b1, P b2) {
	if((cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1) < -EPS) &&
		(cross(b2-b1, a1-b1) * cross(b2-b1, a2-b1) < -EPS))
		return true;
	return is_point_on_ls(a1, a2, b1) || is_point_on_ls(a1, a2, b2) ||
		is_point_on_ls(b1, b2, a1) || is_point_on_ls(b1, b2, a2);
}

P intersection_ls(P a1, P a2, P b1, P b2) {
	P b = b2-b1;
	double d1 = abs(cross(b, a1-b1));
	double d2 = abs(cross(b, a2-b1));
	double t = d1/(d1+d2);

	return a1+(a2-a1)*t;
}

typedef vector<P> vp;

struct crossPoint {
	P p;
	pii info;
	crossPoint(P p, pii info) : p(p), info(info) {};
};

namespace std {
	bool operator<(const crossPoint &a, const crossPoint &b) {
		return a.p.real()!=b.p.real() ? a.p.real()<b.p.real() : a.p.imag()<b.p.imag();
	}
}

int getUpDown(int f, vector<crossPoint> cp) {
	int res = 0;
	int size = cp.size();
	REP(i, size) {
		if(cp[i].info.first == 0) {
			if(f != cp[i].info.second) {
				f = 1-f;
				res++;
			}
		} else {
			if(f == cp[i].info.second) {
				f = 1-f;
				res++;
			}
		}
	}

	return res;
}

int main() {
	int m;
	cin >> m;
	REP(szg, m) {
		double xa, ya, xb, yb;
		int n;
		cin >> xa >> ya >> xb >> yb >> n;
		P a = P(xa, ya), b = P(xb, yb); 
		
		double xs, ys, xt, yt;
		vi o(n), l(n);
		vector<vp> lines(n, vp(2));
		REP(i, n) {
			cin >> xs >> ys >> xt >> yt >> o[i] >> l[i];
			lines[i][0] = P(xs, ys);
			lines[i][1] = P(xt, yt);
		}

		vi isCross(n, 0);
		vector<crossPoint> cp;
		REP(i, n) {
			if(is_intersection_ls(a, b, lines[i][0], lines[i][1])) {
				P p = intersection_ls(a, b, lines[i][0], lines[i][1]);
				cp.push_back(crossPoint(p, pii(o[i], l[i])));
			}
		}

		sort(ALL(cp));
		int size = cp.size();
		int ans = min(size, min(getUpDown(0, cp), getUpDown(1, cp)));

		cout << ans << endl;
	}

	return 0;
}