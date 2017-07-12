#include <stdio.h>
#include <string>
using namespace std;


static const bool RED=true;
static const bool BLACK=false;
//tree node
template <typename Type>
class TNode{
public:
    TNode* p;//parent
    TNode* left;// left son
    TNode* right;//right son
    Type key;
    bool color;
public:
    TNode();
    //~TNode();
    TNode(const Type& key);
    int compare(const Type& t);
};

template <typename Type>
TNode<Type>::TNode(){
    p=left=right=NULL;
}
template <typename Type>
TNode<Type>::TNode(const Type& key){
    this->key=key;
    p=left=right=NULL;
}

template <typename Type>
int TNode<Type>::compare(const Type& t){
    //return key>t?1:(key=t?0:-1);
    if(key>t)
        return 1;
    if(key<t)
        return -1;
    return 0;
}

// tree
template <typename Type>
class RBTree{
public:
    TNode<Type>* root;
    TNode<Type>* nil;
public:
    RBTree();
    ~RBTree();
    TNode<Type>* rb_search(const Type& key);
    void rb_insert(TNode<Type>* tnode);
    TNode<Type>* rb_delete(TNode<Type>* tnode);
    void inorder(TNode<Type>* node,Type a[]);
private:
    TNode<Type>* min(TNode<Type>* x);
    TNode<Type>* max(TNode<Type>* x);
    TNode<Type>* successor(TNode<Type>* x);
    void left_rotate(TNode<Type>* x);
    void right_rotate(TNode<Type>* x);
    void rb_insert_fixup(TNode<Type>* z);
    void rb_delete_fixup(TNode<Type>* z);
    void freeTree(TNode<Type>* node);
};
template <typename Type>
RBTree<Type>::RBTree(){
    root=nil=new TNode<Type>();
    nil->color=BLACK;
    //root=nil;
}
template <typename Type>
RBTree<Type>::~RBTree(){
    freeTree(root);
    if(nil!=NULL){
        delete nil;
        nil=NULL;
    }
}
template <typename Type>
TNode<Type>* RBTree<Type>::min(TNode<Type>* x){
    while(x->left!=nil){
        x=x->left;
    }
    return x;
}
template <typename Type>
TNode<Type>* RBTree<Type>::max(TNode<Type>* x){
    while(x->right!=nil){
        x=x->right;
    }
    return x;
}
template <typename Type>
TNode<Type>* RBTree<Type>::successor(TNode<Type>* x){
    if(x->right!=nil){
        return min(x);
    }
    TNode<Type>* y=x->p;
    while(y!=nil && x==y->right){
        x=y;
        y=y->p;
    }
    return y;
}
template <typename Type>
TNode<Type>* RBTree<Type>::rb_search(const Type& key){
    TNode<Type>* p=root;
    while(p!=nil){
        int result=p->compare(key);
        if(result==0){
            return p;
        }else if(result==1){
            p=p->left;
        }else{
            p=p->right;
        }
    }
    return p;
}
template <typename Type>
void RBTree<Type>::rb_insert(TNode<Type>* tnode){
    TNode<Type>* x=root;
    TNode<Type>* y=nil;
    while(x!=nil){
        y=x;
        if(x->compare(tnode->key)==1){
            x=x->left;
        }else{
            x=x->right;
        }
    }
    tnode->p=y;
    if(y==nil){
        root=tnode;
    }else if(y->compare(tnode->key)==1){
        y->left=tnode;
    }else{
        y->right=tnode;
    }
    tnode->left=nil;
    tnode->right=nil;
    tnode->color=RED;
    rb_insert_fixup(tnode);
}
template <typename Type>
void RBTree<Type>::left_rotate(TNode<Type>* x){
    TNode<Type>* y=x->right;
    x->right=y->left;
    if(y->left!=nil){
        y->left->p=x;
    }
    y->p=x->p;
    if(x->p==nil){
        root=y;
    }else{
        if(x->p->left==x){
            x->p->left=y;
        }else{
            x->p->right=y;
        }
    }
    y->left=x;
    x->p=y;
}
template <typename Type>
void RBTree<Type>::right_rotate(TNode<Type>* x){
    TNode<Type>* y=x->left;
    x->left=y->right;
    if(y->right!=nil){
        y->right->p=x;
    }
    y->p=x->p;
    if(y->p==nil){
        root=y;
    }else{
        if(x->p->left=x){
            x->p->left=y;
        }else{
            x->p->right=y;
        }
    }
    y->right=x;
    x->p=y;
}
template <typename Type>
void RBTree<Type>::rb_insert_fixup(TNode<Type>* z){
    while(z->p->color==RED){
        if(z->p==z->p->p->left){
            TNode<Type>* y=z->p->p->right;
            if(y->color==RED){//z的叔叔是红色
                z->p->color=BLACK;
                z->p->p->color=RED;
                y->color=BLACK;
                z=z->p->p;
            }else if(z==z->p->right){//z的叔叔是黑色，z是右孩子
                z=z->p;
                left_rotate(z);
            }else{//z的叔叔是黑色，z是左孩子
                z->p->color=BLACK;
                z->p->p->color=RED;
                right_rotate(z->p->p);
            }
        }else{
            TNode<Type>* y=z->p->p->left;
            if(y->color==RED){
                z->p->color=BLACK;
                z->p->p->color=RED;
                y->color=BLACK;
                z=z->p->p;
            }else if(z==z->p->left){
                z=z->p;
                right_rotate(z);
            }else{
                z->p->color=BLACK;
                z->p->p->color=RED;
                left_rotate(z->p->p);
            }
        }
    }
    root->color=BLACK;
}

