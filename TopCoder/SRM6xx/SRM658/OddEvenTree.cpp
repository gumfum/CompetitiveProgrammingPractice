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

class OddEvenTree {
public:
	vector <int> getTree(vector <string> x) {
		int N = x.size();
		bool valid = false;
		vi ng(1, -1);
		REP(i, N) {
			REP(j, N) {
				if (x[i][j] == 'O') {
					valid = true;
				}
				if (i == j) {
					if (x[i][j] == 'O') {
						return ng;
					}
				}
				else {
					if (x[i][j] != x[j][i]) {
						return ng;
					}
				}
				REP(k, N) {
					if (i != j && i != k && j != k) {
						if (x[i][j] == x[i][k] && x[j][k] == 'O') {
							return ng;
						}
						else if (x[i][j] != x[i][k] && x[j][k] == 'E') {
							return ng;
						}

					}
				}
			}
		}
		if (!valid) {
			return ng;
		}

		vi ans;
		vi used(N, 0);
		used[0] = 1;
		FOR(i, 1, N - 1) {
			if (x[0][i] == 'O') {
				used[i] = 1;
				ans.push_back(0);
				ans.push_back(i);
			}
		}

		FOR(i, 1, N - 1) {
			if (x[0][i] == 'E') {
				FOR(j, 1, N - 1) {
					if (i != j && used[j]) {
						used[j] = 1;
						ans.push_back(i);
						ans.push_back(j);
						break;
					}
				}
			}
		}

		return ans;
	}
};



// Powered by FileEdit
// Powered by moj 4.18 [modified TZTester]
// Powered by CodeProcessor
