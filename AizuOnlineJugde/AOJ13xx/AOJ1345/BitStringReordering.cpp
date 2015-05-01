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

void show(vi b) {
	REP(i, b.size()) {
		cout << b[i] << " ";
	}
	cout << endl;
}

int main() {
	int N, M;
	cin >> N >> M;
	vi b(N), p(M);
	REP(i, N) {
		cin >> b[i];
	}
	REP(i, M) {
		cin >> p[i];
	}
	FOR(i, 1, M - 1) {
		p[i] += p[i - 1];
	}

	int ans = INF;
	REP(i, 2) {
		int pp = 0, st = i, step = 0;
		vi bb(b);
		REP(j, N) {
			if (j == p[pp]) {
				pp++;
				st = (st + 1) % 2;
			}
			if (bb[j] != st) {
				FOR(l, j, N) {
					if (l == N) {
						goto next;
					}
					if (bb[l] == st) {
						swap(bb[j], bb[l]);
						step += l - j;
						break;
					}
				}
			}
			//show(bb);
		}
		ans = min(ans, step);
	next:;
	}

	cout << ans << endl;
	return 0;
}