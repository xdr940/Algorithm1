#include "pch.h"
#include "Solution.h"


void Solution::DP()
{	//该问题不是DP选择问题，而是划分问题。
	//最优值结构并非二叉树，为i/2叉树，要复杂不少
	
	//step0.问题载入
	int n = 10;
	arr = { 0,1,5,8,9,10,17,17,20,24,30 };

	//step1.解空间构造，这里用没用
	x.resize(n+1,0);
	//step2.prev 这里没用
	
	//step3.最优值空间定义
	//opt(i) = max{arr[i] , opt(i-1)+opt(1) , opt(i-2)+opt(2),...opt(i-j)+opt(j)....}
	
	//step4.求最优值、路由向量，这里边界问题不用问，具有一般性
	vector<int >s(n+1, 0);
	opt_vec.resize(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		int MAX = arr[i];//不划分
		 s[i] = i;
		for (int j = 1; j <= i/2; j++) {//这里用i/2分支，而非之前的二叉
			int A= opt_vec[j] + opt_vec[i - j];
			if (A > MAX) {
				MAX = A;
				s[i] = j;//记录最大划分的小块划分大小
			}
		}
		opt_vec[i] = MAX;//这里是i/2叉树
	}


	//step5.输出
	cout << "最优值为" << endl;
	for (int i = 0; i < opt_vec.size(); i++) {
	
		cout << opt_vec[i] << " ";
	}
	cout << endl;

	cout << "路由向量为" << endl;
	for (int i = 0; i < s.size(); i++) {
		cout << s[i] << " ";
	}
	cout << endl;

	//step6.根据路由向量构造解
	xs.resize(n + 1);
	for (int i = 0; i <= n; i++) {
		if (s[i] == i) {
			vector<int>temp;
			temp.push_back(i);
			xs[i] = temp;
		}
		else {
			//这里有点复杂，可能需要跳很多次才到底，所以这里需要while循环


			vector<int>temp = Merge(xs[s[i - s[i]]], xs[s[i]]);//
			xs[i] = temp;
		}
	
	}
	//输出
	cout << endl;
	for (int i = 0; i < xs.size(); i++) {
		cout << i << " ";

		for (int j = 0; j < xs[i].size(); j++) {
			cout << xs[i][j] << " ";
		}
		cout << endl;
	}

}

void Solution::DP_rec()
{
	int n = 11;
	arr = { 0,1,5,8,9,10,17,17,20,24,30 };
	cout << opt(8);

}

Solution::Solution()
{
}


Solution::~Solution()
{
}

int Solution::opt(int i)

{	
	if (i == 0 || i == 1)return arr[i];
	int a=arr[i];
	vector<int>subBranche(i/2, 0);
	for (int j = 1; j <= i/2; j++) {
		subBranche[j-1] = opt(i-j) + opt(j);
	}
	return max(subBranche,a);

}

int Solution::max(vector<int>s,int a)
{
	int temp = a;
	for (int i = 0; i < s.size(); i++) {
		if (temp < s[i])temp = s[i];
	}
	return temp;
}

vector<int> Solution::Merge(vector<int> a, vector<int> b)
{
	vector<int>ret;
	ret = a;
	for (int i = 0; i < b.size(); i++) {
		ret.push_back(a[i]);
	
	}
	return ret;
}
