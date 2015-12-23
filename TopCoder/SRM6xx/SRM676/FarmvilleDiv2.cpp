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
const double EPS = 1e-12;
const double PI = acos(-1.0);
const int INF = INT_MAX/10;

class FarmvilleDiv2 {
public:
int minTime( vector <int> time, vector <int> cost, int budget ) {
	int ans = 0, size = cost.size();
	vector<pii> p;
	REP(i, size) {
		p.push_back(pii(cost[i], time[i]));
		ans += time[i];
	}
	sort(ALL(p));

	REP(i, size) {
		while (p[i].second > 0) {
			if (budget - p[i].first >= 0) {
				budget -= p[i].first;
				p[i].second--;
				ans--;
			}
			else {
				goto show;
			}
		}
	}

show:
	return ans;
}
};



// Powered by FileEdit
// Powered by moj 4.18 [modified TZTester]
// Powered by CodeProcessor
