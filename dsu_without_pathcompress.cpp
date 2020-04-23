#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int n,pa[N];

int root(int x){ if(pa[x]<0) return x; return root(pa[x]); }

void merge(int a,int b)
{
    a = root(a),b = root(b);
    if(a==b) return;
    if(abs(pa[a])<abs(pa[b])) swap(a,b);
    pa[a]+=pa[b],pa[b] = a;
}

int main()
{
    for(int i = 1;i <= n;i++) pa[i] = -1;
    // if x is root, pa[x] will be (-) of height
    // else pa[x] will be parent of x
    // dsu without path compression that run in o(nlgn)
}
