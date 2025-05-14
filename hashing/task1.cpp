#include <fstream>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

struct date {
    int day;
    int month;
    int year;
};

struct worker {
    string post;
    string surname;
    date date_of_birthday;
    int experience;
    int pay;
};

struct list {
    worker inf;
    list *prev;
    list *next;
};

struct List {
    list *h;
    list *t;
};

void push(list *&h, list *&t, worker x) {
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

void print_worker(worker human) {
    string i = human.date_of_birthday.day / 10 == 0 ? "0" : "";
    string i1 = human.date_of_birthday.month / 10 == 0 ? "0" : "";
    cout << human.surname << ", " << i << human.date_of_birthday.day << "." << i1 << human.date_of_birthday.month << "."
        << human.date_of_birthday.year << ", " << human.experience << ", " << human.post << ", " << human.pay << endl;
}

void print(list *&h, list *&t) {
    list *p = h;
    while(p) {
        print_worker(p->inf);
        p = p->next;
    }
    cout << '\n';
}

vector<list*> find(list *&h, list *&t, int x) {
    vector<list*> ans;
    list *p = h;
    while(p) {
        if (p->inf.date_of_birthday.year == x) ans.push_back(p);
        p = p->next;
    }
    return ans;
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