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
typedef vector<int> vi;
typedef vector<vi>  vvi;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n) FOR(i,0,(n)-1)

class WolfCardGame {
public:
	vector <int> createAnswer(int N, int K) {
		vi res;

		FOR(i, 2, 6) {
			if (N%i != 0) {
				FOR(j, 1, K) {
					res.push_back(i*j);
				}
				break;
			}
		}

		if (N == 60) {
			res.push_back(1);
			FOR(i, 1, K - 1) {
				res.push_back(7 * i);
			}
		}

		return res;
	}
};



// Powered by FileEdit
// Powered by moj 4.18 [modified TZTester]
// Powered by CodeProcessor
