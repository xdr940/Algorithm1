#pragma once


 struct BinNode{
	 int data;
	 BinNode* lchild=nullptr, *rchild=nullptr;
};
class BinTree
{
public:
	BinTree();
	~BinTree();
	void Push(int c);
	int Back();
	void PreOrder();
	void InOrder() ;
	void LevelOrder();
	void disp() {
		cout << endl;
		for (int i = 0; i < ret.size(); i++) {
			cout << ret[i] << " ";
		}
	}
	//void zigzag();

	BinNode*getRoot() { return this->root; }
private:
	void set(BinNode  *& t,int c);//ע�����������������Ҫ��t����ռ䣨��ֵ�������Լ�����
	void visit(BinNode*t);

	void preorder(BinNode  *& t);
	void inorder(BinNode*t);
	void levelorder(BinNode*t);
	BinNode* root;
	int num=0;
	vector<int>ret;
	
};

