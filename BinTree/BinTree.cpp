#include "pch.h"
#include "BinTree.h"


BinTree::BinTree()
{

}


BinTree::~BinTree()
{
}

void BinTree::Push(char c)
{
	set(this->root, c);
}



char BinTree::Back()
{
	return 0;
}


void BinTree::PreOrder()
{
	preorder(this->root);
}

void BinTree::InOrder()const
{
	inorder(this->root);
}

void BinTree::preorder(BinNode *& t) const
{
	if (t != nullptr) {
		this->preorder(t->lchild);
		visit(t);
		this->preorder(t->rchild);
	}
}

void BinTree::inorder(BinNode*t) const
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

void BinTree::levelorder(BinNode * t) const
{
	queue<BinNode*>Q;
	Q.push(t);
	while (!Q.empty()) {
		BinNode*p = Q.front();
		visit(p);
		Q.pop();
		if (p->lchild != nullptr)Q.push(p->lchild);
		if (p->rchild != nullptr)Q.push(p->rchild);
	}
}

void BinTree::LevelOrder()
{
	levelorder(this->root);
}


void BinTree::set(BinNode * &t, char c)
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



void BinTree::visit(BinNode * t)const
{
	if (t != nullptr) {
		cout << t->data << " ";

	}
	else {
		cout << "# "; 
	}


}

