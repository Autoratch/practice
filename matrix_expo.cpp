#include <bits/stdc++.h>
using namespace std;

const int N = 200;
const int K = 30; // constraint about 2^30

struct data
{
    int t[N][N];
};

int n,k; // n : size of matrix, k : power
data mtrx[32],ans; // mtrx[i] keeps m^i, ans keeps answer which is intially identity matrix

data mul(data *a,data *b)
{
    data c;
    for(int i = 0;i < n;i++) for(int j = 0;j < n;j++)
    {
        c.t[i][j] = 0;
        for(int k = 0;k < n;k++) c.t[i][j]+=a->t[i][k]*b->t[k][j];
    }
    return c;
}

int main()
{
    // build matrix that need to power and store in mtrx[0] => 2^0=1

    for(int i = 1;i < K;i++) mtrx[i] = mul(&mtrx[i-1],&mtrx[i-1]);

    for(int i = 0;i < n;i++) ans.t[i][i] = 1;

    for(int i = 0;i < K;i++) 
    {
        if((1<<i)&k) ans = mul(&m[i],&ans);
    }
}
