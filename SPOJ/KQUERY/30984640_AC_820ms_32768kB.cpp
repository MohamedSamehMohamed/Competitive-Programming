#include<bits/stdc++.h>
using namespace std;
const int N = 250009;
int n, q;
struct Node;
extern Node *empty;

struct Node{
	int sum;
	Node *lt,*rt;
	Node() : sum(0) , lt(this) , rt(this){}
	Node(int v,Node *l = empty,Node *r = empty) : sum(v) , lt(l) , rt(r){}
};
Node *empty = new Node();
Node *nodes[N];

Node *Insert(Node *root,int idx, int l = 1,int r = 1e9)
{
	if(idx < l || idx > r)
		return root;
	if(l == r)
		return new Node(root->sum+1);

	int mid = (l+r) >> 1;
	Node *lt = Insert(root->lt,idx, l,mid);
	Node *rt = Insert(root->rt,idx, mid+1,r);

	return new Node(lt->sum+rt->sum,lt,rt);
}

int lessThaneq(Node *rl,Node *rr,int k, int l = 1,int r = 1e9)
{
  if (l > k)
    return 0;
	int cnt = rr->sum - rl->sum;
  if (r <= k)
    return cnt;
	int mid = (l+r) >> 1;
	return lessThaneq(rl->lt,rr->lt,k, l,mid) + lessThaneq(rl->rt,rr->rt,k, mid+1,r);
}

int main()
{
 // wow 
  nodes[0] = empty;
  scanf("%d", &n);
  for (int i = 1, x; i <= n; i++)
  {
    scanf("%d", &x);
    nodes[i] = Insert(nodes[i-1], x);
  }
  scanf("%d", &q);
  while(q--)
  {
    int l, r, k;
    scanf("%d%d%d", &l, &r, &k);
    printf("%d\n", (r-l+1) - lessThaneq(nodes[l-1], nodes[r], k));
  }
}
