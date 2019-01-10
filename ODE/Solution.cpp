#include "pch.h"
#include "Solution.h"




Solution::Solution()
{
}


Solution::~Solution()
{
}

itype Solution::Eular(itype xn, itype yn)
{
	return yn + h * f(xn, yn);
}

itype Solution::ImprovedEular(itype xn, itype yn)
{
	return yn + 0.5*h*(f(xn, yn) + f(xn + h, Eular(xn, yn)));
}
itype Solution::trapezoid(itype xn, itype yn,int k)
{
	itype yn1_ = Eular(xn, yn);
	while (k > 0) {
		yn1_ = yn + 0.5*h*(f(xn, yn) + f(xn + h, yn1_));
		k--;
	}
	


	return yn1_;

}

void Solution::start()
{
	x.resize(N + 1);
	y.resize(N + 1);
	y_improved_eular.resize(N + 1);
	y_trapezoid.resize(N + 1);

	x[0] = x0;
	y[0] = y0;
	y_improved_eular[0] = 0;
	y_trapezoid[0] = 0;
	
	for (int i = 1; i <= N ; i++) {
		x[i] = x[i - 1] + h;
		y[i] = Eular(x[i - 1], y[i - 1]);
		y_improved_eular[i] = ImprovedEular(x[i - 1], y_improved_eular[i - 1]);
		y_trapezoid[i] = trapezoid(x[i - 1], y_trapezoid[i - 1],5);//梯形法多了迭代这一项每一个点迭代5次
	}
	cout << "xn "<<setw(20)<<"Eular"<<setw(20)<<"improved eular" << setw(20) << "trapezoid" << endl;
	for (int i = 0; i <= N; i++) {
		cout << x[i] << setw(20)<< y[i] <<setw(20)<<y_improved_eular[i]<<setw(20)<<y_trapezoid[i]<< endl;
	}



}
