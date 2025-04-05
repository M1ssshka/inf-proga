#include <iostream>
#include <string>
using namespace std;

struct stack{
    int inf;
    stack *next;
};

void push(stack *&h, int x) {
    stack *r = new stack;
    r->inf = x;
    r->next = h;
    h = r;
}

int pop(stack *&h) {
    int i = h->inf;
    stack *r = h;
    h = h->next;
    delete r;
    return i;
}

int main() {
    stack *h = NULL;
    string str;
    getline(cin, str);
}

