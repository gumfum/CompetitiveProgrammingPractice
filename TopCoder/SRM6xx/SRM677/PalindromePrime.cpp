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

class PalindromePrime {
public:
	int count(int L, int R) {
		vi isPrime(1001, 1);
		isPrime[0] = isPrime[1] = 0;
		FOR(i, 2, 33) {
			if (isPrime[i]) {
				for (int j = i*i; j <= 1000; j += i) {
					isPrime[j] = 0;
				}
			}
		}

		int ans = 0;

		FOR(i, L, R) {
			string s = toStr(i);
			int size = s.size();
			bool isPalin = true;

			REP(j, size) {
				if (s[j] != s[size - j - 1]) {
					isPalin = false;
				}
			}

			if (isPalin && isPrime[i]) {
				ans++;
			}
		}

		return ans;
	}
};



// Powered by FileEdit
// Powered by moj 4.18 [modified TZTester]
// Powered by CodeProcessor
