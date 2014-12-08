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
	int n, l;
	while (cin >> n >> l, n) {
		vector<pii> ants(n);
		REP(i, n) {
			char d;
			cin >> d >> ants[i].second;
			if (d == 'R') {
				ants[i].first = 1;
			}
			else {
				ants[i].first = -1;
			}
		}

		int left = n, sec = 0, ans = -1;
		while (true) {
			sec++;
			ans = -1;
			REP(i, n) {
				ants[i].second += ants[i].first;
			}

			REP(i, n) {
				if (ants[i].first != 0) {
					if (ants[i].second == 0) {
						ans = i + 1;
						ants[i].first = 0;
						left--;
					}
					else if (ants[i].second == l) {
						if (ans == -1) {
							ans = i + 1;
						}
						ants[i].first = 0;
						left--;
					}
				}
			}

			if (n != 1) {
				REP(i, n) {
					FOR(j, i, n - 1) {
						if (ants[i].second == ants[j].second && ants[i].first != 0) {
							ants[i].first *= -1;
							ants[j].first *= -1;
						}
					}
				}
			}

			if (left == 0) {
				cout << sec << " " << ans << endl;
				break;
			}
		}
	}

	return 0;
}