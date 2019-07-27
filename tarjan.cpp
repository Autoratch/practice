#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n,m;
vector<int> adj[N];
bool visited[N];
int disc[N],low[N];
int cnt;
set<int> ap;
set<pair<int,int> > bridge;

void tarjan(int u,int p)
{
    visited[u] = true;
    low[u] = disc[u] = ++cnt;
    int ch = 0;
    for(auto v : adj[u])
    {
        if(!visited[v])
        {
            ch++;
            tarjan(v,u);
            low[u] = min(low[u],low[v]);
            if((p and low[v]>=disc[u])or(!p and ch>1)) ap.insert(u);
            if(low[v]>disc[u]) bridge.insert({u,v});
        }       
        else if(v!=p) low[u] = min(low[u],disc[v]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for(int i = 0;i < m;i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    tarjan(1,0);

    for(int x : ap) cout << x << ' ';
    cout << '\n' << '\n';
    for(pair<int,int> x : bridge) cout << x.first << ' ' << x.second << '\n';
}
