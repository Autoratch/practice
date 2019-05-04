#include <bits/stdc++.h>
using namespace std;

int rmq[20][1000100];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n,q;

    cin >> n >> q;

    for(int i = 0;i < n;i++) cin >> rmq[0][i];
    
    for(int i = 0;(1 << i) <= n;i++)
    {
        for(int j = 0;j+ (1 << i) < n;j++) 
            rmq[i][j] = max(rmq[i-1][j],rmq[i-1][j+(1 << (i-1))]);
    }

    while(q--)
    {
        int a,b;
        cin >> a >> b;
        int k = log2(b-a+1);
        cout << max(rmq[k][a],rmq[k][b-(1 << k)+1]);
    }
}
