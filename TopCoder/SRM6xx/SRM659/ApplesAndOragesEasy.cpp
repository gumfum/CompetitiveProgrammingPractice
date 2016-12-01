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

class ApplesAndOrangesEasy {
public:
	int maximumApples(int N, int K, vector <int> info) {
		vi pos(N), app(N, 1);
		int size = info.size();
		REP(i, size) {
			pos[info[i] - 1] = 1;
		}

		int p = 0, sum = 0;
		REP(i, N) {
			sum += app[i];
			if (sum > K / 2) {
				int t = i;
				while (!(pos[t] == 0 && app[t] == 1)) {
					t--;
				}
				app[t] = 0;
				sum--;
			}

			if (i - p == K - 1) {
				sum -= app[p];
				p++;
			}
		}

		int ans = 0;
		REP(i, N) {
			ans += app[i];
		}

		return ans;
	}
};



// Powered by FileEdit
// Powered by moj 4.18 [modified TZTester]
// Powered by CodeProcessor
