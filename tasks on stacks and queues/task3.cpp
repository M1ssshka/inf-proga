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

}