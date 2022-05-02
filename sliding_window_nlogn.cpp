#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n,k;
int a[N];
priority_queue<pair<int,int> > q;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i < k;i++) q.push({a[i],i});
    for(int i = k;i <= n;i++)
    {
        while(q.top().second<=i-k) q.pop();
        q.push({a[i],i});
        cout << "max of " << i-k+1 << " to " << i << " : " << q.top().first << '\n';
    }
}