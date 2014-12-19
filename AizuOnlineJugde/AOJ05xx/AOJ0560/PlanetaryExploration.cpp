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
const double EPS = 1e-12;
const double PI = acos(-1.0);
const int INF = INT_MAX / 10;

int main() {
	int M, N, K;
	cin >> M >> N >> K;
	vs field(M);
	REP(i, M) {
		cin >> field[i];
	}

	vvi J(M + 1, vi(N + 1)), O(M + 1, vi(N + 1)), I(M + 1, vi(N + 1));
	REP(i, M) {
		REP(j, N) {
			if (field[i][j] == 'J') {
				J[i + 1][j + 1] = 1;
			}
			else if (field[i][j] == 'O') {
				O[i + 1][j + 1] = 1;
			}
			else if (field[i][j] == 'I') {
				I[i + 1][j + 1] = 1;
			}
		}
	}
	FOR(i, 1, M) {
		FOR(j, 2, N) {
			J[i][j] += J[i][j - 1];
			O[i][j] += O[i][j - 1];
			I[i][j] += I[i][j - 1];
		}
	}
	FOR(i, 2, M) {
		FOR(j, 1, N) {
			J[i][j] += J[i - 1][j];
			O[i][j] += O[i - 1][j];
			I[i][j] += I[i - 1][j];
		}
	}

	int a, b, c, d;
	REP(i, K) {
		cin >> a >> b >> c >> d;
		a--; b--;
		int ansj = J[c][d] - J[c][b] - J[a][d] + J[a][b];
		int anso = O[c][d] - O[c][b] - O[a][d] + O[a][b];
		int ansi = I[c][d] - I[c][b] - I[a][d] + I[a][b];
		cout << ansj << " " << anso << " " << ansi << endl;
	}

	return 0;
}
