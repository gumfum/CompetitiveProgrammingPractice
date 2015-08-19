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

string format(int t) {
	string res = "";
	int h = t / 100, m = t % 100;
	res += toStr(h);
	res += ":";
	if (m < 10) {
		res += "0";
	}
	res += toStr(m);

	return res;
}

int main() {
	int N, h, m;
	cin >> N;
	set<int> data;
	REP(i, N) {
		cin >> h >> m;
		data.insert(100 * h + m);
	}
	cin >> N;
	REP(i, N) {
		cin >> h >> m;
		data.insert(100 * h + m);
	}

	vi times;
	for (set<int>::iterator it = data.begin(); it != data.end(); it++) {
		times.push_back(*it);
	}

	sort(ALL(times));
	REP(i, times.size()) {
		cout << format(times[i]);
		if (i != times.size() - 1) {
			cout << " ";
		}
	}
	cout << endl;
}