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

class TheMatrix {
public:
int getLargestRectangle(int size, vi buffer) {
	stack<pii> S;
	int maxv = 0;
	buffer.push_back(0);

	REP(i, size+1) {
		pii rect;
		rect.first = buffer[i];
		rect.second = i;
		if(S.empty()) {
			S.push(rect);
		} else {
			if(S.top().first < rect.first) {
				S.push(rect);
			} else if(S.top().first > rect.first) {
				int target = i;
				while(!S.empty() && S.top().first >= rect.first) {
					pii pre = S.top();
					S.pop();
					int area = pre.first * (i-pre.second);
					maxv = max(maxv, area);
					target = pre.second;
				}
				rect.second = target;
				S.push(rect);
			}
		}
	}

	return maxv;
}

vvi hist(vvi field) {
	int height = field.size(), width = field[0].size();
	vvi res(height, vi(width));
	REP(i, width) {
		if(field[0][i]) {
			res[0][i] = 1;
		}
	}

	REP(i, height-1) {
		REP(j, width) {
			if(field[i+1][j]) {
				res[i+1][j] = res[i][j]+1;
			}
		}
	}

	return res;
}

int MaxArea( vector <string> board ) {
	int height = board.size(), width = board[0].size();
	int ans = 0;

	vvi field1(height, vi(width, 0));
	REP(i, height) {
		REP(j, width) {
			if(board[i][j] == (((i+j)%2)+'0')) {
				field1[i][j] = 1;
			}
		}
	}
	field1 = hist(field1);
	REP(i, height) {
		ans = max(ans, getLargestRectangle(width, field1[i]));
	}

	vvi field2(height, vi(width, 0));
	REP(i, height) {
		REP(j, width) {
			if(board[i][j] == (((i+j+1)%2)+'0')) {
				field2[i][j] = 1;
			}
		}
	}
	field2 = hist(field2);
	REP(i, height) {
		ans = max(ans, getLargestRectangle(width, field2[i]));
	}

	return ans;
}
};



// Powered by FileEdit
// Powered by moj 4.18 [modified TZTester]
// Powered by CodeProcessor
