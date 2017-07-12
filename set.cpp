#include "set.h"

void Set::insert(const T& key){
  if (find(root, key) == NULL) {
    c_size++;
    root= ins(root, key);
}
root->color = BLACK;
}

void Set::erase(const T& key) {
    if (find(root, key) != NULL) {
        c_size--;
        root = del(root, key);
        if (root != NULL)
            root->color = BLACK;
    }
}

TNode* Set::del(TNode* tree, T key) {
    if (tree == NULL)
        return NULL;
    /* 向左 */
    if (tree->key > key) {
        if (tree->left != NULL && !isred(tree->left) && !isred(tree->left->left))
            tree = moveleft(tree);
        tree->left = del(tree->left, key);
    }
    else {
        if (isred(tree->left))
            tree =right(tree);
        if (tree->key == key && tree->right == NULL) {
            TNode *t = tree->left;
            delete(tree);
            return t;
        }
        if (tree->right != NULL && !isred(tree->right) && !isred(tree->right->left))
            tree = moveright(tree);

        if (tree->key < key)
            tree->right = del(tree->right, key);
        /* 若相等 */
        else {
            tree->key = findMin(tree->right)->key;
            tree->right = deleteMin(tree->right);
        }

    }
    return tree = fix_up(tree);
}



void Set::clear(){
	if(root!=NULL){
		delete root;
		root=NULL;
	}
	// root=new RBTree();
	c_size=0;
}

void Set::clear(TNode* tree) {
    if (tree == NULL)
        return;
    clear(tree->left);
    clear(tree->right);
    delete(tree);
}


int Set::count(const T& key) const {
    if (find(root, key) != NULL)
        return 1;
    else
        return 0;
}

size_t Set::size(){
	return c_size;
}

bool Set::empty(){
	return c_size==0?true:false;
}

TNode* Set::ins(TNode* tree, T key) {
    if (tree == NULL)
        return new TNode(RED, key, NULL, NULL);
    if (tree->key > key)
        tree->left = ins(tree->left, key);
    else
        tree->right = ins(tree->right, key);
    fix_up(tree);
    return tree;
}



TNode* Set::moveright(TNode* tree) {
    flip(tree);
    if (tree->left != NULL && isred(tree->left->left)) {
        tree = right(tree);
        flip(tree);
    }
    return tree;
}


TNode* Set::deleteMin(TNode* tree)
{
   root = deleteMin(root);
   root->color = BLACK;
}
/*TNode* deleteMax()
{
   root = deleteMax(root);
   root->color = BLACK;
}*/
TNode* Set::moveleft(TNode* tree) {

    flip(tree);
    if (tree->right != NULL && isred(tree->right->left)) {
        tree->right = right(tree->right);
        tree = left(tree);
        flip(tree);
    }
    return tree;
}

TNode* Set::fix_up(TNode* node) {
    if (isred(node->right))
        node = left(node);

    if (node->left != NULL && isred(node->left) && isred(node->left->left))
        node = right(node);
    if (isred(node->left) && isred(node->right))
        flip(node);
    return node;
}
TNode* Set::flip(TNode* k1) {
    k1->color = !k1->color;
    if (k1->left != NULL)
        k1->left->color = !k1->left->color;
    if (k1->right != NULL)
    k1->right->color = !k1->right->color;
    return k1;
}

TNode* Set::right(TNode* k1) {
    TNode *k2 = k1->left;
    k1->left = k2->right;
    k2->right = k1;
    k2->color = k2->right->color;
    k2->right->color = RED;
    return k2;
  }

/*
void rightRoate(rbTreeNode* x){
  rbTreeNode* y=x->left;
  x->left=y->right;     y->parent=x->parent;
  if (x->parent==NULL)
    root=y;
  if (x->left!=NULL)
    x->left->parent=x;
  if (x->parent!=NULL&&x->parent->left==x){
    x->parent->left=y;
  }else if (x->parent!=NULL&&x->parent->right==x){
    x->parent->right=y;
  }
  y->right=x;
  x->parent=y;
}

*/
TNode* Set::left(TNode* k1) {
    TNode *k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k2->color = k2->left->color;
    k2->left->color = RED;
    return k2;}  //返回结构顶点

/*
void leftRoate(rbTreeNode* x){
  rbTreeNode* y=x->right;  y->parent=x->parent;
  if (x->parent==NULL)
    root=y;
  x->right=y->left;
  if (y->left!=NULL)
    y->left->parent=x;
  if (x->parent!=NULL&&x->parent->left==x){
    x->parent->left=y;
  }
  else if (x->parent!=NULL&&x->parent->right==x){
    x->parent->right=y;
  }
  y->left=x;
  x->parent=y;
}
*/

bool Set::isred(TNode* node) {
    if (node == NULL || node->color == BLACK)
        return false;
    else
        return true;
}

TNode* Set::find(TNode* node, T key) const {
    TNode* p = node;
    while (p != NULL) {
        if (p->key > key)
            p = p->left;
        else if (p->key < key)
            p = p->right;
        else
            return p;
    }
    return NULL;
}


TNode* Set::findMin(TNode* tree) {
    if (tree->left == NULL)
        return tree;
    else
        return findMin(tree->left);
}
