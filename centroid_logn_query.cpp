#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
const int K = 20;

int n,m;
vector<pair<int,int> > adj[N];
int sz[N];
bool blocked[N];
vector<pair<int,int> > diss[N];

void dfs(int u,int p,int st,int w)
{
    sz[u] = 1;
    if(st) diss[st].push_back({w,u}); // reduce log n on querying distance from node to centroid
    for(auto [d,v] : adj[u]) if(v!=p and !blocked[v]) dfs(v,u,st,w+d),sz[u]+=sz[v];
}

void build(int u,int cp)
{
    dfs(u,0,0,0); // dfs first time to get subtree size
    int c = u,prev = 0;
    while(true)
    {
        int mx = -1,id;
        for(auto [d,v] : adj[c]) if(!blocked[v] and v!=prev and sz[c]>mx) mx = sz[c],id = c;
        if(mx*2>sz[u]) prev = c,c = id;
        else break;
    }
    dfs(c,0,c,0); // dfs second time to store distance from centroid to each node
    blocked[c] = true;
    for(auto [d,v] : adj[c]) if(!blocked[v]) build(v,c);
}

void query(int u)
{
    for(auto [w,v] : diss[u]); // use stored value instead of calculating new one
    // reduce log^2 n to be log n for each query
}
