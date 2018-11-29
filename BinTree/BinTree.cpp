#include "pch.h"
#include "BinTree.h"


BinTree::BinTree()
{

}


BinTree::~BinTree()
{
}

void BinTree::Push(int c)
{
	set(this->root, c);
}



int BinTree::Back()
{
	return 0;
}


void BinTree::PreOrder()
{
	preorder(this->root);
}

void BinTree::InOrder() 
{
	inorder(this->root);
}

void BinTree::preorder(BinNode *& t)  
{
	if (t != nullptr) {
		this->preorder(t->lchild);
		visit(t);
		this->preorder(t->rchild);
	}
}

void BinTree::inorder(BinNode*t)  
{
	if (t != nullptr) {
		visit(t);
		this->inorder(t->lchild);
		
		this->inorder(t->rchild);
	}
	else {
		cout << "# ";
	}
}

void BinTree::levelorder(BinNode * t)  
{
	queue<BinNode*>Q;
	Q.push(t);
	while (!Q.empty()) {
		BinNode*p = Q.front();
		visit(p);
		Q.pop();
		if (p) {
			if (p->lchild != nullptr)Q.push(p->lchild);
			else Q.push(nullptr);
			if (p->rchild != nullptr)Q.push(p->rchild);
			else Q.push(nullptr);

		}
		

	}
}

void BinTree::LevelOrder()
{
	levelorder(this->root);
}


void BinTree::set(BinNode * &t, int c)
{
	if (t == nullptr) {
		t = new BinNode;//这个还是赋值，如果没有引用则赋值出set函数就失效
		t->data = c;
		num++;
	}
	else {
		if (c < t->data)set(t->lchild, c);
		if (c > t->data) set(t->rchild, c);
	}
	return;
}



void BinTree::visit(BinNode * t)
{
	if (t != nullptr) {
		cout << t->data << " ";
		ret.push_back(t->data);
	}
	else {
		cout << "# "; 
		ret.push_back(Nan);
	}


}
/*
void BinTree::zigzag()
{	
	vector<vector<int>>xs;
	vector<int>temp;
	int cnt = 1;
	int flag = 1;//从右往左
	int sumcnt = 0;
	while (cnt) {
		temp.clear();

		for (int j = sumcnt; j < sumcnt + cnt; j++) {
			if (ret[j] != Nan) {
				temp.push_back(ret[j]);
			}

		}

		if (!temp.empty()) {
			if (flag == 1) {
				xs.push_back(temp);
				flag = 2;
			}
			else {
				reverse(temp.begin(), temp.end());
				xs.push_back(temp);
				flag = 1;
			}
		}
		sumcnt += cnt;



		cnt = 0;
		for (int j = 0; j < temp.size(); j++) {
			if (temp[j] != Nan)cnt++;
		}
		cnt *= 2;

	}

	//输出展示
	for (int i = 0; i < xs.size(); i++) {
		for (int j = 0; j < xs[i].size(); j++) {
			cout << xs[i][j] << " ";
		}cout << endl;
	}
}

*/