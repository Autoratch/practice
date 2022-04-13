#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int n,m;
vector<int> adj[N],ans;
int indeg[N];
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
        indeg[v]++;
    }
    for(int i = 1;i <= n;i++) if(indeg[i]==0) q.push(i);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for(int v : adj[u]) 
        {
            indeg[v]--;
            if(indeg[v]==0) q.push(v);
        }
    }
    if(ans.size()<n) cout << "-1";
    else for(int x : ans) cout << x << ' ';
}