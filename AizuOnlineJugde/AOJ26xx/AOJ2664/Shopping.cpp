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

struct UnionFind {
	vi data;
	UnionFind(int size) : data(size, -1) {}
	bool unite(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool find(int x, int y) {
		return root(x) == root(y);
	}
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	int size(int x) {
		return -data[root(x)];
	}
};

int main() {
	int N;
	cin >> N;
	vector<string> a(N);
	vi x(N);
	UnionFind uf(N);
	map<string, int> index;
	REP(i, N) {
		cin >> a[i] >> x[i];
		index[a[i]] = i;
	}

	int M;
	cin >> M;
	string s, t;
	REP(i, M) {
		cin >> s >> t;
		uf.unite(index[t], index[s]);
	}

	vi cost(N, INF), num(N, 0);
	REP(i, N) {
		int r = uf.root(i);
		cost[r] = min(cost[r], x[i]);
		num[r]++;
	}

	int ans = 0;
	REP(i, N) {
		if (cost[i] != INF) {
			ans += cost[i] * num[i];
		}
	}

	cout << ans << endl;
	return 0;
}