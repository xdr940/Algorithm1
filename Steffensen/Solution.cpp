#include "pch.h"
#include "Solution.h"


Solution::Solution()
{
}


Solution::~Solution()
{
}

void Solution::steffensen(int n)
{

	vector<float>x;
	vector<float>y;
	vector<float>z;
	float x0 = 1.5;
	x.resize(n);
	y.resize(n);
	z.resize(n);

	x[0] = x0;
	for (int k = 0; k < n-1; k++) {
		y[k] = phi(x[k]);
		z[k] = phi(y[k]);
		x[k + 1] = x[k] - (y[k] - x[k])*(y[k] - x[k]) / (z[k] - 2 * y[k] + x[k]);
		
	}
	cout << "xk-------------yk--------------zk----------" << endl;
	for (int k = 0; k < n; k++) {
		cout << x[k] << setw(10)<< y[k] << setw(10) << z[k] << endl;
	}

}
