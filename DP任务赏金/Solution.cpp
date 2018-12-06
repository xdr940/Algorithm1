#include "pch.h"
#include "Solution.h"

using namespace std;


Solution::Solution( )
{
	
}


void Solution::DC_rec()//���η�
{	//��������
	tasks.clear();
	this->n = 8;
	tasks.resize(n + 1);
	tasks[0] = { 0,0,0 };
	tasks[1] = { 1,4,5 };
	tasks[2] = { 3,5,1 };
	tasks[3] = { 0,6,8 };
	tasks[4] = { 4,7,4 };
	tasks[5] = { 3,8,6 };
	tasks[6] = { 5,9,3 };
	tasks[7] = { 6,10,2 };
	tasks[8] = { 8,11,4 };
	//��ʼ��prev
	prev.clear();
	prev.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = i; j >= 0; j--) {
			if (tasks[j].ed <= tasks[i].st) {
				prev[i] = j;
				break;
			}
		}
	}
	//opt���õݹ麯��ʵ��
	cout << opt(n) << endl;
}

void Solution::DP()
{
	//��������
	tasks.clear();
	this->n = 8;
	tasks.resize(n + 1);
	tasks[0] = { 0,0,0 };
	tasks[1] = { 1,4,5 };
	tasks[2] = { 3,5,1 };
	tasks[3] = { 0,6,8 };
	tasks[4] = { 4,7,4 };
	tasks[5] = { 3,8,6 };
	tasks[6] = { 5,9,3 };
	tasks[7] = { 6,10,2 };
	tasks[8] = { 8,11,4 };
	//��ʼ��prev
	prev.clear();
	prev.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = i; j >= 0; j--) {
			if (tasks[j].ed <= tasks[i].st) {
				prev[i] = j;
				break;
			}
		}
	}
	//opt���÷ǵݹ����飬���仯����ʵ��
	OPT_array.clear();
	xs.clear();

	OPT_array.resize(n + 1);
	xs.resize(n + 1);
	
	OPT_array[0] = 0;
	OPT_array[1] = 5;//�Ȱ�ͷд��,�߽����
	xs[0] = {};
	xs[1] = { 1 };

	for (int i = 1; i <= n; i++) {
		//����д�Լ�¼����ֵ�ȽϷ��㣬�������Žⲻ��Ū	
		//OPT_array[i] = max(OPT_array[i - 1], OPT_array[prev[i]] + tasks[i].cost);
		int temp1 = OPT_array[i - 1];
		int temp2 = OPT_array[prev[i]] + tasks[i].cost;
		if (temp1 > temp2) {
			OPT_array[i] = temp1;//����ֵ��¼
			xs[i] = xs[i - 1];//���Ž��¼
		}
		else {
			OPT_array[i] = temp2;
			xs[i] = xs[prev[i]];//xs[i] = xs[prev[i]]+i
			xs[i].push_back(i);//���Ž��¼
		}
	
	}
	//������Ž�
	for (int i = 1; i <= n; i++) {
		cout << OPT_array[i] << " ";
	}
	cout << endl;
	//�������ֵ
	for (int i = 0; i < xs.size(); i++) {
		for (int j = 0; j < xs[i].size(); j++) {
			cout << xs[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

Solution::~Solution()
{
}

int Solution::max(int i, int j)
{
	if (i > j)return i;
	else return j;
}

int Solution::opt(int i)
{//��������Դ�����·����Ϣ
	if (i <= 0)return 0;
	if (i == 1)return tasks[i].cost;
	int temp = max(opt(i - 1), tasks[i].cost + opt(prev[i]));
	return temp;
}
