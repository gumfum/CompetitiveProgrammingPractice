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
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n) FOR(i,0,(n)-1)

class IdentifyingWood {
public:
	string check(string s, string t) {
		int ssize = s.size(), tsize = t.size();
		int tpos = 0;
		bool ok = false;

		REP(i, ssize) {
			if (s[i] == t[tpos]) {
				tpos++;
			}
			if (tpos == tsize) {
				ok = true;
				break;
			}
		}

		if (ok) {
			return "Yep, it's wood.";
		}
		else {
			return "Nope.";
		}
	}
};



// Powered by FileEdit
// Powered by moj 4.18 [modified TZTester]
// Powered by CodeProcessor
