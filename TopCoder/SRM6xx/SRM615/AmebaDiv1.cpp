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
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n) FOR(i,0,(n)-1)

class AmebaDiv1 {
public:
int count( vector <int> X ) {
	int size = X.size();
	vi finish(size);
	REP(i, size) {
		int st = X[i];
		REP(j, size) {
			if(st == X[j]) {
				st += X[j];
			}
		}
		finish[i] = st;
	}

	set<int> ans;
	REP(i, size) {
		bool ok = false;
		REP(j, size) {
			if(X[i] == finish[j]) {
				ok = true;
			}
		}
		if(!ok) {
			ans.insert(X[i]);
		}
	}

	return ans.size();
}
};



// Powered by FileEdit
// Powered by moj 4.18 [modified TZTester]
// Powered by CodeProcessor
