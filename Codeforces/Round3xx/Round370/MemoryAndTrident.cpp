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

int main() {
	string s;
	cin >> s;

	int l = s.length();
	if (l % 2) {
		cout << -1 << endl;
		return 0;
	}

	int v = 0, h = 0;
	REP(i, l) {
		switch (s[i]) {
		case 'R':
			v++;
			break;
		case 'L':
			v--;
			break;
		case 'U':
			h++;
			break;
		case 'D':
			h--;
			break;
		default:
			break;
		}
	}

	cout << (abs(v) + abs(h)) / 2 << endl;

	return 0;
}
