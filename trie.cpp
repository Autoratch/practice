#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;

int n,q,cnt;
int tree[N][26],res[N];

void add(string s,int x)
{
    int cur = 0;
    for(char c : s)
    {
        if(tree[cur][c-'a']==0) 
        {
            tree[cur][c-'a'] = ++cnt;
            cur = cnt;
            res[cur] = x;
        }
        else 
        {
            cur = tree[cur][c-'a'];
            res[cur] = max(res[cur],x);
        }
    }
}

int find(string s)
{
    int cur = 0;
    for(char c : s)
    {
        if(tree[cur][c-'a']==0) return -1;
        cur = tree[cur][c-'a'];
    }
    return res[cur];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    for(int i = 0;i < n;i++)
    {
        string s;
        int x;
        cin >> s >> x;
        add(s,x);
    }
    for(int i = 0;i < q;i++)
    {
        string s;
        cin >> s;
        cout << find(s) << '\n';
    }
}
