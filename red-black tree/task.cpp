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

int main() {
    
}