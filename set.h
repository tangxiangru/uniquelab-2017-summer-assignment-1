#include <iostream>
using namespace std;

static bool RED = false;
static bool BLACK = true;
using T = double;
using RBTColor = bool;

class RBTNode{
    public:
        bool color;    
        T key;           
        RBTNode *left;    
        RBTNode *right;   
        RBTNode *parent; 

        RBTNode(T _key, bool _color, RBTNode* _parent, RBTNode *_left, RBTNode *_right):
            key(_key),color(_color),parent(_parent),left(_left),right(_right) {}
		RBTNode(): color(RED), left(NULL), right(NULL), parent(NULL){}
};

class RBTree {
    private:
        RBTNode* mRoot;    
        int treeNode;
    public:
        RBTree();
        ~RBTree();

        int size(){return treeNode;}
        bool empty(){return mRoot == NULL;}
        RBTNode* search(T key);
        T minimum();
        T maximum();
        void insert(T key);
        void remove(T key);
        void destroy();
    private:
        RBTNode* search(RBTNode* x, T key) const;
        RBTNode* minimum(RBTNode* tree);
        RBTNode* maximum(RBTNode* tree);

        
        void leftRotate(RBTNode* &root, RBTNode* x);
        void rightRotate(RBTNode* &root, RBTNode* y);
        void insert(RBTNode* &root, RBTNode* node);
        void insertFixUp(RBTNode* &root, RBTNode* node);
        void remove(RBTNode* &root, RBTNode *node);
        void removeFixUp(RBTNode* &root, RBTNode *node, RBTNode *parent);
        void destroy(RBTNode* &tree);

        RBTNode* rb_parent(RBTNode* node){return node->parent;}
        bool rb_color(RBTNode* node){return node->color;}
        bool rb_is_red(RBTNode* node){return node->color == RED;}
        bool rb_is_black(RBTNode* node){return node->color == BLACK;}
        void rb_set_black(RBTNode* node){node->color = BLACK;}
        void rb_set_red(RBTNode* node){node->color = RED;}
        void rb_set_parent(RBTNode* node, RBTNode* p){node->parent = p;}
        void rb_set_color(RBTNode* node, RBTColor c){node->color = c;}
};


class Set
{
public:
    void insert(const T&);
    void erase(const T&);
    void clear();
    void deleteMin();
    void deleteMax();
    T findMin();
    T findMax();
    int count(const T&);
    bool empty();
    bool contain(const T&);
    int size();
private:
    RBTree tree;
};




