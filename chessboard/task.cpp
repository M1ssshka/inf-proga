#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct node {
    int x;
    int y;
};

struct queue {
    node inf;
    queue *next;
};

void push(queue *&h, queue *&t, node x) {
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

node pop(queue *&h, queue *&t) {
    queue *r = h;
    node i = h->inf;
    h = h->next;
    if (!h) {
        t = nullptr;
    }
    delete r;
    return i;
}

bool is_board(node t) {
    return (t.x < 8 && t.x >= 0 && t.y < 8 && t.y >= 0);
}

vector<vector<node>> p;
vector<vector<int>> used;
queue *h = nullptr;
queue *t = nullptr;
vector<int> dx = {1, 1, 2, -2, -1, -1, -2, 2};
vector<int> dy = {2, -2, 1, -1, -2, 2, 1, 1};
vector<queue> pr;

void bfs(node c0, node end) {
    push(h, t, c0);
    used[c0.x][c0.y] = 1;
    while(h) {
    c0 = h->inf;
    pop(h, t);
        for (int i = 0; i < 8; i++) {
            node c;
            c.x = dx[i] + c0.x; 
            c.y = dy[i] + c0.y;
            if (is_board(c)) {
                if(!used[c.x][c.y]) {
                    used[c.x][c.y] = 1;
                    p[c.x][c.y] = c0;
                    push(h, t, c);
                    if (c.x == end.x && c.y == end.y) {
                        return;
                    }
                }
            }
        }
    }
}

int main() {
    
}
