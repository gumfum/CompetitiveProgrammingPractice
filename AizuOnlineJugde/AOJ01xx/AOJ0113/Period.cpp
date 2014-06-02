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
#include <list>
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
const double EPS = 1e-10;
const double PI = acos(-1.0);
const int INF = INT_MAX/10;

int main() {
	int p, q;
	while(cin >> p >> q) {
		int pos = 1, r = 1;
		int s, g;
		bool loop = false;
		map<int, int> memo;
		while(r != 0) {
			p *= 10;
			if(memo[p]) {
				loop = true;
				s = memo[p]-1;
				g = pos;
				break;
			} else {
				memo[p] = pos;
				pos++;
			}
			cout << p/q;
			p -= (p/q)*q;
			r = p-(p/q)*q;
		}
		cout << endl;

		if(loop) {
			REP(i, g-1) {
				if(i >= s) {
					cout << "^";
				} else {
					cout << " ";
				}
			}
			cout << endl;
		}
	}
	return 0;
}