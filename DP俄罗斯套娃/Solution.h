#pragma once
using namespace std;
typedef int itype;//��Ŀ85�����������ڴ������������short������

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

