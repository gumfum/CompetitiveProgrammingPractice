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

class TaroString {
public:
string getAnswer( string S ) {
	int size = S.size();
	string str;
	REP(i, size) {
		if(S[i] == 'A' || S[i] == 'C' || S[i] == 'T') {
			str.push_back(S[i]);
		}
	}

	if(str == "CAT") {
		return "Possible";
	} else {
		return "Impossible";
	}
}
};



// Powered by FileEdit
// Powered by moj 4.18 [modified TZTester]
// Powered by CodeProcessor
