#include <iostream>
using namespace std;

struct stack{
    char inf;
    stack *next;
};

void push(stack *&h, char x) {
    stack *r = new stack;
    r->inf = x;
    r->next = h;
    h = r;
}

char pop(stack *&h) {
    char i = h->inf;
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

int main() {
    stack *h = NULL;
    stack *glas = NULL;
    stack *sogl = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char t;
        cin >> t;
        if (t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u') {
            push(glas, t);
        }
        else {
            push(sogl, t);
        }
    }
    while(glas || sogl) {
        char t;
        if (sogl) t = pop(sogl);
        else t = pop(glas);
        push(h, t);
    }
    while(h) {
        cout << pop(h) << ' ';
    }
}
