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

}