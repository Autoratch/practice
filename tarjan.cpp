#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int n,m;
vector<int> adj[N];
int disc[N],low[N];
bool visited[N];
int idx;
set<int> ap;
set<pair<int,int> > b;

void dfs(int u,int p)
{
    visited[u] = true;
    low[u] = disc[u] = idx++;
    int ch = 0;
    for(int v : adj[u])
    {
        if(!visited[v])
        {
            ch++;
            dfs(v,u);
            low[u] = min(low[u],low[v]);
            if((p!=-1 and low[v]>=disc[u])or(p==-1 and ch>1)) ap.insert(u);
            if(low[v]>disc[u]) b.insert({u,v});
        }
        else if(v!=p)
        {
            low[u] = min(low[u],disc[v]);
        }
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
        adj[b].push_back(a);
    }

    dfs(0,-1);

    cout << ap.size() << '\n';
    for(int x : ap) cout << x << ' ';
    cout << '\n' << b.size() << '\n';
    for(pair<int,int> x : b) cout << x.first << ' ' << x.second << '\n';
}
