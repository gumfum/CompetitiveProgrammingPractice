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

vs split(string str, string delim) {
	vs result;
	int pos;

	while ((pos = str.find_first_of(delim)) != str.npos) {
		if (pos > 0) {
			result.push_back(str.substr(0, pos));
		}
		str = str.substr(pos + 1);
	}
	if (str.length() > 0) {
		result.push_back(str);
	}

	return result;
}

int main() {
	string line;
	while (getline(cin, line)) {
		vs str = split(line, " ");
		int size = str.size();
		stack<double> S;
		REP(i, size) {
			if (str[i] == "+") {
				double b = S.top();
				S.pop();
				double a = S.top();
				S.pop();
				S.push(a + b);
			}
			else if (str[i] == "-") {
				double b = S.top();
				S.pop();
				double a = S.top();
				S.pop();
				S.push(a - b);
			}
			else if (str[i] == "*") {
				double b = S.top();
				S.pop();
				double a = S.top();
				S.pop();
				S.push(a * b);
			}
			else if (str[i] == "/") {
				double b = S.top();
				S.pop();
				double a = S.top();
				S.pop();
				S.push(a / b);
			}
			else {
				S.push(toInt(str[i]));
			}
		}
		double ans = S.top();
		printf("%.6f\n", ans);
	}
}