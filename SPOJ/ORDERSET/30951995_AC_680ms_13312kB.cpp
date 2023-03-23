// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
// #include <ext/pb_ds/detail/standard_policies.hpp>
struct node;
extern node* empty;
enum DIR{L, R};
struct node{
  long long val;
  int p, sz, frq;
  node *ch[2];
  node()
  {
    val = 0;
    p = INT_MIN;
    frq = sz = 0;
    ch[0] = ch[1] = this;
  }
  node (int val, node *l = empty, node *r = empty)
  {
    p = rand();
    this->val = val;
    frq = 1;
    ch[0] = l;
    ch[1] = r;
    push_up();
  }
  void push_up()
  {
    sz = ch[0]->sz + ch[1]->sz + frq;
  }
};
void rotate(node *&root, DIR dir)
{
    node *p = root;
    node *q = p->ch[!dir];
    p->ch[!dir] = q->ch[dir];
    q->ch[dir] = p;
    p->push_up();
    q->push_up();
    root = q;
}
void balance(node *&root)
{
    if (root->ch[0]->p > root->p)
        rotate(root, R);
    else if (root->ch[1]->p > root->p)
        rotate(root, L);
}

void insert(node *&root, const long long &val)
{
    if (root == empty)
    {
        root = new node(val);
        return;
    }
    if (root->val == val)
    {
        root->frq++;
        root->sz++;
        return;
    }
    insert(root->ch[root->val<val], val);
    root->push_up();
    balance(root);
}
void erase(node *&root, long long val)
{
    if (root == empty)
        return;
    if (root->val > val)
        erase(root->ch[0], val);
    else if (root->val < val)
        erase(root->ch[1], val);
    else
    {
        if (root->frq > 1)
        {
            root->frq--;
            root->sz--;
            return;
        }
        int mxi = 0, mxp = root->ch[0]->p;
        for (int i = 0; i < 2; i++)
        {
            if (root->ch[i]->p > mxp)
                mxp = root->ch[i]->p, mxi = i;
            if (root->ch[i] == empty)
            {
                node *temp = root->ch[!i];
                delete root;
                root = temp;
                return;
            }
        }
        rotate(root, (DIR)!mxi);
        erase(root, val);
    }
    root->push_up();
}
const long long &getByIndex(node *root,int ind)
{
    if(ind<root->ch[L]->sz)
        return getByIndex(root->ch[L],ind);
    int sum=root->ch[L]->sz+root->frq;
    if(ind>=sum)
        return getByIndex(root->ch[R],ind-sum);
    return root->val;
}
int lower_bound(node *&root,const long long& val)
{
    if(root==empty)
        return 0;
    if(root->val==val)
        return root->ch[L]->sz;
    if(root->val>val)
        return lower_bound(root->ch[L],val);
    return lower_bound(root->ch[R],val)+root->frq+root->ch[L]->sz;
}

void print(node *root, int dpth = 0)
{
    if (root == empty)
        return;
    print(root->ch[0], dpth+1);
    print(root->ch[1], dpth+1);
    printf("%s%2lld,%2d\n", string(dpth * 5, ' ').c_str(), root->val, root->p);
}
int getCount(node *&root,const long long &val)
{
    if(root==empty)
        return 0;
    if(root->val==val)
        return root->frq;
    if(root->val>val)
        return getCount(root->ch[L],val);
    return  getCount(root->ch[R],val);
}
node *empty = new node;
using namespace std ;
int main()
{
    int n,val;
    char type;
    node *rt=empty;
    scanf("%d",&n);
    while(n--)
    {
        scanf(" %c %d",&type,&val);
        switch (type)
        {
            case 'I':
                if(getCount(rt,val)==0)
                    insert(rt,val);
                break;
            case 'D':
                erase(rt,val);
                break;
            case 'K':
                if(val>rt->sz)
                    puts("invalid");
                else
                    printf("%lld\n",getByIndex(rt,val-1));
                break;
            case 'C':
                printf("%d\n",lower_bound(rt,val));
                break;
        }
    }
}
