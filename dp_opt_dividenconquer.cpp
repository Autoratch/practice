#include <bits/stdc++.h>
using namespace std;

// dp(i,j) = min{dp(i-1,k)+c(k,j)}
//           k<=j

const int N = 1e5;

int dp[2][N];

int c(int x,int y);

void compute(int l,int r,int optl,int optr,int f,int id)
{
    if(l>r) return;
    int mid = (l+r)/2;
    int val = INT_MAX,opt;
    for(int k = optl;k <= min(optr,mid);k++)
    {
        int now = dp[f^1][k]+c(k,mid);
        if(now<val) val = now,opt = k;
    }
    // id is i, and mid is j, for dp(i,j)
    dp[f][mid] = val; // opt of k is opt
    compute(l,mid-1,optl,opt,f,id);
    compute(mid+1,r,opt,optr,f,id);
}

int main()
{
    // each time calling compute starting with i instead of 1 makes it faster
    // call compute(i,n-1,0,n-1) for m times, as 0 < i < m
    // each time f would denote state space reduction
}
