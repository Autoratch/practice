#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n,m;
vector<pair<int,int> > adj[N];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
int dist[N];
bool visited[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 0;i < m;i++)
    {
        int a,b,d;
        cin >> a >> b >> d;
        adj[a].push_back({d,b});
        adj[b].push_back({d,a});
    }
    for(int i = 1;i <= n;i++) dist[i] = INT_MAX;
    q.push({0,1});
    dist[1] = 0;
    while(!q.empty())
    {
        int u = q.top().second;
        q.pop();
        if(visited[u]) continue;
        visited[u] = true;
        for(int i = 0;i < adj[u].size();i++)
        {
            int w = adj[u][i].first,v = adj[u][i].second;
            if(dist[u]+w<dist[v]) dist[v] = dist[u]+w,q.push({dist[v],v});
        }
    }
    for(int i = 1;i <= n;i++) cout << dist[i] << '\n';
}