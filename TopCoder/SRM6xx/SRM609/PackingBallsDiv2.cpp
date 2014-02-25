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
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n) FOR(i,0,(n)-1)

class PackingBallsDiv2 {
public:
int minPacks( int R, int G, int B ) {
	int ans = ceil(R/3.)+ceil(G/3.)+ceil(B/3.);
	R--; G--; B--;
	ans = min(ans, int(ceil(R/3.)+ceil(G/3.)+ceil(B/3.))+1);
	R--; G--; B--;
	ans = min(ans, int(ceil(R/3.)+ceil(G/3.)+ceil(B/3.))+2);

	return ans;
}
};