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

struct state {
	int p, c, r;
	state(int p, int c, int r) : p(p), c(c), r(r) {};
	bool operator<(const state &o)const {
		return o.c<c;
	}
};

int main() {
	int N;
	while (cin >> N, N) {
		int S, T, M, A, B;
		vvi dist(N + 1, vi(N + 1, INF));
		cin >> S >> T >> M;
		int num = 1;
		REP(i, M) {
			cin >> A >> B;
			dist[A][B] = min(dist[A][B], num);
			num++;
		}

		priority_queue<state> Q;
		Q.push(state(S, 0, 0));
		vi ncost(N + 1, INF), rcost(N + 1, INF), road(N + 1, INF);
		int ans = INF, ansr = INF;
		while (!Q.empty()) {
			state st = Q.top();
			Q.pop();

			if (ans < st.c) {
				break;
			}

			if (st.p == T) {
				if (st.c < ans) {
					ans = st.c;
					ansr = st.r;
					continue;
				}
				else if (st.c == ans && st.r < ansr) {
					ansr = st.r;
					continue;
				}
			}

			FOR(i, 1, N) {
				if (dist[st.p][i] != INF) {
					if (st.r == 0) {
						if (st.c + 1 < ncost[i]) {
							ncost[i] = st.c + 1;
							Q.push(state(i, st.c + 1, 0));
						}
					}
					else  {
						if (st.c + 1 < rcost[i]) {
							rcost[i] = st.c + 1;
							road[i] = st.r;
							Q.push(state(i, st.c + 1, st.r));
						}
						else if (st.c + 1 == rcost[i] && st.r < road[i]) {
							road[i] = st.r;
							Q.push(state(i, st.c + 1, st.r));
						}
					}
				}
				if (dist[i][st.p] != INF && st.r == 0) {
					if (st.c + 1 < rcost[i]) {
						rcost[i] = st.c + 1;
						road[i] = dist[i][st.p];
						Q.push(state(i, st.c + 1, dist[i][st.p]));
					}
					else if (st.c + 1 == rcost[i] && st.r < road[i]) {
						road[i] = dist[i][st.p];
						Q.push(state(i, st.c + 1, dist[i][st.p]));
					}
				}
			}
		}

		cout << ans << " " << ansr << endl;
	}

	return 0;
}