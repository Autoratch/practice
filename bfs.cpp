#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n,m;
vector<int> adj[N];
bool visited[N];
queue<int> q;

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
    q.push(1);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        if(visited[u]) continue;
        visited[u] = true;
        cout << u << ' ';
        for(int v : adj[u]) 
            q.push(v);
    }
}