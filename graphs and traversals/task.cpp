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

void dfs(stack *&h, vector<vector<int>> gr, vector<int> &used, int x) {
    used[x] = 1;
    cout << x + 1 << ' ';
    push_s(h, x);
    bool fl = false;
    while(h) {
        x = h->inf;
        int y;
        for (int i = 0; i < gr[x].size(); i++) {
            if (!used[gr[x][i]]) {
                y = gr[x][i];
                fl = true;
                break;
            }
        }
        if (fl) {
            used[y] = 1;
            push_s(h, y);
            cout << y + 1 << ' ';
            fl = false;
        }
        else {
            pop_s(h);
        }
    }
}

int main() {
    int n, m; 
    cin >> n >> m; //n - количество рёбер, m - количество вершин
    vector<vector<int>> gr(m);
    for (int i = 0; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--; u--;
        gr[v].push_back(u);
        gr[u].push_back(v);
    }
    vector<int> used(n);
    stack *h_s = nullptr;
    int x;
    cin >> x;
    x--;
    cout << "DFS:" << '\n';
    dfs(h_s, gr, used, x);
    cout << '\n';
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(h_s, gr, used, i);
            cout << '\n';
        }
    }
    used.assign(m, {});
    queue *h_q = nullptr;
    queue *t_q = nullptr;
    cout << "BFS:" << '\n';
    bfs(h_q, t_q, gr, used, x);
    cout << '\n';
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            bfs(h_q, t_q, gr, used, i);
            cout << '\n';
        }
    }
}