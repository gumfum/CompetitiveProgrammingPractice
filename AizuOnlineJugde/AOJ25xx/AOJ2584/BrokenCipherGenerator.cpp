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

string Cipher();
string String();
string Letter();
string plusLetter(string str);
string minusLetter(string str);

int p;
string s;

string Cipher() {
	string ret;
	while (p < s.size() && s[p] != ']') {
		ret += String();
	}
	return ret;
}

string String() {
	string ret;
	if (s[p] == '[') {
		p++;
		ret = Cipher();
		reverse(ALL(ret));
		p++;
	}
	else {
		ret = Letter();
	}
	return ret;
}

string Letter() {
	string ret;
	if (s[p] == '+') {
		p++;
		ret = Letter();
		ret = plusLetter(ret);
	}
	else if (s[p] == '-') {
		p++;
		ret = Letter();
		ret = minusLetter(ret);
	}
	else {
		ret = string(1, s[p]);
		p++;
	}
	return ret;
}

string plusLetter(string str) {
	string ret;
	if (str == "?") {
		ret = "?";
	}
	else if (str == "Z") {
		ret = "A";
	}
	else {
		str[0]++;
		ret = str;
	}
	return ret;
}

string minusLetter(string str) {
	string ret;
	if (str == "?") {
		ret = "?";
	}
	else if (str == "A") {
		ret = "Z";
	}
	else {
		str[0]--;
		ret = str;
	}
	return ret;
}

int main() {
	while (cin >> s, s != ".") {
		p = 0;
		string ans = Cipher();
		REP(i, ans.size()) {
			if (ans[i] == '?') {
				ans[i] = 'A';
			}
		}
		cout << ans << endl;
	}

	return 0;
}