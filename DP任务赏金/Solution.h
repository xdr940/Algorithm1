#pragma once
struct task {
	int st;
	int ed;
	int cost;
};

class Solution
{
public:
	void DC_rec();//���ֵݹ����ʵ�Ƿ��η�
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
	int opt(int i);//������·����Ϣ
};

