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

void printLeaves(tree *tr)
{
    if (tr)
    {
        if (!tr->left && !tr->right)
            cout << tr->inf << ' ';
        printLeaves(tr->left);
        printLeaves(tr->right);
    }
}

int main()
{
    int n;
    cin >> n;
    tree *tr1 = NULL;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        insert(tr1, t);
    }
    print_tree(tr1, heightNode(tr1));
    printLeaves(tr1);
    cout << '\n';
}
