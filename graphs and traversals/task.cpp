#include <iostream>
#include <vector>
using namespace std;

struct queue {
    int inf;
    queue *next;
};

void push_q(queue *&h, queue *&t, int x) {
    queue *r = new queue;
    r->inf = x;
    r->next = nullptr;
    if (!h && !t) {
        h = t = r;
    }
    else {
        t->next = r;
        t = r;
    }
}

int pop_q(queue *&h, queue *&t) {
    queue *r = h;
    int i = h->inf;
    h = h->next;
    if (!h) {
        t = nullptr;
    }
    delete r;
    return i;
}

void bfs(queue *&h, queue *&t, vector<vector<int>> gr, vector<int> &used, int x) {
    used[x] = 1;
    push_q(h, t, x);
    cout << x + 1 << ' ';
    while(h) {
        x = h->inf;
        pop_q(h, t);
        int y;
        for (int i = 0; i < gr[x].size(); i++) {
            if (!used[gr[x][i]]) {
                y = gr[x][i];
                used[y] = 1; 
                push_q(h, t, y);   
                cout << y + 1 << ' ';
            }
        }
    }
}

struct stack{
    int inf;
    stack *next;
};

void push_s(stack *&h, int x) {
    stack *r = new stack;
    r->inf = x;
    r->next = h;
    h = r;
}

int pop_s(stack *&h) {
    int i = h->inf;
    stack *r = h;
    h = h->next;
    delete r;
    return i;
}

int main() {

}