#pragma once

using namespace std;

#define MAX 1000;
class Solution
{
public:
	int minimumTotal(vector<vector<int>>& triangle);
	
private:
	int n;
	vector<vector<int>>opt_mat;//opt_mat[i][j]为到达ij点的最短长度
	vector<int>x;

};

