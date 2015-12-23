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

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

class BoardEscapeDiv2 {
public:
	string findWinner(vector <string> s, int k) {
		int H = s.size(), W = s[0].size();
		int sy = -1, sx = -1;
		REP(i, H) {
			REP(j, W) {
				if (s[i][j] == 'T') {
					sy = i;
					sx = j;
				}
			}
		}

		string winner = "";
		int bobWinCount = 0;
		bool moved = false;
		REP(d, 4) {
			int y = sy + dy[d], x = sx + dx[d];
			if (0 <= y && y < H && 0 <= x && x < W && s[y][x] != '#') {
				moved = true;
				if (s[y][x] == 'E') {
					winner = "Alice";
					goto show;
				}
				else if (s[y][x] == '.') {
					REP(dd, 4) {
						int ny = y + dy[dd], nx = x + dx[dd];
						if (0 <= ny && ny < H && 0 <= nx && nx < W && s[ny][nx] == 'E') {
							bobWinCount++;
							break;
						}
					}
				}
			}
			else {
				bobWinCount++;
			}
		}

		if (!moved) {
			winner = "Bob";
		}
		else if (k == 1) {
			winner = "Alice";
		}
		else if (bobWinCount == 4) {
			winner = "Bob";
		}
		else if (k % 2) {
			winner = "Alice";
		}
		else {
			winner = "Bob";
		}

	show:
		return winner;
	}
};



// Powered by FileEdit
// Powered by moj 4.18 [modified TZTester]
// Powered by CodeProcessor
