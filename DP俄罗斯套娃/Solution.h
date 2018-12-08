#pragma once
using namespace std;
typedef int itype;//题目85个样例会有内存溢出，可以用short来减少

class Solution
{
public:
	itype maxEnvelopes(vector<pair<itype, itype>>& envelopes);
	
	

private:
	vector<itype>opt_arr;
	itype opt(int i) {
		if (i == -1) { return 0; }
		else return opt_arr[i];
	}
	vector<vector<itype>>prevs;

	int n = 0;

	itype maxopt(vector<itype>as) {
		itype ret = 0;
		for (int i = 0; i < as.size(); i++) {
			if (ret < opt(as[i])) {
				ret = opt(as[i]);
			}
		
		}
		return ret;
	
	}

};

