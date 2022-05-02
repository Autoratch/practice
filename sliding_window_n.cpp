#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n,k;
int a[N];
deque<pair<int,int> > q;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i < k;i++)
    {
        while(!q.empty() and q.back().first<=a[i]) q.pop_back();
        q.push_back({a[i],i});
    }
    for(int i = k;i <= n;i++)
    {
        while(q.front().second<=i-k) q.pop_front();
        while(!q.empty() and q.back().first<=a[i]) q.pop_back();
        q.push_back({a[i],i});
        cout << "max of " << i-k+1 << " to " << i << " : " << q.front().first << '\n';
    }
}