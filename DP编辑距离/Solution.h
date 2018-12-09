#pragma once
using namespace std;
class Solution
{
public:

	int minDistance(string s, string d);

private:
	string s, d;
	vector<vector<int>>opt_mat;//opt_mat[i][j]意思是 s[0:i] 到 d[0:j]的编辑距离
	int m = 0, n = 0;//分别为行数(目标串长度)、列数(源串长度)
	int dis(int i, int j, int di, int dj) {
		if (di == -1 && dj == -1) {
			if (s[i - 1] == d[j - 1])return 0;
			else return 1;
		}
		
		if (di == -1 && dj == 0) return 1;
		if (di == 0 && dj == -1)return 1;


	}
	int min(int a, int b, int c) {

		if (a <= b&&a <= c)return a;
		if (b <= a&&b <= c)return b;
		if (c <= a&&c <= b)return c;
	
	}
};

