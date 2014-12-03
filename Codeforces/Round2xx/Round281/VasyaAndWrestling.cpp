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

typedef vector<ll> vl;

int isLarge(vi a, vi b) {
	int al = a.size(), bl = b.size();
	int l = min(al, bl);
	REP(i, l) {
		if (a[i] > b[i]) {
			return 1;
		}
		else if (a[i] < b[i]) {
			return -1;
		}
	}

	if (al > bl) {
		return 1;
	}
	else if(al < bl) {
		return -1;
	}

	return 0;
}

int main() {
	int n;
	cin >> n;

	vl pts(2);
	vvi seq(2, vi());
	int last = 0;
	REP(i, n) {
		int p;
		cin >> p;
		if (p > 0) {
			pts[0] += p;
			seq[0].push_back(p);
			last = 1;
		}
		else {
			pts[1] += abs(p);
			seq[1].push_back(abs(p));
			last = -1;
		}
	}

	if (pts[0] > pts[1]) {
		cout << "first" << endl;
	}
	else if (pts[0] < pts[1]) {
		cout << "second" << endl;
	}
	else {
		int res = isLarge(seq[0], seq[1]);
		if (res == 1) {
			cout << "first" << endl;
		}
		else if(res == -1) {
			cout << "second" << endl;
		}
		else {
			if (last == 1) {
				cout << "first" << endl;
			}
			else {
				cout << "second" << endl;
			}
		}
	}

	return 0;
}