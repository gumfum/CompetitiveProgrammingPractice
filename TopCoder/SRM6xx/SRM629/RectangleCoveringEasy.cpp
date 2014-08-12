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

class RectangleCoveringEasy {
public:
	int solve(int holeH, int holeW, int boardH, int boardW) {
		if (holeH < boardH && holeW < boardW) {
			return 1;
		}
		if (holeH <= boardH && holeW < boardW) {
			return 1;
		}
		if (holeH < boardH && holeW <= boardW) {
			return 1;
		}
		if (holeH < boardW && holeW < boardH) {
			return 1;
		}
		if (holeH <= boardW && holeW < boardH) {
			return 1;
		}
		if (holeH < boardW && holeW <= boardH) {
			return 1;
		}
		return -1;
	}
};



// Powered by FileEdit
// Powered by moj 4.18 [modified TZTester]
// Powered by CodeProcessor
