#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> gr;
vector<char> used;

void dfs(int v) {
    used[v] = true;
    for (int u : gr[v]) {
        if (!used[u]) dfs(u);
    }
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
        gr[u].push_back(v);
    }
    used.assign(n, {});
    dfs(0);
}