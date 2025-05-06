#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> gr;
vector<vector<int>> tgr;
vector<char> used;
vector<int> ord;

vector<int> clr;
int comp = 0;

void dfs(int v)
{
    clr[v] = comp;
    for (int u : tgr[v])
    {
        if (clr[u] == -1)
            dfs(u);
    }
}

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
    tgr.assign(n, {});
    for (int i = 0; i < m; i++)
    {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        gr[v].push_back(u);
        tgr[u].push_back(v);
    }
    used.assign(n, {});
    for (int i = 0; i < n; i++)
    {
        if (!used[i]) ts(i);
    }
    reverse(ord.begin(), ord.end());
    clr.assign(n, -1);
    for (int i : ord)
    {
        if (clr[i] == -1)
        {
            dfs(i);
            comp++;
        }
    }
    cout << '\n';
    int t = 0;
    for (int x : ord) {
        if (t != clr[x]) {
            cout << '\n';
            t = clr[x];
        }
        cout << x + 1 << ' ';
    }
    cout << '\n';
}