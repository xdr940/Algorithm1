#include "pch.h"
#include "Solution.h"



int Solution::minimumTotal(vector<vector<int>>& triangle)
{
	n = triangle.size();
	if (n == 0)return 0;
	if (n == 1)return triangle[0][0];
	if (n == 2) {
		int a = triangle[0][0];
		int b = triangle[1][0];
		int c = triangle[1][1];
		return a + b > a + c ? a + b : a + c;
	}
	
	//opt_mat 初始化
	opt_mat.resize(n);
	for (int i = 0; i < n; i++) {
		opt_mat[i].resize(triangle[i].size());
	}
	//边界情况
	opt_mat[0][0] = triangle[0][0];
	for (int i = 1; i < n; i++) {
		opt_mat[i][0] = opt_mat[i - 1][0] + triangle[i][0];
		opt_mat[i][opt_mat[i].size() - 1] = opt_mat[i - 1][opt_mat[i - 1].size() - 1] + triangle[i][opt_mat[i].size() - 1];
	}
	//x 初始化
	x.resize(n, 0);
	x[0]= triangle[0][0];

#ifdef DEBUG
	cout << endl;
	for (int i = 0; i < opt_mat.size(); i++) {
		for (int j = 0; j < opt_mat[i].size(); j++) {
		
			cout << opt_mat[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

#endif // DEBUG



	for (int i = 2; i < n; i++) {
		for (int j = 1; j < opt_mat[i].size()-1; j++) {
		
				int A = opt_mat[i-1][j] + triangle[i][j];
				int B = opt_mat[i - 1][j-1] + triangle[i][j];
				if (A < B) {
					opt_mat[i][j] = A;
					x[i] = j;

				}
				else {
					opt_mat[i][j] = B;
					x[i] = j - 1;
				}
			
			

		}

	}

	return *min_element(opt_mat.back().begin(), opt_mat.back().end());

}
