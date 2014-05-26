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

#include <complex>
typedef complex<double> P;
typedef vector<P> vp;
typedef vector<double> vd;

#define LT(x,y) ((x)-(y)<=-EPS)
#define LE(x,y) ((x)-(y)<+EPS)

double dot(P a, P b) {
	return a.real()*b.real()+a.imag()*b.imag();
}

double cross(P a, P b) {
	return a.real()*b.imag()-a.imag()*b.real();
}

double dist(P a, P b) {
	return abs(b-a);
}

double distance_ls_p(P a, P b, P c) {
	if(dot(b-a, c-a) < EPS) return abs(c-a);
	if(dot(a-b, c-b) < EPS) return abs(c-b);
	return abs(cross(b-a, c-a))/abs(b-a);
}

bool is_inner_circle_ls(P w, double r, P a, P b) {
	if(LT(dist(w, a), r) && LT(dist(w, b), r)) {
		return true;
	}
	return false;
}

bool is_cross_circle_ls(P w, double r, P a, P b) {
	if(is_inner_circle_ls(w, r, a, b)) {
		return false;
	} else {
		if(LE(distance_ls_p(a, b, w), r)) {
			return true;
		}
	}
	return false;
}

int main() {
	int n;
	while(cin >> n, n) {
		vp w(n);
		vd r(n);
		double x, y;
		REP(i, n) {
			cin >> x >> y >> r[i];
			w[i] = P(x, y);
		}

		int m;
		cin >> m;
		REP(i, m) {
			P t, s;
			cin >> x >> y;
			t = P(x, y);
			cin >> x >> y;
			s = P(x, y);

			bool safe = false;
			REP(i, n) {
				if(is_cross_circle_ls(w[i], r[i], t, s)) {
					safe = true;
					break;
				}
			}

			cout << (safe ? "Safe" : "Danger") << endl;
		}
	}

	return 0;
}