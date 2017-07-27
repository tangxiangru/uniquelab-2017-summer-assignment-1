#include "set.h"

void Set::insert(const T& key)
{
	tree.insert(key);
}

void Set::erase(const T& key)
{
	tree.remove(key);
}

void Set::clear()
{
    tree.destroy();
}

void Set::deleteMin()
{
    tree.remove(tree.minimum());
}

void Set::deleteMax()
{
    tree.remove(tree.maximum());
}

T Set::findMin()
{
    return tree.minimum();
}

T Set::findMax()
{
    return tree.maximum();
}

int Set::count(const T& key)
{
    if(tree.search(key) == NULL)
        return 0;
    return 1;
}

bool Set::empty()
{
    return tree.empty();
}

bool Set::contain(const T& val)
{
    return tree.search(val) != NULL;
}

int Set::size()
{
    return tree.size();
}





RBTree::RBTree():mRoot(NULL)
{
    treeNode = 0;
    mRoot = NULL;
}

RBTree::~RBTree()
{
    treeNode = 0;
    destroy();
}


RBTNode* RBTree::search(RBTNode* x, T key) const
{
    if (x==NULL || x->key==key)
        return x;

    if (key < x->key)
        return search(x->left, key);
    else
        return search(x->right, key);
}

RBTNode* RBTree::search(T key)
{
    search(mRoot, key);
}

RBTNode* RBTree::minimum(RBTNode* tree)
{
    if (tree == NULL)
        return NULL;

    while(tree->left != NULL)
        tree = tree->left;
    return tree;
}

T RBTree::minimum()
{
    RBTNode *p = minimum(mRoot);
    if (p != NULL)
        return p->key;

    return (T)NULL;
}

RBTNode* RBTree::maximum(RBTNode* tree)
{
    if (tree == NULL)
        return NULL;

    while(tree->right != NULL)
        tree = tree->right;
    return tree;
}

T RBTree::maximum()
{
    RBTNode *p = maximum(mRoot);
    if (p != NULL)
        return p->key;

    return (T)NULL;
}

void RBTree::leftRotate(RBTNode* &root, RBTNode* x)
{
    RBTNode *y = x->right;
    x->right = y->left;
    if (y->left != NULL)
        y->left->parent = x;
    y->parent = x->parent;

    if (x->parent == NULL)
           root = y;            
    else
    {
        if (x->parent->left == x)
            x->parent->left = y;    
        else
            x->parent->right = y;    
	}
    y->left = x;
    x->parent = y;
}

void RBTree::rightRotate(RBTNode* &root, RBTNode* y)
{
    RBTNode *x = y->left;
    y->left = x->right;
    if (x->right != NULL)
        x->right->parent = y;
    x->parent = y->parent;

    if (y->parent == NULL)
        root = x;           
    else
    {
        if (y == y->parent->right)
            y->parent->right = x;  
        else
            y->parent->left = x;  
    }
    x->right = y;
    y->parent = x;
}
 
void RBTree::insertFixUp(RBTNode* &root, RBTNode* node)
{
    RBTNode *parent, *gparent;
    while ((parent = rb_parent(node)) && rb_is_red(parent))
    {
        gparent = rb_parent(parent);
        if (parent == gparent->left)
        {
          	{
                RBTNode *uncle = gparent->right;
                if (uncle && rb_is_red(uncle))
                {
                    rb_set_black(uncle);
                    rb_set_black(parent);
                    rb_set_red(gparent);
                    node = gparent;
                    continue;
                }
            }
            if (parent->right == node)
            {
                RBTNode *tmp;
                leftRotate(root, parent);
                tmp = parent;
                parent = node;
                node = tmp;
            }
            rb_set_black(parent);
            rb_set_red(gparent);
            rightRotate(root, gparent);
        }
        else
        {
            {
                RBTNode *uncle = gparent->left;
                if (uncle && rb_is_red(uncle))
                {
                    rb_set_black(uncle);
                    rb_set_black(parent);
                    rb_set_red(gparent);
                    node = gparent;
                    continue;
                }
            }
            if (parent->left == node)
            {
                RBTNode *tmp;
                rightRotate(root, parent);
                tmp = parent;
                parent = node;
                node = tmp;
            }
            rb_set_black(parent);
            rb_set_red(gparent);
            leftRotate(root, gparent);
        }
    }
    rb_set_black(root);
}


