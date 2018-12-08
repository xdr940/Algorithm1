#pragma once
using namespace std;
class Solution
{
public:
	void DP();
	void DP_rec();
	Solution();
	~Solution();
private:
	vector<vector<int>>xs;
	vector<int >x;
	vector<int >arr;
	int opt(int i);
	int max(vector<int>s,int a);
	vector<int >opt_vec;
	vector<vector<int>>opt_mat;
	vector<int > Merge(vector<int>a, vector<int>b);
};

