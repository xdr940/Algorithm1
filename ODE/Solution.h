#pragma once
class Solution
{
public:
	Solution();
	~Solution();

	itype Eular(itype xn, itype yn);
	itype ImprovedEular(itype xn,itype yn);
	itype trapezoid(itype xn, itype yn,int k);
	void start();
private:
	itype x0 = 0;
	itype h = 0.1;
	itype y0 = 0;
	itype xend = 0.5;
	int N = 5;

	vector<itype>x;
	vector<itype>y;
	vector<itype>y_improved_eular;//改进欧拉
	vector<itype>y_trapezoid;//梯形法

};

