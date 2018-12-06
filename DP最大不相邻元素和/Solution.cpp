#include "pch.h"
#include "Solution.h"


Solution::Solution()
{
}


Solution::~Solution()
{
}

void Solution::DC_rec()
{	//问题初始化
	int n = 7;
	arr.clear();
	arr.resize(n);
	arr = { 1,2,4,1,7,8,3 };
	cout<<opt(6);



}

void Solution::DP()
{	//step0. 问题载入
	int n = 7;
	arr.clear();
	arr.resize(n);
	arr = { 1,2,4,1,7,8,3 };

	//step1.定义最优解空间结构，并写入边界情况
	xs.resize(n);
	xs[0] = {0};
	if (arr[0] > arr[1])xs[1] = { 0 };
	else xs[1] = { 1 };
	//step2.构造prev
	prev.resize(n);
	prev[0] = -1;//先填写边界
	if (arr[0] > arr[1])prev[1] = 0;
	else prev[1] = 1;
	for (int i = 2; i < n; i++) {
		prev[i] = i - 2;
	}

	//step3.最优值结构定义,填写边界情况
	//opt_arr[i]=max(OPT_arr[prev[i]] + arr[i],OPT_arr[i - 1]);
	OPT_arr.resize(n);
	OPT_arr[0] = arr[0];
	OPT_arr[1] = max(arr[0], arr[1]);//先填写边界

	//step4.写入最优值，最优解
	for (int i = 2; i < OPT_arr.size(); i++) {
		int A = OPT_arr[prev[i]] + arr[i];
		int B = OPT_arr[i - 1];
		if (A > B) {
			OPT_arr[i] = A;
			xs[i] = xs[prev[i]];
			xs[i].push_back(i);
		}
		else {
			OPT_arr[i] = B;
			xs[i] = xs[i - 1];
		}

	}

	//step5.输出

	cout << "最优解如下" << endl;
	for (int i = 0; i < xs.size(); i++) {
		for (int j = 0; j < xs[i].size(); j++) {
		
			cout << xs[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	cout << "最优值如下" << endl;
	//输出最优值
	for (int i = 0; i < OPT_arr.size(); i++) {
		cout << OPT_arr[i] << " ";
	}
	cout << endl;
}

int Solution::max(int i, int j)
{
	if (i > j)return i;
	else return j;
}

int Solution::opt(int i)
{
	if (i ==0)return arr[0];
	if (i == 1)return max(arr[0], arr[1]);
	return max(opt(i - 1), opt(i - 2) + arr[i]);
}
