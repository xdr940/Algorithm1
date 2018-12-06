#pragma once
struct task {
	int st;
	int ed;
	int cost;
};

class Solution
{
public:
	void DC_rec();//这种递归的其实是分治法
	void DP();
	Solution();
	~Solution();
private:
	int n ;
	vector<int>OPT_array;
	vector<int>prev;
	vector<vector<int>>xs;
	vector<task>tasks;
	int max(int i, int j);
	int opt(int i);//传不出路由信息
};

