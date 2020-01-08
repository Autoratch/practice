#include <bits/stdc++.h>
using namespace std;

struct node
{
    int size,val,prio;
    node *l,*r;
};

using pnode = node*;

int sz(pnode t){ if(t) return t->size; else return 0; }
void updt(pnode t){ if(t) t->size = sz(t->l)+sz(t->r)+1; }

void split(pnode t,pnode &l,pnode &r,int key)
{
    if(!t) l = r = NULL;
    else if(t->val<=key) split(t->r,t->r,r,key),l = t;
    else split(t->l,l,t->l,key),r = t;
    updt(t);
}

void merge(pnode &t,pnode l,pnode r)
{
    if(!l or !r){ if(!l) t = r; else t = l; }
    else if(l->prio>r->prio) merge(l->r,l->r,r),t = l;
    else merge(r->l,l,r->l),t = r;
    updt(t);
}

void insert(pnode &t,pnode it)
{
    if(!t) t = it;
    else if(it->prio>t->prio) split(t,it->l,it->r,it->val),t = it;
    else 
    {
        if(it->val>t->val) insert(t->r,it);
        else insert(t->l,it);
    }
    updt(t);
}

void erase(pnode &t,int key)
{
    if(!t) return;
    else if(t->val==key){ pnode tmp = t; merge(t,t->l,t->r); free(tmp); }
    else
    {
        if(key>t->val) erase(t->r,key);
        else erase(t->l,key);
    }
    updt(t);
}

pnode init(int val)
{
    pnode ret = new node;
    *ret = {1,val,rand(),NULL,NULL};
    return ret;
}

int main()
{
    srand(time(NULL));
}