void RBTree::insert(RBTNode* &root, RBTNode* node)
{
    RBTNode *y = NULL;
    RBTNode *x = root;
    while (x != NULL)
    {
        y = x;
        if (node->key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    node->parent = y;
    if (y!=NULL)
    {
        if (node->key < y->key)
            y->left = node;
        else
            y->right = node;
    }
    else
        root = node;
    node->color = RED;
    insertFixUp(root, node);
}

void RBTree::insert(T key)
{
    RBTNode *z=NULL;

    if ((z=new RBTNode(key,BLACK,NULL,NULL,NULL)) == NULL)
        return ;

    if(search(mRoot, key) == NULL)
	{
	    ++treeNode;
    	insert(mRoot, z);
    }
}

void RBTree::removeFixUp(RBTNode* &root, RBTNode *node, RBTNode *parent)
{
    RBTNode *other;

    while ((!node || rb_is_black(node)) && node != root)
    {
        if (parent->left == node)
        {
            other = parent->right;
            if (rb_is_red(other))
            {
                rb_set_black(other);
                rb_set_red(parent);
                leftRotate(root, parent);
                other = parent->right;
            }
            if ((!other->left || rb_is_black(other->left)) &&
                (!other->right || rb_is_black(other->right)))
            {
                rb_set_red(other);
                node = parent;
                parent = rb_parent(node);
            }
            else
            {
                if (!other->right || rb_is_black(other->right))
                {
                    rb_set_black(other->left);
                    rb_set_red(other);
                    rightRotate(root, other);
                    other = parent->right;
                }
                rb_set_color(other, rb_color(parent));
                rb_set_black(parent);
                rb_set_black(other->right);
                leftRotate(root, parent);
                node = root;
                break;
            }
        }
        else
        {
            other = parent->left;
            if (rb_is_red(other))
            {
                rb_set_black(other);
                rb_set_red(parent);
                rightRotate(root, parent);
                other = parent->left;
            }
            if ((!other->left || rb_is_black(other->left)) &&
                (!other->right || rb_is_black(other->right)))
            {
                rb_set_red(other);
                node = parent;
                parent = rb_parent(node);
            }
            else
            {
                if (!other->left || rb_is_black(other->left))
                {
                    rb_set_black(other->right);
                    rb_set_red(other);
                    leftRotate(root, other);
                    other = parent->left;
                }
                rb_set_color(other, rb_color(parent));
                rb_set_black(parent);
                rb_set_black(other->left);
                rightRotate(root, parent);
                node = root;
                break;
            }
        }
    }
    if (node)
        rb_set_black(node);
}

void RBTree::remove(RBTNode* &root, RBTNode *node)
{
    RBTNode *child, *parent;
    RBTColor color;

    if ( (node->left!=NULL) && (node->right!=NULL) )
    {
        RBTNode *replace = node;

        replace = replace->right;
        while (replace->left != NULL)
            replace = replace->left;

        if (rb_parent(node))
        {
            if (rb_parent(node)->left == node)
                rb_parent(node)->left = replace;
            else
                rb_parent(node)->right = replace;
        }
        else
            root = replace;

        child = replace->right;
        parent = rb_parent(replace);
        color = rb_color(replace);

        if (parent == node)
        {
            parent = replace;
        }
        else
        {
            if (child)
                rb_set_parent(child, parent);
            parent->left = child;

            replace->right = node->right;
            rb_set_parent(node->right, replace);
        }

        replace->parent = node->parent;
        replace->color = node->color;
        replace->left = node->left;
        node->left->parent = replace;

        if (color == BLACK)
            removeFixUp(root, child, parent);

        delete node;
        return ;
    }

    if (node->left !=NULL)
        child = node->left;
    else
        child = node->right;

    parent = node->parent;
    color = node->color;
    if (child)
        child->parent = parent;
    if (parent)
    {
        if (parent->left == node)
            parent->left = child;
        else
            parent->right = child;
    }
    else
        root = child;

    if (color == BLACK)
        removeFixUp(root, child, parent);
    delete node;
}

void RBTree::remove(T key)
{
    RBTNode *node;
    if ((node = search(mRoot, key)) != NULL)
    {
        --treeNode;
        remove(mRoot, node);
    }
}
void RBTree::destroy(RBTNode* &tree)
{
    if (tree==NULL)
        return ;

    if (tree->left != NULL)
        return destroy(tree->left);
    if (tree->right != NULL)
        return destroy(tree->right);

    treeNode = 0;
    delete tree;
    tree=NULL;
}

void RBTree::destroy()
{
    destroy(mRoot);
}





