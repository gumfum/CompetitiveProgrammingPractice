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

int getLargestRectangle(int size, vi hist) {
	stack<pii> S;
	int maxv = 0;
	hist.push_back(0);

	REP(i, size+1) {
		pii rect;
		rect.first = hist[i];
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

int main() {
	int H, W;
	while(cin >> H >> W, H) {
		vs field(H);
		REP(i, H) {
			cin >> field[i];
		}

		vvi hist(H, vi(W, 0));
		REP(i, H) {
			REP(j, W) {
				if(i == 0) {
					if(field[i][j] == '.') {
						hist[i][j] = 1;
					}
				} else {
					if(field[i][j] == '*') {
						hist[i][j] = 0;
					} else {
						hist[i][j] = hist[i-1][j]+1;
					}
				}
			}
		}

		int ans = 0;
		REP(i, H) {
			ans = max(ans, getLargestRectangle(W, hist[i]));
		}

		cout << ans << endl;
	}
}