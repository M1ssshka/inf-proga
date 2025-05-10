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

void insert_case1(tree *&tr, tree *x);
void insert_case2(tree *&tr, tree *x);
void insert_case3(tree *&tr, tree *x);
void insert_case4(tree *&tr, tree *x);
void insert_case5(tree *&tr, tree *x);

void insert_case5(tree *&tr, tree *x) {
    tree *g = grandparent(x);
    x->parent->clr = 'b';
    g->clr = 'r';
    if (x == x->parent->left && x->parent == g->left)
        right_rotate(tr, g);
    else
        left_rotate(tr, g);
}

void insert_case4(tree *&tr, tree *x) {
    tree *g = grandparent(x);
    if (!g) return;
    if (x == x->parent->right && x->parent == g->left) {
        left_rotate(tr, x);
        x = x->left;
    }
    else
        if (x == x->parent->left && x->parent == g->right) {
            right_rotate(tr, x->parent);
            x = x->right;
        }
    insert_case5(tr, x);
}


void insert_case3(tree *&tr, tree *x) {
    tree *u = uncle(x);
    tree *g = grandparent(x);
    if (u && u->clr == 'r' && x->parent->clr == 'r') {
        x->parent->clr = 'b';
        u->clr = 'b';
        g->clr = 'r';
        insert_case1(tr, g);
    }
    else insert_case4(tr, x);
}

void insert_case2(tree *&tr, tree *x) {
    if (x->parent->clr == 'r')
        insert_case3(tr, x);
    else
        return;
}

void insert_case1(tree *&tr, tree *x) {
    if (!x->parent)
        x->clr = 'b';
    else
        insert_case2(tr, x);
}

void insert(tree *&tr, tree *prev, int x) {
    if (x < prev->inf && !prev->left) {
        prev->left = node(prev, x);
        insert_case1(tr, prev->left);
    }
    else {
        if (x > prev->inf && !prev->right) {
            prev->right = node(prev, x);
            insert_case1(tr, prev->right);
        }
        else {
            if (x < prev->inf && prev->left)
                insert(tr, prev->left, x);
            else
                if (x > prev->inf && prev->right)
                    insert(tr, prev->right, x);
        }
    }
}

void inorder(tree *tr)
{
    if (tr) {
        inorder(tr->left);
        cout << tr->inf << ' ';
        inorder(tr->right);
    }
}

void delete_case1(tree *&tr, tree *x);
void delete_case2(tree *&tr, tree *x);
void delete_case3(tree *&tr, tree *x);
void delete_case4(tree *&tr, tree *x);
void delete_case5(tree *&tr, tree *x);
void delete_case6(tree *&tr, tree *x);

void delete_case1(tree *&tr, tree *x) {
    if (!x->parent) {
        if (x->left)
            tr = x->left;
        else
            tr = x->right;
    }
    else
        delete_case2(tr, x);
}

void delete_case2(tree *&tr, tree *x) {
    tree *s = sibling(x);
    if (s && s->clr == 'r') {
        x->parent->clr = 'r';
        s->clr = 'b';
        if (x == x->parent->left) {
            x->parent->left = nullptr;
            left_rotate(tr, x->parent);
        }
        else {
            x->parent->right = nullptr;
            right_rotate(tr, x->parent);
        }
    }
    delete_case3(tr, x);
}

void delete_case3(tree *&tr, tree *x) {
    tree *s = sibling(x);
    if (x->parent->clr == 'b' && s->clr == 'b' && (!s->left || s->left->clr == 'b') &&
        (!s->right || s->right->clr == 'b')) {
        s->clr = 'r';
        delete_case1(tr, x);
    }
    else
        delete_case4(tr, x);
}

void delete_case4(tree *&tr, tree *x) {
    tree *s = sibling(x);
    if (s && x->parent->clr == 'r' && s->clr == 'b' && (!s->left || s->left->clr == 'b') &&
        (!s->right || s->right->clr == 'b')) {
        s->clr = 'r';
        x->parent->clr = 'b';
    }
    else
        delete_case5(tr, x);
}

void delete_case5(tree *&tr, tree *x) {
    tree *s = sibling(x);
    if (s && s->clr == 'b') {
        if (x == x->parent->left && (s->left && s->left->clr == 'r') &&
        (!s->right || s->right->clr == 'b')) {
            s->clr = 'r';
            s->left->clr = 'b';
            right_rotate(tr, s);
        }
        else
            if (x == x->parent->right && (s->right && s->right->clr == 'r') &&
        (!s->left || s->left->clr == 'b')) {
                s->clr = 'r';
                s->right->clr = 'b';
                left_rotate(tr, s);
            }
    }
    delete_case6(tr, x);
}

void delete_case6(tree *&tr, tree *x) {
    tree *s = sibling(x);
    if (s) {
        s->clr = x->parent->clr;
        x->parent->clr = 'b';
        if (x == x->parent->left) {
            s->right->clr = 'b';
            x->parent->left = nullptr;
            left_rotate(tr, x->parent);
        }
        else {
            s->left->clr = 'b';
            x->parent->right = nullptr;
            right_rotate(tr, x->parent);
        }
    }
}

void replace(tree *&tr, tree *x) {
    if (x->left) {
        tree *ch = x->left;
        ch->parent = x->parent;
        if (x->parent) {
            if (x == x->parent->left)
                x->parent->left = ch;
            else
                x->parent->right = ch;
        }
        else
            tr = ch;
    }
    else {
        tree *ch = x->right;
        ch->parent = x->parent;
        if (x->parent) {
            if (x == x->parent->left)
                x->parent->left = ch;
            else
                x->parent->right = ch;
        }
        else
            tr = x;
    }
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

void delete_one(tree *&tr, tree *x) {
    if (x->right && x->left) {
        tree *buf;
        if (x->inf <= tr->inf)
            buf = Max(x->left);
        else
            buf = Min(x->right);
        x->inf = buf->inf;
        x = buf;
    }
    if (x->left || x->right) {
        tree *ch;
        if (x->left && !x->right)
            ch = x->left;
        if (!x->left && x->right)
            ch = x->right;
        replace(tr, x);
        if (x->clr == 'b') {
            if (ch->clr == 'r')
                ch->clr = 'b';
            else
                delete_case1(tr, x);
        }
    }
    else {
        if (x->clr == 'b') {
            delete_case1(tr, x);
        }
        else {
            if (x == x->parent->left)
                x->parent->left = nullptr;
            else
                x->parent->right = nullptr;
        }
    }
    delete x;
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

int sumLeaves(tree *&tr) {
    if (tr) {
        if (!tr->left && !tr->right) {
            return tr->inf;
        }
        return sumLeaves(tr->left) + sumLeaves(tr->right);
    }
    return 0;
}

int main() {

}