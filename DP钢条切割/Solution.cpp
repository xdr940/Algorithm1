#include "pch.h"
#include "Solution.h"


void Solution::DP()
{	//�����ⲻ��DPѡ�����⣬���ǻ������⡣
	//����ֵ�ṹ���Ƕ�������Ϊi/2������Ҫ���Ӳ���
	
	//step0.��������
	int n = 10;
	arr = { 0,1,5,8,9,10,17,17,20,24,30 };

	//step1.��ռ乹�죬������û��
	x.resize(n+1,0);
	//step2.prev ����û��
	
	//step3.����ֵ�ռ䶨��
	//opt(i) = max{arr[i] , opt(i-1)+opt(1) , opt(i-2)+opt(2),...opt(i-j)+opt(j)....}
	
	//step4.������ֵ��·������������߽����ⲻ���ʣ�����һ����
	vector<int >s(n+1, 0);
	opt_vec.resize(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		int MAX = arr[i];//������
		 s[i] = i;
		for (int j = 1; j <= i/2; j++) {//������i/2��֧������֮ǰ�Ķ���
			int A= opt_vec[j] + opt_vec[i - j];
			if (A > MAX) {
				MAX = A;
				s[i] = j;//��¼��󻮷ֵ�С�黮�ִ�С
			}
		}
		opt_vec[i] = MAX;//������i/2����
	}


	//step5.���
	cout << "����ֵΪ" << endl;
	for (int i = 0; i < opt_vec.size(); i++) {
	
		cout << opt_vec[i] << " ";
	}
	cout << endl;

	cout << "·������Ϊ" << endl;
	for (int i = 0; i < s.size(); i++) {
		cout << s[i] << " ";
	}
	cout << endl;

	//step6.����·�����������
	xs.resize(n + 1);
	for (int i = 0; i <= n; i++) {
		if (s[i] == i) {
			vector<int>temp;
			temp.push_back(i);
			xs[i] = temp;
		}
		else {
			//�����е㸴�ӣ�������Ҫ���ܶ�βŵ��ף�����������Ҫwhileѭ��


			vector<int>temp = Merge(xs[s[i - s[i]]], xs[s[i]]);//
			xs[i] = temp;
		}
	
	}
	//���
	cout << endl;
	for (int i = 0; i < xs.size(); i++) {
		cout << i << " ";

		for (int j = 0; j < xs[i].size(); j++) {
			cout << xs[i][j] << " ";
		}
		cout << endl;
	}

}

void Solution::DP_rec()
{
	int n = 11;
	arr = { 0,1,5,8,9,10,17,17,20,24,30 };
	cout << opt(8);

}

Solution::Solution()
{
}


Solution::~Solution()
{
}

int Solution::opt(int i)

{	
	if (i == 0 || i == 1)return arr[i];
	int a=arr[i];
	vector<int>subBranche(i/2, 0);
	for (int j = 1; j <= i/2; j++) {
		subBranche[j-1] = opt(i-j) + opt(j);
	}
	return max(subBranche,a);

}

int Solution::max(vector<int>s,int a)
{
	int temp = a;
	for (int i = 0; i < s.size(); i++) {
		if (temp < s[i])temp = s[i];
	}
	return temp;
}

vector<int> Solution::Merge(vector<int> a, vector<int> b)
{
	vector<int>ret;
	ret = a;
	for (int i = 0; i < b.size(); i++) {
		ret.push_back(a[i]);
	
	}
	return ret;
}
