#include <bits/stdc++.h>
using namespace std;

const int N = 200;

struct data
{
    int t[N][N];
};

int n;
data mtrx[32];

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

    for(int i = 1;i < 30;i++) mtrx[i] = mul(&mtrx[i-1],&mtrx[i-1]);
}