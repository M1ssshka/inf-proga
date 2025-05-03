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

int heightTree(tree *tr)
{
    if (tr)
    {
        return max(heightTree(tr->left), heightTree(tr->right)) + 1;
    }
    else
    {
        return 0;
    }
}

tree *find(tree *tr, int x)
{
    if (!tr || x == tr->inf)
        return tr;
    if (x < tr->inf)
        return find(tr->left, x);
    else
        return find(tr->right, x);
}

tree *Max(tree *tr)
{
    if (!tr->right)
        return tr;
    else
        return Max(tr->right);
}

tree *Min(tree *tr)
{
    if (!tr->left)
        return tr;
    else
        return Min(tr->left);
}

tree *Next(tree *tr, int x)
{
    tree *n = find(tr, x);
    if (n->right)
        return Min(n->right);
    tree *y = n->parent;
    while (y && n == y->right)
    {
        n = y;
        y = y->parent;
    }
    return y;
}

void del(tree *&tr, tree *v)
{
    tree *p = v->parent;
    if (!p && !tr->right && !tr->left)
        tr = NULL;
    else if (!v->left && !v->right)
    {
        if (p->left == v)
            p->left = NULL;
        if (p->right == v)
            p->right = NULL;
        delete v;
    }
    else if (!v->left || !v->right)
    {
        if (!p)
        {
            if (!v->left)
            {
                v->right->parent = NULL;
                tr = v->right;
            }
            else
            {
                v->left->parent = NULL;
                tr = v->left;
            }
        }
        else
        {
            if (!v->left)
            {
                if (p->left == v)
                    p->left = v->right;
                else
                    p->right = v->right;
                v->right->parent = p;
            }
            else
            {
                if (p->left == v)
                    p->left = v->left;
                else
                    p->right = v->left;
                v->left->parent = p;
            }
        }
        delete v;
    }
    else
    {
        tree *succ = Next(tr, v->inf);
        v->inf = succ->inf;
        if (succ->parent->left == succ)
        {
            succ->parent->left = succ->right;
            if (succ->right)
                succ->right->parent = succ->parent;
        }
        else
        {
            succ->parent->right = succ->right;
            if (succ->right)
                succ->right->parent = succ->parent;
        }
        delete succ;
    }
}

void print_tree(tree *tr, int k)
{
    int n = k;
    for (int i = 0; i < (int)pow(2.0, n + 1) - 1; i++)
        cout << '*';
    cout << '\n';
    if (!tr)
        cout << "tree is empty" << endl;
    else
    {
        queue<tree *> cur, next;
        tree *r = tr;
        cur.push(r);
        int j = 0;
        while (cur.size())
        {
            if (j == 0)
            {
                for (int i = 0; i < (int)pow(2.0, k) - 1; i++)
                    cout << ' ';
            }
            tree *buf = cur.front();
            cur.pop();
            j++;
            if (buf)
            {
                cout << buf->inf;
                next.push(buf->left);
                next.push(buf->right);
                for (int i = 0; i < (int)pow(2.0, k + 1) - 1; i++)
                    cout << ' ';
            }

            if (!buf)
            {
                for (int i = 0; i < (int)pow(2.0, k + 1) - 1; i++)
                    cout << ' ';
                cout << ' ';
            }

            if (cur.empty())
            {
                cout << endl;
                swap(cur, next);
                j = 0;
                k--;
            }
        }
    }
    for (int i = 0; i < (int)pow(2.0, n + 1) - 1; i++)
        cout << '*';
    cout << '\n';
}

tree *removeOddNodes(tree *tr, tree *&tree)
{
    if (tr->left) removeOddNodes(tr->left, tree);
    if (tr->right) removeOddNodes(tr->right, tree);
    if ((tr->inf) % 2) del(tree, tr);
    return tree;
}

int main()
{
}