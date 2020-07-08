#include <bits/stdc++.h>
using namespace std;

vector<long long> m,b;

bool bad(int l1,int l2,int l3)
{
    return (double)(b[l2]-b[l3])*(m[l2]-m[l1])<(double)(b[l1]-b[l2])*(m[l3]-m[l2]);
}

void add(long long mx,long long bx)
{
    m.push_back(mx),b.push_back(bx);
    while(m.size()>=3 and bad(m.size()-3,m.size()-2,m.size()-1)) 
        m.erase(m.end()-2),b.erase(b.end()-2);
}

int ptr;
long long query(long long x)
{
    if(ptr>=m.size()) ptr = m.size()-1;
    while(ptr<m.size()-1 and m[ptr+1]*x+b[ptr+1]>m[ptr]*x+b[ptr]) ptr++;
    return m[ptr]*x+b[ptr];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);


}
