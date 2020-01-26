#include <bits/stdc++.h>
using namespace std;

int n;
struct pt{ double x,y; };
vector<pt> s,up,dn;
pt a,b;

bool cmp(pt a,pt b){ if(a.x!=b.x) return a.x<b.x; else return a.y<b.y; }

bool cw(pt a,pt b,pt c){ return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y)<0; }

bool ccw(pt a,pt b,pt c){ return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y)>0; }

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 0;i < n;i++){ int a,b; cin >> a >> b; s.push_back({a,b}); }
    sort(s.begin(),s.end(),cmp);
    a = s[0],b = s[s.size()-1];
    up.push_back(a),dn.push_back(a);
    for(int i = 1;i < s.size();i++)
    {
        if(i==s.size()-1 or cw(a,s[i],b)) // upper part
        {
            while(up.size()>=2 and !cw(up[up.size()-2],up[up.size()-1],s[i])) up.pop_back();
            up.push_back(s[i]);
        }
        if(i==s.size()-1 or ccw(a,s[i],b)) // lower part
        {
            while(dn.size()>=2 and !ccw(dn[dn.size()-2],dn[dn.size()-1],s[i])) dn.pop_back();
            dn.push_back(s[i]);
        }
    }
    s.clear();
    for(int i = 0;i < up.size();i++) s.push_back(up[i]);
    for(int i = dn.size()-2;i > 0;i--) s.push_back(dn[i]);
    for(int i = 0;i < s.size();i++) cout << s[i].x << ' ' << s[i].y << '\n';
}
