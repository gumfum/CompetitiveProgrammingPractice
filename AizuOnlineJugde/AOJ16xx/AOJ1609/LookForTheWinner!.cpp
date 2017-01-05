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
	while (cin >> n, n) {
		vector<char> c(n + 1);
		FOR(i, 1, n) {
			cin >> c[i];
		}

		vi p(26 + 'A');
		int f = 0, s = 0;
		bool finish = false;
		FOR(i, 1, n) {
			p[c[i]]++;
			if (f < p[c[i]]) {
				f = p[c[i]];
				FOR(j, 'A', 'Z') {
					if (c[i] != j) {
						s = max(s, p[j]);
					}
				}
			}
			else if (f == p[c[i]] || s < p[c[i]]) {
				s = p[c[i]];
			}

			if (n - i + s < f) {
				char w;
				FOR(j, 'A', 'Z') {
					if (p[j] == f) {
						w = j;
					}
				}
				cout << w << " " << i << endl;
				finish = true;
				break;
			}
		}

		if (!finish) {
			cout << "TIE" << endl;
		}
	}
}