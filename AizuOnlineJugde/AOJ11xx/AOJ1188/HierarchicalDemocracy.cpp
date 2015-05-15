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

int dfs() {
	vi votes;
	while (p < s.size()) {
		if (s[p] == '[') {
			p++;
			votes.push_back(dfs());
		}
		else if (isdigit(s[p])) {
			int num = 0;
			while (s[p] != ']') {
				num = 10 * num + (s[p] - '0');
				p++;
			}
			votes.push_back((num + 1) / 2);
		}
		else if (s[p] == ']') {
			p++;
			vi v = votes;
			sort(ALL(v));
			int res = 0;
			FOR(i, 0, v.size() / 2) {
				res += v[i];
			}
			return res;
		}
	}
}

int main() {
	int N;
	cin >> N;
	REP(i, N) {
		cin >> s;
		p = 1;
		cout << dfs() << endl;
	}
	return 0;
}