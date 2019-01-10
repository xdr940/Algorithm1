#include "pch.h"
#include "Romberg_solution.h"

itype Romberg_solution::SDTM(int k,itype &h)//逐次二分，纵向
{
	h /= 2;
	itype temp=0;
	itype xk_12 = 0;
	int i = 0;
	while (1) {
		xk_12 = 2 * h*i + h;//把在原来区间二分后的新增函数值算出来，求和
		if (xk_12 > b)break;
		temp += f(xk_12);
		i++;
	}
	

	return 0.5*T[k-1][0]+h*temp;
}

itype Romberg_solution::Rchardson(itype m, itype t1, itype t2)//外推加速，横向
{	itype temp = pow(4, m);
	return temp / (temp - 1)*t1 - 1 / (temp - 1)*t2;
}

void Romberg_solution::start(int K, int M)
{
	T.resize(K);
	for (int i = 0; i < M; i++) {
		T[i].resize(M);
	}

	T[0][0] = (h / 2)*(f(a) + f(b));


	for (int k = 1; k<K; k++) {
		for (int m = 0; m <=k; m++) {
			if (m == 0) {//SDTM
				T[k][m] = SDTM(k,h);
			}
			else {
				T[k][m] = Rchardson(m, T[k][m - 1], T[k-1][m - 1]);
			
			}
			
		}
	}
	//下三角输出
	for (int k = 0; k < K; k++) {
		for (int m = 0; m <= k; m++) {
			cout << T[k][m]<<"  ";
			
		}
		cout << endl;
	}



}
