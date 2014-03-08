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
	else 
		return false;
}

P intersection_ls(P a1, P a2, P b1, P b2) {
	P b = b2-b1;
	double d1 = abs(cross(b, a1-b1));
	double d2 = abs(cross(b, a2-b1));
	double t = d1/(d1+d2);

	return a1+(a2-a1)*t;
}

typedef vector<P> vp;

int main() {
	int n;
	while(cin >> n, n) {
		vector<vp> ps(n, vp(2));
		double x, y;
		REP(i, n) {
			REP(j, 2) {
				cin >> x >> y;
				ps[i][j] = P(x, y);
			}
		}

		int ans = 1;
		REP(i, n) {
			ans++;
			vp cp;
			REP(j, i) {
				if(is_intersection_ls(ps[i][0], ps[i][1], ps[j][0], ps[j][1])) {
					P p = intersection_ls(ps[i][0], ps[i][1], ps[j][0], ps[j][1]);
					int size = cp.size();
					bool exist = false;
					REP(k, size) {
						if(EQV(p, cp[k])) {
							exist = true;
							break;
						}
					}
					if(!exist) {
						cp.push_back(p);
						ans++;
					}
				}
			}
		}

		cout << ans << endl;
	}
	return 0;
}