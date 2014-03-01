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

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
	int n;
	cin >> n;
	vs field(n);
	REP(i, n) {
		cin >> field[i];
	}

	FOR(i, 1, n-2) {
		FOR(j, 1, n-2) {
			bool ok = false;
			if(field[i][j] == '#') {
				ok = true;
				REP(d, 4) {
					if(field[i+dy[d]][j+dx[d]] != '#') {
						ok = false;
					}
				}
			}
			if(ok) {
				field[i][j] = '.';
				REP(d, 4) {
					field[i+dy[d]][j+dx[d]] = '.';
				}
			}
		}
	}

	bool ok = true;
	REP(i, n) {
		REP(j, n) {
			if(field[i][j] == '#') {
				ok = false;
			}
		}
	}
	
	cout << (ok ? "YES" : "NO") << endl;
	return 0;
}