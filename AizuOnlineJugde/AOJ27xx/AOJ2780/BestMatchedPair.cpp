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

int main() {
	int N;
	cin >> N;
	vi a(N);
	REP(i, N) {
		cin >> a[i];
	}

	int ans = -1;
	string cond = "123456789";
	REP(i, N - 1) {
		FOR(j, i + 1, N - 1) {
			int p = a[i] * a[j];
			if (cond.find(toStr(p)) != string::npos) {
				ans = max(ans, p);
			}
		}
	}

	cout << ans << endl;
	return 0;
}