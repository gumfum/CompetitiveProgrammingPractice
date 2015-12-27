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

typedef vector<string> vs;

class FourStrings {
public:
	int shortestLength(string a, string b, string c, string d) {
		vs strs(4);
		strs[0] = a;
		strs[1] = b;
		strs[2] = c;
		strs[3] = d;

		vi v(4);
		REP(i, 4) {
			v[i] = i;
		}

		int ans = INF;
		do {
			string sa = strs[v[0]];
			FOR(i, 1, 3) {
				if (sa.find(strs[v[i]]) != string::npos) {
					continue;
				}
				else {
					string sb = strs[v[i]];
					int al = sa.size(), bl = sb.size();
					int l = min(al, bl);
					int le = 0;
					FOR(j, 1, l) {
						if (sa.substr(al - j, al) == sb.substr(0, j)) {
							le = j;
						}
					}
					sa = sa + sb.substr(le, bl);
				}
			}
			if (sa.size() < ans) {
				ans = sa.size();
				//cout << sa << endl;
			}
		} while (next_permutation(ALL(v)));

		return ans;
	}
};



// Powered by FileEdit
// Powered by moj 4.18 [modified TZTester]
// Powered by CodeProcessor
