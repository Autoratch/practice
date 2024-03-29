#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n,m;
vector<int> adj[N],rev[N];
stack<int> st;
bool visited[N];

void dfs(int u)
{
    if(visited[u]) return;
    visited[u] = true;
    for(int v : adj[u]) dfs(v);
    st.push(u);
}

void scc(int u)
{
    if(visited[u]) return;
    visited[u] = true;
    cout << u << ' ';
    for(int v : rev[u]) scc(v);
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
        rev[b].push_back(a);
    }

    for(int i = 1;i <= n;i++) if(!visited[i]) dfs(i);

    memset(visited,0,sizeof visited);

    while(!st.empty())
    {
        int u = st.top();
        st.pop();
        if(visited[u]) continue;
        scc(u); 
        cout << '\n';
    }
}
