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

void show(int caseNum, int pos) {
	cout << "Case #" << flush;
	cout << caseNum << flush;
	cout << ": " << flush;
	cout << pos << endl;
}

int main() {
	int T;
	cin >> T;
	REP(caseNum, T) {
		int M, C, W;
		cin >> M >> C >> W;
		vi A(C), B(C);
		REP(i, C) {
			cin >> A[i] >> B[i];
		}
		int pos = W;
		for (int i = C - 1; i >= 0; i--) {
			if (pos > (A[i] + B[i] - 1)) {

			}
			else if (pos > B[i]) {
				pos -= B[i];
			}
			else if (pos <= B[i]) {
				pos = A[i] + pos - 1;
			}
			//cout << "*" << pos << "*" << endl;
		}
		show(caseNum+1, pos);
	}
}