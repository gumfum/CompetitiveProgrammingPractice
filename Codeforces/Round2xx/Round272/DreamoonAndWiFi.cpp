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

int kaijo(int n) {
	int res = 1;
	if (n == 0) {
		return 1;
	}
	FOR(i, 1, n) {
		res *= i;
	}
	return res;
}

int nCr(int n, int r) {
	return kaijo(n) / (kaijo(r) * kaijo(n - r));
}

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	int size = s1.size();

	int p1 = 0;
	REP(i, size) {
		if (s1[i] == '+') {
			p1++;
		}
		else if (s1[i] == '-') {
			p1--;
		}
	}

	int p2 = 0, ph2 = 0;
	REP(i, size) {
		if (s2[i] == '+') {
			p2++;
		}
		else if (s2[i] == '-') {
			p2--;
		}
		else {
			ph2++;
		}
	}

	//cout << p1 << endl;
	//cout << p2 << endl;
	//cout << ph2 << endl;

	bool ok = false;
	double ans = 0;
	if (p1 == p2 && ph2 == 0) {
		ans = 1;
		goto show;
	}
	int plus;
	FOR(i, 0, ph2) {
		if ((2 * i - ph2 + p2) == p1) {
			ok = true;
			plus = i;
			break;
		}
	}
	if (ok) {
		//cout << ph2 << endl;
		//cout << plus << endl;
		//cout << nCr(ph2, plus) << endl;
		//cout << (1 << ph2) << endl;
		ans = 1.0 * nCr(ph2, plus) / (1 << ph2);
	}
show:
	printf("%1.12f\n", ans);
}