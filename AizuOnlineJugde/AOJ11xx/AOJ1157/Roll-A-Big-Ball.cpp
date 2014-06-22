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

#include <complex>
typedef complex<double> P;
#define LE(x,y) ((x)-(y)<+EPS)

double dot(P a, P b) {
	return a.real()*b.real() + a.imag()*b.imag();
}

double cross(P a, P b) {
	return a.real()*b.imag() - a.imag()*b.real();
}

int is_point_on_ls(P a, P b, P c) {
	return (abs(a - c) + abs(c - b) < abs(a - b) + EPS);
}

double distance_ls_p(P a, P b, P c) {
	if (dot(b - a, c - a) < EPS) return abs(c - a);
	if (dot(a - b, c - b) < EPS) return abs(c - b);
	return abs(cross(b - a, c - a)) / abs(b - a);
}

int is_intersected_ls(P a1, P a2, P b1, P b2) {
	if ((cross(a2 - a1, b1 - a1) * cross(a2 - a1, b2 - a1) < -EPS) &&
		(cross(b2 - b1, a1 - b1) * cross(b2 - b1, a2 - b1) < -EPS)) {
		return true;
	}
	return is_point_on_ls(a1, a2, b1) || is_point_on_ls(a1, a2, b2)
		|| is_point_on_ls(b1, b2, a1) || is_point_on_ls(b1, b2, a2);
}

double distance_ls(P a1, P a2, P b1, P b2) {
	if (is_intersected_ls(a1, a2, b1, b2)) return 0.0;
	return min(min(distance_ls_p(a1, a2, b1), distance_ls_p(a1, a2, b2)),
		min(distance_ls_p(b1, b2, a1), distance_ls_p(b1, b2, a2)));
}

struct block {
	int h;
	P a, b, c, d;
	block(int minx, int miny, int maxx, int maxy, int h) :
		a(P(minx, miny)), b(P(maxx, miny)), c(P(maxx, maxy)), d(P(minx, maxy)), h(h) {};
};

double distance_ball_ls(P s, P e, P b1, P b2, int h) {
	double d = distance_ls(s, e, b1, b2), res = d;
	if (!LE(d, h)) {
		res = ((h*h + d*d) / (2 * h));
	}
	return res;
}

double distance_ball_block(P s, P e, block b) {
	return min(min(distance_ball_ls(s, e, b.a, b.b, b.h), distance_ball_ls(s, e, b.b, b.c, b.h)),
		min(distance_ball_ls(s, e, b.c, b.d, b.h), distance_ball_ls(s, e, b.d, b.a, b.h)));
}

bool is_point_in_block(int x, int y, int minx, int miny, int maxx, int maxy) {
	return minx < x && x < maxx && miny < y && y < maxy;
}

int main() {
	int N;
	while (cin >> N, N) {
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		P s(sx, sy), e(ex, ey);

		int minx, miny, maxx, maxy, h;
		double r = INF;
		REP(i, N) {
			cin >> minx >> miny >> maxx >> maxy >> h;
			if (is_point_in_block(sx, sy, minx, miny, maxx, maxy) || is_point_in_block(ex, ey, minx, miny, maxx, maxy)) {
				r = 0;
			}
			block b(minx, miny, maxx, maxy, h);
			r = min(r, distance_ball_block(s, e, b));
		}

		cout << r << endl;;
	}

	return 0;
}