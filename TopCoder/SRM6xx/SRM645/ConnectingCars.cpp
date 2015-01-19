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

typedef pair<ll, ll> pll;

class ConnectingCars {
public:
	long long minimizeCost(vector <int> positions, vector <int> lengths) {
		int size = positions.size();
		vector<pll> dist(size);
		REP(i, size) {
			dist[i].first = positions[i];
			dist[i].second = dist[i].first + lengths[i];
		}

		sort(ALL(dist));
		vector<ll> d(size - 1);
		REP(i, size - 1) {
			d[i] = dist[i + 1].first - dist[i].second;
		}

		ll ans = LONG_MAX;
		REP(i, size - 1) {
			ll sum = 0, tmp = 0;
			for (int j = i - 1; j >= 0; j--) {
				tmp += d[j];
				sum += tmp;
			}
			tmp = 0;
			FOR(j, i, size - 2) {
				tmp += d[j];
				sum += tmp;
			}
			ans = min(ans, sum);
		}

		return ans;
	}
};



// Powered by FileEdit
// Powered by moj 4.18 [modified TZTester]
// Powered by CodeProcessor
