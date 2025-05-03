#include <iostream>
#include <queue>
#include <math.h>
#include <vector>
using namespace std;

struct tree
{
    int inf;
    tree *right;
    tree *left;
    tree *parent;
};

tree *node(int x)
{
    tree *n = new tree;
    n->inf = x;
    n->left = n->right = NULL;
    n->parent = NULL;
    return n;
}

int main()
{
}