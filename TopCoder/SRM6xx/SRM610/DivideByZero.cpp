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
const double EPS = 1e-12;
const double PI = acos(-1.0);
const int INF = INT_MAX/10;

class DivideByZero {
public:
int CountNumbers( vector <int> numbers ) {
	vi exists(101, 0);
	int size = numbers.size();
	REP(i, size) {
		exists[numbers[i]] = 1;
	}

	bool update = true;
	while(update) {
		update = false;
		sort(RALL(numbers));
		size = numbers.size();
		REP(i, size-1) {
			FOR(j, i+1, size-1) {
				int res = numbers[i]/numbers[j];
				if(!exists[res]) {
					exists[res] = 1;
					numbers.push_back(res);
					update = true;
				}
			}
		}
	}

	return numbers.size();
}
};



// Powered by FileEdit
// Powered by moj 4.18 [modified TZTester]
// Powered by CodeProcessor