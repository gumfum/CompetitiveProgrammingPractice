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

typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<vd> vvd;

class FixedDiceGameDiv1 {
public:
	double getExpectation(int a, int b, int c, int d) {
		vvd sumAlice(a + 1, vd(a*b + 51)), sumBob(c + 1, vd(c*d + 51));
		sumAlice[0][0] = 1;
		FOR(i, 1, a) {
			FOR(j, 0, (i - 1)*b) {
				FOR(k, 1, b) {
					sumAlice[i][j + k] += sumAlice[i - 1][j] / b;
				}
			}
		}

		sumBob[0][0] = 1;
		FOR(i, 1, c) {
			FOR(j, 0, (i - 1)*d) {
				FOR(k, 1, d) {
					sumBob[i][j + k] += sumBob[i - 1][j] / d;
				}
			}
		}

		int minAlice = a, minBob = c;
		int maxAlice = a*b, maxBob = c*d;
		double sum = 0, comb = 0;
		FOR(i, minAlice, maxAlice) {
			FOR(j, minBob, maxBob) {
				if (j < i) {
					sum += sumAlice[a][i] * sumBob[c][j] * i;
					comb += sumAlice[a][i] * sumBob[c][j];
				}
			}
		}

		if (sum == 0) {
			return -1;
		}
		else {
			return sum / comb;
		}
	}
};



// Powered by FileEdit
// Powered by moj 4.18 [modified TZTester]
// Powered by CodeProcessor
