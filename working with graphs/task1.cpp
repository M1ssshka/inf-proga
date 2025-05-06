#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> gr;

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
    int x;
    cin >> x;
    x--;
    cout << '\n' << gr[x].size() << '\n';
    for (int i = 0; i < n; i++) {
        cout << i + 1 << " : " << gr[i].size() << '\n';
    }
}