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

void show_field(string field) {
	REP(i, 4) {
		REP(j, 8) {
			cout << field[16 * i + 2 * j] << field[16 * i + 2 * j + 1] << " ";
		}
		cout << endl;
	}
}

int main() {
	string goal;
	REP(i, 4) {
		REP(j, 8) {
			if (j != 7) {
				goal.push_back('1' + i);
				goal.push_back('1' + j);
			}
			else {
				goal.push_back('0');
				goal.push_back('0');
			}
		}
	}

	int n;
	cin >> n;

	REP(hoge, n) {
		vvi field(4, vi(8));
		REP(i, 4) {
			FOR(j, 1, 7) {
				int num;
				cin >> num;
				if (num % 10 == 1) {
					field[num / 10 - 1][0] = num;
				}
				else {
					field[i][j] = num;
				}
			}
		}
		string start;
		REP(i, 4) {
			REP(j, 8) {
				if (field[i][j] == 0) {
					start.push_back('0');
					start.push_back('0');
				}
				else {
					start.push_back('0' + field[i][j] / 10);
					start.push_back('0' + field[i][j] % 10);
				}
			}
		}

		map<string, int> memo;
		queue<string> Q;
		Q.push(start);
		memo[start] = 0;
		bool finished = false;
		while (!Q.empty()) {
			string s = Q.front();
			Q.pop();

			if (s == goal) {
				finished = true;
				break;
			}

			vi change_pos;
			vs change_str;
			REP(i, 32) {
				if (s[2 * i] == '0') {
					if (s[2 * i - 1] != '7') {
						string str = s.substr(2 * (i - 1), 2);
						str[1]++;
						change_pos.push_back(i);
						change_str.push_back(str);
					}
				}
			}

			int size = change_pos.size();
			REP(i, size) {
				string str = change_str[i];
				REP(j, 32) {
					if (s[2 * j] == str[0] && s[2 * j + 1] == str[1])  {
						int pos = change_pos[i];
						string ns = s;
						ns[2 * pos] = str[0];
						ns[2 * pos + 1] = str[1];
						ns[2 * j] = '0';
						ns[2 * j + 1] = '0';
						if (memo[ns] == 0) {
							memo[ns] = memo[s] + 1;
							Q.push(ns);
						}
					}
				}
			}
		}

		if (finished) {
			cout << memo[goal] << endl;
		}
		else {
			cout << -1 << endl;
		}
	}

	return 0;
}