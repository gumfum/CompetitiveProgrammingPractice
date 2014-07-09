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
const double EPS = 1e-12;
const double PI = acos(-1.0);
const int INF = INT_MAX / 10;

typedef vector<double> vd;

vi subset_combination(int n, int k) {
	vi res;
	int S = (1 << k) - 1;
	int E = ~((1 << n) - 1);
	while (!(S&E)) {
		res.push_back(S);
		int smallest = S & -S;
		int ripple = S + smallest;
		int nsmallest = ripple & -ripple;
		S = ripple | (((nsmallest / smallest) >> 1) - 1);
	}
	return res;
}

double dist(vd a, vd b) {
	double res = 0;
	REP(i, a.size()) {
		res += pow(a[i] - b[i], 2);
	}
	return res;
}

int main() {
	int N, M;
	cin >> N >> M;
	vector<vd> data(N, vd(3));
	REP(i, N) {
		REP(j, 3) {
			cin >> data[i][j];
		}
	}

	double ans = 0;
	if (N == 0 || M == 0) {

	}
	else {
		vi comb = subset_combination(N, M);
		int size = comb.size();
		REP(i, size) {
			double tmp = 0;
			REP(j, N) {
				REP(k, N) {
					if (j != k && comb[i] & (1 << j) && comb[i] & (1 << k)) {
						tmp += dist(data[j], data[k]);
					}
				}
			}
			ans = max(ans, tmp);
		}
		ans /= 2;
	}

	printf("%.6f\n", ans);
	return 0;
}