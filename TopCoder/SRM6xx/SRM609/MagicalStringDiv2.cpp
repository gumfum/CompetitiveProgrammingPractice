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

class MagicalStringDiv2 {
public:
int minimalMoves( string S ) {
	int ans = 0, length = S.size();
	REP(i, length) {
		if(i < length/2) {
			if(S[i] == '<') {
				ans++;
			}
		} else {
			if(S[i] == '>') {
				ans++;
			}
		}
	}

	return ans;
}
};