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
	int n;
	int c[] = { 5, 7, 5, 7, 7 };
	while (cin >> n, n) {
		vs w(n);
		REP(i, n) {
			cin >> w[i];
		}
		int ans = -1;
		REP(i, n) {
			int p = 0, t = 0;
			FOR(j, i, n - 1) {
				t += w[j].size();
				if (t == c[p]) {
					if (p == 4) {
						ans = i + 1;
						break;
					}
					else {
						p++;
						t = 0;
					}
				}
				else if (t > c[p]) {
					break;
				}
			}
			if (ans != -1) {
				break;
			}
		}
		cout << ans << endl;
	}
}