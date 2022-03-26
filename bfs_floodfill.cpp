#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 1;

int m,n;
queue<pair<int,int> > q;
bool visited[N][N];

int main()
{
    cin >> m >> n;
    while(!q.empty())
    {
        int x = q.front().first,y = q.front().second;
        q.pop();
        for(int i = -1;i <= 1;i++) for(int j = -1;j <= 1;j++)
        {
            if(i==0 and j==0) continue;
            if(i!=0 and j!=0) continue;
            int ai = x+i,aj = y+j;
            if(ai<1 or ai>m or aj<1 or aj>n) continue;
            if(visited[ai][aj]) continue;
            visited[ai][aj] = true;
            q.push({ai,aj});
        }
    }
}