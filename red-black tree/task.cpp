#include <iostream>
#include <queue>
using namespace std;

struct tree {
    int inf;
    tree *right;
    tree *left;
    tree *parent;
    char clr;
};

tree *node(tree *p, int x) {
    tree *n = new tree;
    n->clr = 'r';
    n->inf = x;
    n->left = nullptr;
    n->right = nullptr;
    n->parent = p;
    return n;
}

tree *root(int x) {
    tree *n = new tree;
    n->clr = 'b';
    n->inf = x;
    n->left = nullptr;
    n->right = nullptr;
    n->parent = nullptr;
    return n;
}

tree *grandparent(tree *x) {
    if (x && x->parent)
        return x->parent->parent;
    else
        return nullptr;
}

tree *uncle(tree *x) {
    tree *g = grandparent(x);
    if (!g)
        return nullptr;
    if (x->parent == g->left)
        return g->right;
    else
        return g->left;
}

tree *sibling(tree *x) {
    if (x && x->parent) {
        if (x == x->parent->left)
            return x->parent->right;
        else
            return x->parent->left;
    }
    else
        return nullptr;
}

void left_rotate(tree *&tr, tree *x) {
    tree *y = x->right;
    x->right = y->left;
    if (y->left)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent)
        if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
    y->left = x;
    x->parent = y;
    if (!y->parent) {
        y->clr = 'b';
        tr = y;
    }
}

void right_rotate(tree *&tr, tree *x) {
    tree *y = x->left;
    x->left = y->right;
    if (y->right)
        y->right->parent = x;
    y->parent = x->parent;
    if (x->parent)
        if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
    y->right = x;
    x->parent = y;
    if (!y->parent) {
        y->clr = 'b';
        tr = y;
    }
}

int main() {

}