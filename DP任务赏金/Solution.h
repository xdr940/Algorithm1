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
	int max(int i, int j) {
		if (i > j)return i;
		else return j;
	}
	int opt(int i) {//��������Դ�����·����Ϣ
		if (i <= 0)return 0;
		if (i == 1)return tasks[i].cost;
		int temp= max(opt(i - 1), tasks[i].cost + opt(prev[i]));
		return temp;
	}
};

