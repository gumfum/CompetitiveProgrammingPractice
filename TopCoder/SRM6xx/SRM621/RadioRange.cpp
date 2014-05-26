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
#include <cmath>
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

#define isnan(x) _isnan(x)
#define isinf(x) (!_finite(x))

typedef vector<double> vd;
#define EQ(x,y) (abs((x)-(y))<EPS)
#define LE(x,y) ((x)-(y)<+EPS)

class RadioRange {
public:
double RadiusProbability( vector <int> X, vector <int> Y, vector <int> R, int Z ) {
	int size = X.size();
	vector<vd> dists(2*size, vd(2));
	REP(i, size) {
		double dist = sqrt((double)X[i]*X[i]+(double)Y[i]*Y[i]);
		dists[2*i][0] = max(0.0, dist-R[i]);
		dists[2*i][1] = +1;
		dists[2*i+1][0] = dist+R[i];
		dists[2*i+1][1] = -1;
	}

	sort(ALL(dists));
	int pos = 1, count = 0;
	double ans = 0.0;
	if(LE(dists[0][0], Z)) {
		ans += dists[0][0];
		count++;
	} else {
		pos = 2*size;
	}

	while(pos < 2*size) {
		if(count == 0) {
			ans += min((double)Z, dists[pos][0])-dists[pos-1][0];
		}
		if(LE(Z, dists[pos][0])) {
			break;
		}
		count += (int)dists[pos++][1];
	}
	if(pos == 2*size && count == 0) {
		if(LE(dists[pos-1][0], (double)Z)) {
			ans += Z-dists[pos-1][0];
		} else {
			ans += Z;
		}
	}

	return ans/Z;
}
};

// Powered by FileEdit
// Powered by moj 4.18 [modified TZTester]
// Powered by CodeProcessor
