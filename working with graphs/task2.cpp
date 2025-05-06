#include <iostream>
#include <vector>
#include <algorithm>
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
    int A, B;
    cin >> A >> B;
    for (int i = 0; i < gr.size(); i++)
    {
        cout << i + 1 << " : ";
        for (int j : gr[i])
        {
            cout << j + 1 << ' ';
        }
        cout << '\n';
    }
    if (A > n || B > n) {
        if (A > n)
            gr.push_back({});
        if (B > n)
            gr.push_back({});
    }
    A--;
    B--;
    cout << '\n';
    gr[A].push_back(B);
    gr[B].push_back(A);
    for (int i = 0; i < gr.size(); i++)
    {
        sort(gr[i].begin(), gr[i].end());   
        gr[i].erase(unique(gr[i].begin(), gr[i].end()), gr[i].end());
    }
    for (int i = 0; i < gr.size(); i++)
    {
        cout << i + 1 << " : ";
        for (int j : gr[i])
        {
            cout << j + 1 << ' ';
        }
        cout << '\n';
    }
}