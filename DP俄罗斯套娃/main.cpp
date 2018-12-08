// 354_Russian Doll Envelopes.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
typedef int itype;

int main()
{
	Solution s;
	vector<pair<int, int>> envelopes;
	envelopes = { {2,100},{3,200},{4,300},{5,500},{5,400},{5,250},{6,370},{6,360},{7,380} } = { {2, 100}, {3, 200}, {4, 300}, {5, 500}, {5, 400}, {5, 250}, {6, 370}, {6, 360}, {7, 380} };
	
	//envelopes = {{1, 1}, {1, 1}, {1, 1}};
	//输出1

	//envelopes = { {1, 3}, {3, 5}, {6, 7}, {6, 8}, {8, 4}, {9, 5} }; 
	//[[1,3],[3,5],[6,7],[6,8],[8,4],[9,5]]
	//输出4 预期3
	
	
	//envelopes = { {46,89},{50,53},{52,68},{72,45},{77,81} };
	//[[46, 89], [50, 53], [52, 68], [72, 45], [77, 81]]
	//预期3
	cout<<s.maxEnvelopes(envelopes);
	return 0;
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
