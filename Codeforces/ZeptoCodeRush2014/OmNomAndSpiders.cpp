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

void showLine(vi line) {
	int size = line.size();
	REP(i, size - 1) {
		cout << line[i] << " ";
	}
	cout << line[size - 1] << endl;
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	vs field(n);
	vi line(m);
	REP(i, n) {
		cin >> field[i];
		REP(j, m) {
			switch (field[i][j]) {
			case 'R':
				if (j + i < m) {
					line[j + i]++;
				}
				break;
			case 'L':
				if (0 <= j - i) {
					line[j - i]++;
				}
				break;
			case 'U':
				if (i % 2 == 0) {
					line[j]++;
				}
				break;
			case 'D':
			default:
				break;
			}
		}
	}

	showLine(line);
	return 0;
}