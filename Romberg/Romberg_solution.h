#pragma once
class Romberg_solution
{
public:
	Romberg_solution(){}
	itype SDTM(int m,itype &h);//Successive dichotomy trapezoidal method
	itype Rchardson(itype m, itype a, itype b);
	void start(int k, int m);
private:
	vector<vector<itype>>T;
	itype a = 0;
	itype b = 3;//区间
	itype h = b - a;//初始步长

};

