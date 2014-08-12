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
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n) FOR(i,0,(n)-1)

class CandyMaking {
public:
	double findSuitableDensity(vector <int> containerVolume, vector <int> desiredWeight) {
		int size = containerVolume.size();
		vector<double> density(size);
		REP(i, size) {
			density[i] = 1. * desiredWeight[i] / containerVolume[i];
		}

		double ans = 1LL << 60;
		REP(i, size) {
			double tmp = 0;
			REP(j, size) {
				tmp += abs((density[j] - density[i]) * containerVolume[j]);
			}
			ans = min(ans, tmp);
		}

		return ans;
	}
};



// Powered by FileEdit
// Powered by moj 4.18 [modified TZTester]
// Powered by CodeProcessor
