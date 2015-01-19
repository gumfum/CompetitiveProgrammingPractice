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
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n) FOR(i,0,(n)-1)


class BacteriesColony {
public:
	vector <int> performTheExperiment(vector <int> colonies) {
		int size = colonies.size();
		bool flag = true;
		while (flag) {
			vi nc(colonies);
			flag = false;
			FOR(i, 1, size - 2) {
				if (colonies[i] < colonies[i - 1] && colonies[i] < colonies[i + 1]) {
					nc[i]++;
					flag = true;
				}
				else if (colonies[i] > colonies[i - 1] && colonies[i] > colonies[i + 1]) {
					nc[i]--;
					flag = true;
				}
			}
			colonies = nc;
		}

		return colonies;
	}
};



// Powered by FileEdit
// Powered by moj 4.18 [modified TZTester]
// Powered by CodeProcessor
