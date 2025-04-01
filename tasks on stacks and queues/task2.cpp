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
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        push(head, tail, t);
    }
    int first = pop(head, tail);
    push(resh, rest, first);
    int max_num = first;
    while(tail) {
        int temp = pop(head, tail);
        max_num = max(max_num, temp);
        push(head1, tail1, temp);
    } 
    push(resh, rest, max_num);
    while(tail1) {
        int temp = pop(head1, tail1);
        push(resh, rest, temp);
        if (temp == first) {
            push(resh, rest, max_num);
        }
    }
    while(rest) {
        cout << pop(resh, rest) << ' ';
    }
}