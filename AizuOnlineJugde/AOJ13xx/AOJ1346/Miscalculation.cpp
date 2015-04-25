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

string s;
int p;

int term();
int num();

int expression() {
	int ret = term();
	while (s[p] == '+') {
		p++;
		ret += term();
	}
	return ret;
}

int term() {
	int ret = num();
	while (s[p] == '*') {
		p++;
		ret *= num();
	}
	return ret;
}

int num() {
	int ret = 0;
	while (isdigit(s[p])) {
		ret *= 10;
		ret += (s[p] - '0');
		p++;
	}
	return ret;
}

int expression2() {
	int ret = num();
	while (true) {
		if (s[p] == '+') {
			p++;
			ret += num();
		}
		else if (s[p] == '*') {
			p++;
			ret *= num();
		}
		else {
			break;
		}
	}
	return ret;
}

int main() {
	int n;
	cin >> s >> n;
	p = 0;
	int ans1 = expression();
	p = 0;
	int ans2 = expression2();

	if (n == ans1) {
		if (n == ans2) {
			cout << 'U' << endl;
		}
		else {
			cout << 'M' << endl;
		}
	}
	else if (n == ans2) {
		cout << 'L' << endl;
	}
	else {
		cout << 'I' << endl;
	}
	
	return 0;
}