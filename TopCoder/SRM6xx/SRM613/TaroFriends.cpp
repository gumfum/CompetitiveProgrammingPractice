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

class TaroFriends {
public:
int getNumber( vector <int> coordinates, int X ) {
	int size = coordinates.size();
	sort(ALL(coordinates));
	ll ans = INT_MAX;
	FOR(i, 0, size) {
		ll minC = INT_MAX, maxC = -INT_MAX;
		REP(j, size) {
			ll pos;
			if(j < i) {
				pos = coordinates[j]+X;
			} else {
				pos = coordinates[j]-X;
			}
			minC = min(minC, pos);
			maxC = max(maxC, pos);
		}
		ans = min(ans, maxC-minC);
	}

	return ans;
}
};



// Powered by FileEdit
// Powered by moj 4.18 [modified TZTester]
// Powered by CodeProcessor
