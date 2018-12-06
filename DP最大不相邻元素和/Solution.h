#pragma once
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();
	void DC_rec();
	void DP();

private:
	int n;
	vector<vector<int>>xs;
	vector<int>arr;
	vector<int>OPT_arr;
	vector<int>prev;
	int max(int i, int j);
	int opt(int i);//传不出路由信息

};

