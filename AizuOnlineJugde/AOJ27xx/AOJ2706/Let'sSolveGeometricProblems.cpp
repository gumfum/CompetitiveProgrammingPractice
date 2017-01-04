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
const double EPS = 1e-10;
const double PI = acos(-1.0);
const int INF = INT_MAX / 10;
const int MOD = 1000000007;

int gcd(int x, int y) {
	if (x < y) {
		swap(x, y);
	}
	if (y == 0) {
		return x;
	}
	return gcd(y, x%y);
}

int main() {
	int p, q;
	cin >> p >> q;
	int m = sqrt(q) + 1;
	vi prime(m + 1, 1);
	prime[0] = prime[1] = 0;
	FOR(i, 2, m) {
		if (prime[i]) {
			for (int j = i*i; j <= m; j += i) {
				prime[j] = 0;
			}
		}
	}

	int ans = 1;
	q /= gcd(p, q);
	FOR(i, 2, m) {
		if ((prime[i] == 1) && (q%i == 0)) {
			ans *= i;
			while (q%i == 0) {
				q /= i;
			}
		}
	}

	if (q > 1) {
		ans *= q;
	}
	cout << ans << endl;
	return 0;
}