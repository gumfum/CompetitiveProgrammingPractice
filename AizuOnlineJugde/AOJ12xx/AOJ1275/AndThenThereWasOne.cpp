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

ll josephus(ll n, ll k, ll s) {
	// n : number of people
	// k : number of skips
	// s : number of turn
	ll ret = k * s;
	while(ret > n) {
		ret = ((ret - n) * k - 1) / (k - 1);
	}
	return ret;
}

int main() {
	int n, k, m;
	while(cin >> n >> k >> m, n) {
		int o = k % n;
		int diff = m - o;
		int ans = (josephus(n, k, n) + diff + n) % n;
		cout << (ans != 0 ? ans : n) << endl;
	}

	return 0;
}