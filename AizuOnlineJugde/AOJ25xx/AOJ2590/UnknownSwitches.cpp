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

char conv(int n) {
	if (n < 0) {
		return '?';
	}
	else if (n < 10) {
		return '0' + n;
	}
	else {
		return 'A' + n - 10;
	}
}

int main() {
	int N, M, Q;
	while (cin >> N >> M >> Q, N) {
		vvi table(N, vi(M, 1));

		string S, B;
		vector<bool> isOn(N, false);
		REP(i, Q) {
			cin >> S >> B;
			REP(j, N) {
				if (S[j] == '1') {
					isOn[j] = !isOn[j];
				}
				REP(k, M) {
					if (isOn[j] && (B[k] == '0')) {
						table[j][k] = 0;
					}
					else if (!isOn[j] && (B[k] == '1')) {
						table[j][k] = 0;
					}
				}
			}
		}

		vi ans(M);
		REP(i, M) {
			int num = -1;
			REP(j, N) {
				if (table[j][i] == 1) {
					if (num == -1) {
						num = j;
					}
					else {
						num = -1;
						break;
					}
				}
			}
			ans[i] = num;
		}

		REP(i, M) {
			cout << conv(ans[i]);
		}
		cout << endl;
	}

	return 0;
}