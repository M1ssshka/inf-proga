#include <iostream>
#include <queue>
#include <math.h>
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

void insert(tree *&tr, int x)
{
    tree *n = node(x);
    if (!tr)
        tr = n;
    else
    {
        tree *y = tr;
        while (y)
        {
            if (n->inf > y->inf)
            {
                if (y->right)
                {
                    y = y->right;
                }
                else
                {
                    n->parent = y;
                    y->right = n;
                    break;
                }
            }
            else if (n->inf < y->inf)
            {
                if (y->left)
                {
                    y = y->left;
                }
                else
                {
                    n->parent = y;
                    y->left = n;
                    break;
                }
            }
        }
    }
}
tree *find(tree *tr, int x) {
    if (!tr || x == tr->inf) 
        return tr;
    if (x < tr->inf) 
        return find(tr->left, x);
    else 
        return find(tr->right, x);
}

int heightNode(tree *tr)
{
    if (tr)
    {
        return max(heightNode(tr->left), heightNode(tr->right)) + 1;
    }
    else
    {
        return 0;
    }
}

int main() {

}