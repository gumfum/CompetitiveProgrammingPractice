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
	int N, M;
	while (cin >> N >> M, N) {
		vi field(N);
		REP(i, N) {
			cin >> field[i];
		}
		vi dice(M);
		REP(i, M) {
			cin >> dice[i];
		}

		int pos = 0;
		REP(i, M) {
			pos += dice[i];
			if (pos >= N - 1) {
				cout << i + 1 << endl;
				break;
			}

			pos += field[pos];
			if (pos >= N - 1) {
				cout << i + 1 << endl;
				break;
			}
			if (pos < 0) {
				pos = 0;
			}
		}
	}

	return 0;
}