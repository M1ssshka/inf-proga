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
    bool f = true;
    for (int i = 0; i < n; i++)
    {
        if (!used[i]) f = false;
    }
    (f) ? (cout << "YES" << '\n') : (cout << "NO" << '\n');
}

// 5 4
// 1 2
// 2 3
// 3 4
// 3 5

// 6 4
// 1 2
// 2 3
// 3 4
// 3 5