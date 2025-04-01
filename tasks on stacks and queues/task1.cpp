#include <iostream>
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

void reverse(stack *&h) {
    stack *head1 = NULL;
    while(h) {
        push(head1, pop(h));
    }
    h = head1;
}

bool prime_number(int x) {
    if (x == 1) return false;
    for (int i = 2; i*i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

stack *result(stack *&h) {
    stack *res = NULL;
    while (h) {
        int x = pop(h);
        if (!prime_number(x)) {
            push(res, x);
        }
    }
    return res;
}

int main() {
    stack *h = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        push(h, t);
    }
    h = result(h);
    while (h) {
        cout << pop(h) << ' ';
    }
}