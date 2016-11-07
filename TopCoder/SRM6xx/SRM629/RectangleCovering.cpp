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

class RectangleCovering {
public:
	int minimumNumber(int holeH, int holeW, vector <int> boardH, vector <int> boardW) {
		int l = boardH.size(), ansa = INF, ansb = INF;
		vector<pii> board;
		REP(i, l) {
			int h = boardH[i], w = boardW[i];
			if (holeH < h) {
				if (holeH < w && w < h) {
					board.push_back(pii(h, w));
				}
				else {
					board.push_back(pii(w, h));
				}
			}
			else if (holeH < w) {
				board.push_back(pii(h, w));
			}
		}
		if (board.size() > 0) {
			sort(RALL(board));
			int sum = 0;
			REP(i, board.size()) {
				sum += board[i].first;
				if (holeW <= sum) {
					ansa = i + 1;
					break;
				}
			}
		}

		board.clear();
		REP(i, l) {
			int h = boardH[i], w = boardW[i];
			if (holeW < h) {
				if (holeW < w && w < h) {
					board.push_back(pii(h, w));
				}
				else {
					board.push_back(pii(w, h));
				}
			}
			else if (holeW < w) {
				board.push_back(pii(h, w));
			}
		}
		if (board.size() > 0) {
			sort(RALL(board));
			int sum = 0;
			REP(i, board.size()) {
				sum += board[i].first;
				if (holeH <= sum) {
					ansb = i + 1;
					break;
				}
			}
		}

		if (ansa == ansb && ansb == INF) {
			return -1;
		}
		else {
			return min(ansa, ansb);
		}
	}
};



// Powered by FileEdit
// Powered by moj 4.18 [modified TZTester]
// Powered by CodeProcessor
