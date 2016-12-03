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
typedef long long ll;
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n) FOR(i,0,(n)-1)
const double EPS = 1e-12;
const double PI = acos(-1.0);
const int INF = INT_MAX / 10;

class ProblemSets {
public:
	bool ok(ll E, ll EM, ll M, ll MH, ll H, ll N) {
		if (E < N) {
			EM -= (N - E);
			if (EM < 0) {
				return false;
			}
		}
		if (H < N) {
			MH -= (N - H);
			if (MH < 0) {
				return false;
			}
		}

		return M + EM + MH >= N;
	}

	long long maxSets(long long E, long long EM, long long M, long long MH, long long H) {
		ll minS = 0, maxS = (E + EM + M + MH + H);

		while (maxS - minS > 1) {
			ll mid = (maxS + minS) / 2;
			if (ok(E, EM, M, MH, H, mid)) {
				minS = mid;
			}
			else {
				maxS = mid;
			}
		}

		return minS;
	}
};



// Powered by FileEdit
// Powered by moj 4.18 [modified TZTester]
// Powered by CodeProcessor