template <typename Type>
TNode<Type>* RBTree<Type>::rb_delete(TNode<Type>* tnode){
    TNode<Type>* y;
    if(tnode->left==nil || tnode->right==nil){
        y=tnode;
    }else{
        y=successor(tnode);
    }
    TNode<Type>* x;
    if(y->left!=nil){
        x=y->left;
    }else{
        x=y->right;
    }
    x->p=y->p;
    if(y->p==nil){
        root=x;
    }else{
        if(y->p->left==y){
            y->p->left=x;
        }else{
            y->p->right=x;
        }
    }
    if(y!=tnode){
        tnode->key=y->key;
    }
    if(y->color==BLACK){
        rb_delete_fixup(x);
    }
    
    return y;
}

template <typename Type>
void RBTree<Type>::rb_delete_fixup(TNode<Type>* z){
    //z的兄弟
    TNode<Type>* w;
    while(z!=root && z->color==BLACK){
        if(z==z->p->left){
            w=z->p->right;
            if(w->color==RED){//z的兄弟w是红色
                w->color=BLACK;
                z->p->color=RED;
                left_rotate(z->p);
                w=z->p->right;
            }
            if(w->left->color==BLACK && w->right->color==BLACK){//z的兄弟w是黑色，w的两个孩子都是黑色
                w->color=RED;
                z=z->p;
            }else if(w->right->color==BLACK){//z的兄弟w是黑色，w的左孩子是红色，右孩子是黑色
                w->left->color=BLACK;
                w->color=RED;
                right_rotate(w);
                w=z->p->right;
            }else{//z的兄弟w是黑色，w的右孩子是红色
                w->color=z->p->color;
                z->p->color=BLACK;
                w->right->color=BLACK;
                left_rotate(z->p);
                z=root;
            }
        }else{
            w=z->p->left;
            if(w->color==RED){
                w->color=BLACK;
                z->p->color=RED;
                right_rotate(z->p);
                w=z->p->left;
            }
            if(w->left->color==BLACK && w->right->color==BLACK){
                w->color=RED;
                z=z->p;
            }else if(w->left->color==BLACK){
                w->right->color=BLACK;
                w->color=RED;
                left_rotate(w);
                w=z->p->left;
            }else{
                w->color=z->p->color;
                z->p->color=BLACK;
                w->left->color=BLACK;
                right_rotate(z->p);
                z=root;
            }
        }
    }
    z->color=BLACK;
}

template <typename Type>
void RBTree<Type>::freeTree(TNode<Type>* node){
    if(node==nil){
        return;
    }
    if(node->left!=nil){
        freeTree(node->left);
    }
    if(node->right!=nil){
        freeTree(node->right);
    }
    delete node;
    node=NULL;
}
template <typename Type>
void RBTree<Type>::inorder(TNode<Type>* node,Type a[]){
    static int count=0;
    if(node==nil){
        return;
    }
    inorder(node->left,a);
    a[count++]=node->key;
    inorder(node->right,a);
}
//*************MySet**************************//
template <typename Type>
class MySet{
    RBTree<Type>* tree;
    int count;
public:
    MySet();
    ~MySet();
    bool add(const Type& key);
    bool contains(const Type& key);
    bool remove(const Type& key);
    bool isEmpty();
    int  size();
    void clear();
    Type* toArray(int& i);
};
template <typename Type>
MySet<Type>::MySet(){
    tree=new RBTree<Type>();
    count=0;
}
template <typename Type>
MySet<Type>::~MySet(){
    if(tree!=NULL){
        delete tree;
        tree=NULL;
    }
}
template <typename Type>
bool MySet<Type>::contains(const Type& key){
    TNode<Type>* node=tree->rb_search(key);
    if(node==tree->nil){
        return false;
    }
    return true;
}
template <typename Type>
bool MySet<Type>::add(const Type& key){
    if(contains(key)){
        return false;
    }
    TNode<Type>* node=new TNode<Type>(key);
    tree->rb_insert(node);
    count++;
    return true;
}
template <typename Type>
bool MySet<Type>::remove(const Type& key){
    TNode<Type>* node=tree->rb_search(key);
    if(node==tree->nil){
        return false;
    }
    TNode<Type>* result=tree->rb_delete(node);
    delete result;
    count--;
    return true;
}
template <typename Type>
bool MySet<Type>::isEmpty(){
    return count==0?true:false;
}
template <typename Type>
int MySet<Type>::size(){
    return count;
}
template <typename Type>
void MySet<Type>::clear(){
    if(tree!=NULL){
        delete tree;
        tree=NULL;
    }
    tree=new RBTree<Type>();
    count=0;
}
template <typename Type>
Type* MySet<Type>::toArray(int& i){
    Type* a=new Type[count];
    tree->inorder(tree->root,a);
    i=count;
    return a;
}

#if 0
void main(){
    MySet<int>* set=new MySet<int>();
    for(int i=1000;i>0;i--){
        set->add(i);
    }
    printf("倒序插入1000个数之后\n");
    int count=0;
    int* a=set->toArray(count);
    printf("遍历较小的十个数:\n");
    for(int i=0;i<10;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
    
    set->remove(1);
    printf("after remove 1.set.size()=%d\n",set->size());
    
    set->clear();
    printf("after clear.set.size()=%d\n",set->size());
    delete set;
    
    getchar();
    
}

#endif
