#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n,m;
vector<int> adj[N];
bool visited[N];

void dfs(int u,int p)
{
    if(visited[u]) return;
    visited[u] = true;
    cout << u << ' ';
    for(int v : adj[u]) if(v!=p)
        dfs(v,u);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 0;i < m;i++) 
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
}
