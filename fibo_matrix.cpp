#include <bits/stdc++.h>
using namespace std;

const int N = 2;
const int K = 30;

struct data
{
    int t[N][N];
};

int k;
data m[30],ans;

data mul(data *a,data *b)
{
    data c;
    for(int i = 0;i < N;i++) for(int j = 0;j < N;j++)
    {
        c.t[i][j] = 0;
        for(int k = 0;k < N;k++) c.t[i][j]+=a->t[i][k]*b->t[k][j];
    }
    return c;
}

int main()
{
    cin >> k;

    for(int i = 0;i < 2;i++) for(int j = 0;j < 2;j++) m[0].t[i][j] = 1;
    m[0].t[1][1] = 0;
    ans.t[0][0] = ans.t[1][1] = 1;

    for(int i = 1;i < K;i++) m[i] = mul(&m[i-1],&m[i-1]);

    for(int i = 0;i < K;i++) if((1<<i)&k) ans = mul(&ans,&m[i]);

    cout << ans.t[0][0];
}
