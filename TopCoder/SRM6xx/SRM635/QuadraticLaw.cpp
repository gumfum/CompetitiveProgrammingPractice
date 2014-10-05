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
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n) FOR(i,0,(n)-1)

class QuadraticLaw {
public:
	ll diff(ll d, ll t) {
		return d = d - (t*t + t);
	}

	long long getTime(long long d) {
		ll mint = 0, maxt = 10000000000;

		while (mint != maxt) {
			ll mid = (mint + maxt) / 2;
			ll middiff = diff(d, mid);
			if (middiff < 0) {
				maxt = mid;
				continue;
			}
			if (maxt - mint == 1) {
				if (!(diff(d, maxt) < 0)) {
					return maxt;
				}
				else {
					return mint;
				}
			}
			else {
				mint = mid;
			}
		}

		return mint;
	}
};



// Powered by FileEdit
// Powered by moj 4.18 [modified TZTester]
// Powered by CodeProcessor
