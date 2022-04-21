#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;

int n,m,dist[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 1;i <= n;i++) for(int j = 1;j < i;j++) dist[i][j] = dist[j][i] = INT_MAX;
    for(int i = 0;i < m;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        dist[u][v] = dist[v][u] = w;
    }
    for(int k = 1;k <= n;k++) for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++)
        if(dist[i][k]!=INT_MAX and dist[k][j]!=INT_MAX and dist[i][k]+dist[k][j]<dist[i][j])
            dist[i][j] = dist[i][k]+dist[k][j];
    for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) cout << i << ' ' << j << ' ' << dist[i][j] << '\n';    
}