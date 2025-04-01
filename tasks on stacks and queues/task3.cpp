#include <iostream>
using namespace std;

struct queue {
    int inf;
    queue *next;
};

void push(queue *&h, queue *&t, int x) {
    queue *r = new queue;
    r->inf = x;
    r->next = NULL;
    if (!h && !t) {
        h = t = r;
    }
    else {
        t->next = r;
        t = r;
    }
}

int pop(queue *&h, queue *&t) {
    queue *r = h;
    int i = h->inf;
    h = h->next;
    if (!h) {
        t = NULL;
    }
    delete r;
    return i;
}

int main() {
    int n;
    cin >> n;
    queue *head = NULL;
    queue *tail = NULL;
    queue *head1 = NULL;
    queue *tail1 = NULL;
    queue *resh = NULL;
    queue *rest = NULL; 
    int first_chet = 0;
    for (int i = 0; i < n; i++) {
        int t; 
        cin >> t;
        if (t % 2 == 0 && !first_chet) 
            first_chet = t;
        push(head, tail, t);
    }
    for (int i = 0; i < n; i++) {
        int t = pop(head, tail);
        if (t == first_chet) {
            push(resh, rest, t);
            break;
        }
        else 
            push(head1, tail1, t);
    }   
    while(tail) {
        int t = pop(head, tail);
        push(resh, rest, t);
    }
    while(tail1) {
        int t = pop(head1, tail1);
        push(resh, rest, t);
    }
    for (int i = 0; i < n; i++) {
        cout << pop(resh, rest) << ' ';
    }
}