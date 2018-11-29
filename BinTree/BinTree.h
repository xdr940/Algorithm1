#pragma once


 struct BinNode{
	 char data;
	 BinNode* lchild=nullptr, *rchild=nullptr;
};
class BinTree
{
public:
	BinTree();
	~BinTree();
	void Push(char c);
	char Back();
	void PreOrder();
	void InOrder()const;
	void LevelOrder();
	
	BinNode*getRoot() { return this->root; }
private:
	void set(BinNode  *& t,char c);//ע�����������������Ҫ��t����ռ䣨��ֵ�������Լ�����
	void visit(BinNode*t)const;


	void preorder(BinNode  *& t)const;
	void inorder(BinNode*t)const;
	void levelorder(BinNode*t)const;
	BinNode* root;
	int num=0;
	
};

