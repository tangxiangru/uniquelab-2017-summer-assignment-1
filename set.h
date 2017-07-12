#ifndef MYSET
#define MYSET
#include <iostream>
#include <algorithm>
using T = double;
using std::cout;
using std::endl;
enum RBTColor {BLACK, RED};
class TNode {
    public:
        bool color;
        T key;
        TNode* p;
        TNode* left;
        TNode* right;
    //构造函数
        TNode(RBTColor c, T value, TNode *l, TNode *r) :
        color(c), key(value), left(l), right(r) {};
        //TNode();
      //  TNode(const Type& key);
      //  int compare(const Type& t);
};


class RBTree{
public:
	TNode* root;
	TNode* nil;
public:
	RBTree();
	~RBTree();
	//TNode* rb_search(const Type& key);
	//void rb_insert(TNode<Type>* tnode);
	TNode* rb_delete(TNode* tnode);
	//void inorder(TNode* node,Type a[]);
private:
	TNode* min(TNode* x);
	TNode* max(TNode* x);
	TNode* successor(TNode* x);
	void left_rotate(TNode* x);
	void right_rotate(TNode* x);
	void rb_insert_fixup(TNode* z);
	void rb_delete_fixup(TNode* z);
	void freeTree(TNode* node);
};
#endif


class Set {
public:
  void insert(const T& element);
  void erase(const T& element);
  void clear();
  int count(const T& element) const;
  bool empty();
  size_t size();
  ~Set() {delete root;}
private:
    TNode* root;
    int c_size = 0;
    TNode* ins(TNode* tree, T key);
    TNode* del(TNode* tree, T key);
    void clear(TNode* tree);
    TNode* find(TNode* tree, T key) const;
    bool isred(TNode* node);
    TNode* findMin(TNode* tree);
    TNode* left(TNode* node);
    TNode* right(TNode* node);
    TNode* flip(TNode* node);
    TNode* fix_up(TNode* node);
    TNode* moveleft(TNode* tree);
    TNode* moveright(TNode* tree);
    TNode* deleteMin(TNode* tree);
};
