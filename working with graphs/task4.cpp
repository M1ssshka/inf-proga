#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> gr;
vector<char> used;
vector<int> ord;

void ts(int v) {
    used[v] = true;
    for (int u : gr[v]) {
        if (!used[u]) ts(u);
    }
    ord.push_back(v);
}

int main()
{
    int n, m;
    cin >> n >> m;
    gr.assign(n, {});
    for (int i = 0; i < m; i++)
    {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        gr[v].push_back(u);
    }
    used.assign(n, {});
    for (int i = 0; i < n; i++)
    {
        if (!used[i]) ts(i);
    }
    reverse(ord.begin(), ord.end());
}