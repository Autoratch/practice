#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int n,pa[N];

int root(int x)
{
    if(pa[x]==x) return x;
    else return pa[x] = root(pa[x]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

}
