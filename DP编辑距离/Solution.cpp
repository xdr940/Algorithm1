#include "pch.h"
#include "Solution.h"


int Solution::minDistance(string s, string d)
{

	//word2是模板序列
	//word1是测试序列
	m = s.size();
	n = d.size();
	this->s = s;
	this->d = d;
	if (m == 0)return n;
	if (n == 0)return m;


	opt_mat.resize(m + 1);
	for (int i = 0; i < opt_mat.size(); i++) {
		opt_mat[i].resize(n + 1, 0);
	}


	for (int i = 1; i <= m; i++) {
		opt_mat[i][0] = opt_mat[i - 1][0] + 1;
	}
	for (int i = 1; i <= n; i++) {
		opt_mat[0][i] = opt_mat[0][i - 1] + 1;
	}
	//按列写opt
	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= m; i++) {
			int c1 = opt_mat[i - 1][j - 1] + dis(i, j, -1, -1);
			int c2 = opt_mat[i - 1][j] + dis(i, j, -1, 0);
			int c3 = opt_mat[i][j - 1] + dis(i, j, 0, -1);
			opt_mat[i][j] = min(c1, c2, c3);
		}
	}

#ifdef DEBUG
	cout << endl;
	for (int i = 0; i < opt_mat.size(); i++) {
		for (int j = 0; j < opt_mat[i].size(); j++) {
			cout << opt_mat[i][j] << " ";
			
		}cout << endl;
	}

#endif // DEBUG

	return opt_mat[m][n];


}
