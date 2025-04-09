#include <iostream>
using namespace std;

struct list {
    int inf;
    list *prev;
    list *next;
};

void push(list *&h, list *&t, int x) {
    list *r = new list;
    r->inf = x;
    r->next = nullptr;
    if (!h && !t) {
        r->prev = nullptr;
        h = r;
    }
    else {
        t->next = r;
        r->prev = t;
    }
    t = r;
}

void print(list *&h, list *&t) {
    list *p = h;
    while(p) {
        cout << p->inf << " ";
        p = p->next;
    }
    cout << '\n';
}

list *find(list *&h, list *&t, int x) {
    list *p = h;
    while(p) {
        if (p->inf == x) break;
        p = p->next;
    }
    return p;
}

void insert_after(list *&h, list *&t, list *&r, int x) {
    list *p = new list;
    p->inf = x;
    if (r == t) {
        p->next = nullptr;
        p->prev = r;
        r->next = p;
        t = p;
    }
    else {
        r->next->prev = p;
        p->next = r->next;
        p->prev = r;
        r->next = p;
    }
}

void del_node(list *&h, list *&t, list *&r) {
    if (r == h && r == t) {
        h = t = nullptr;
    }
    else if (r == h) {
        h = h->next;
        h->prev = nullptr;
    }
    else if (r == t) {
        t = t->prev;
        t->next = nullptr;
    }
    else {
        r->next->prev = r->prev;
        r->prev->next = r->next;
    }
    delete r;
}

void del_list(list *&h, list *&t) {
    while(h) {
        list *p = h;
        h = h->next;
        h->prev = nullptr;
        delete p;
    }
}

void res(list *&h, list *&t, int n) {
    list *temp = h;
    int i = 0;
    while(i < n) {
        if (temp->inf % 2 == 0) {
            insert_after(h, t, t, temp->inf);
            del_node(h, t, temp);
        }
        temp = temp->next;
        i++;
    }
    print(h, t);
}

int main() {
    list *h = nullptr;
    list *t = nullptr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        push(h, t, temp);
    }
    res(h, t, n);
}
