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

void show(vi p) {
	cout << " " << p[20] << p[19] << p[18] << endl;
	cout << p[15] << p[0] << p[1] << p[2] << p[14] << p[27] << p[28] << p[29] << endl;
	cout << p[16] << p[3] << p[4] << p[5] << p[13] << p[24] << p[25] << p[26] << endl;
	cout << p[17] << p[6] << p[7] << p[8] << p[12] << p[21] << p[22] << p[23] << endl;
	cout << " " << p[9] << p[10] << p[11] << endl;
}

vi rotate(vi p, int d) {
	vi np(31);
	REP(i, 31) {
		np[i] = p[i];
	}
	switch (d) {
	case 0:
		swap(np[0], np[23]);
		swap(np[3], np[26]);
		swap(np[6], np[29]);
		swap(np[9], np[20]);
		swap(np[15], np[17]);
		break;
	case 1:
		swap(np[6], np[21]);
		swap(np[7], np[22]);
		swap(np[8], np[23]);
		swap(np[12], np[17]);
		swap(np[9], np[11]);
		break;
	case 2:
		swap(np[2], np[21]);
		swap(np[5], np[24]);
		swap(np[8], np[27]);
		swap(np[11], np[18]);
		swap(np[12], np[14]);
		break;
	case 3:
		swap(np[0], np[27]);
		swap(np[1], np[28]);
		swap(np[2], np[29]);
		swap(np[14], np[15]);
		swap(np[18], np[20]);
		break;
	}
	np[30]++;
	return np;
}

bool finish(vi p) {
	FOR(i, 1, 8) {
		if (p[0] != p[i]) {
			return false;
		}
	}
	FOR(i, 10, 11) {
		if (p[9] != p[i]) {
			return false;
		}
	}
	FOR(i, 13, 14) {
		if (p[12] != p[i]) {
			return false;
		}
	}
	FOR(i, 16, 17) {
		if (p[15] != p[i]) {
			return false;
		}
	}
	FOR(i, 19, 20) {
		if (p[18] != p[i]) {
			return false;
		}
	}
	FOR(i, 22, 29) {
		if (p[21] != p[i]) {
			return false;
		}
	}
	return true;
}

int main() {
	int N;
	cin >> N;
	REP(i, N) {
		vi puzzle(31);
		REP(j, 30) {
			cin >> puzzle[j];
		}

		queue<vi> Q;
		Q.push(puzzle);
		while (!Q.empty()) {
			vi p = Q.front();
			Q.pop();

			//			show(p);
			if (finish(p)) {
				cout << p[30] << endl;
				break;
			}

			REP(d, 4) {
				vi np = rotate(p, d);
				Q.push(np);
			}
		}
	}
}