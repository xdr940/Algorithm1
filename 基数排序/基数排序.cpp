// 基数排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<set>
using namespace std;
int main2()
{
	set<vector<int>>iset;

	vector<int>a = { 1,2,3 };
	iset.insert(a);
	vector<int>b = { 1,2,3 };
	

	iset.insert(b);
	
	set<vector<int>>::iterator ite1 = iset.begin();
	for (; ite1 != iset.end(); ite1++) {
		for (int i = 0; i < (*ite1).size(); i++) {
			cout << (*ite1)[i] << " ";

		}
		cout << endl;
	}
	vector<vector<int>>as;
	copy(iset.begin(), iset.end(), back_inserter(as));
	cout << endl << "=============" << endl;
	for (int i = 0; i < as.size(); i++) {
		for (int j = 0; j < as[i].size(); j++) {
			cout << as[i][j] << " ";
		}cout << endl;
	}
	return 0;

}

int main() {

	vector<int>a = { 1,1,1 };
	vector<int>b = { 1,2,1 };

	vector<vector<int>>as;
	as.push_back(a);
	if (as.size() &&( as.back() == b)) { cout << "1"; }

}
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
