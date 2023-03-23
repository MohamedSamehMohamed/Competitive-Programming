// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 1 << 17, Mx = 1e9;
int a[N], seg[N<<1], n, q;
struct Node; 
extern Node *empty;  
struct Node
{
	int frq;
	Node *l, *r;
	Node()
	{
		frq = 0;
		l = r = this; 
	}
	Node(int x, Node *l = empty, Node *r = empty)
	{
		frq = x;
		this->l = l;
		this->r = r; 
	}
};
Node *empty = new Node;
Node *pos[N]; 
Node *insert(Node *node, int val, int l = 0, int r = Mx)
{
	if (val > r || val < l)
		return node; 
	if (l == r)return new Node(node->frq+1, node->l, node->r); 
	int m = (l+r)>>1;
	Node *left  = insert(node->l, val, l, m);
	Node *right = insert(node->r, val, m+1, r); 
	return new Node(left->frq + right->frq, left, right); 
} 
int count(Node *L, Node *R, int val, int l = 0, int r = Mx)
{
	if (val < l || val > r)
		return 0;
	if (l == r)
		return R->frq - L->frq;
	int m = (l+r) >> 1;
	return count(L->l, R->l, val, l, m) + count(L->r, R->r, val, m+1, r); 
}
void build(int node = 0, int l = 0, int r = n-1)
{
	if (l == r)
	{
		seg[node] = a[l]; 
		return;
	}
	int m = (l+r)>>1;
	int n1 = node * 2 + 1;
	int n2 = n1 + 1;
	build(n1, l, m);
	build(n2, m+1, r);
	seg[node] = __gcd(seg[n1],seg[n2]); 
}
int query(int le, int re, int node = 0, int l = 0, int r = n-1)
{
	if (le > r || re < l)return 0; 
	if (l >= le && r <= re)return seg[node];
	int m = (l+r)>>1;
	int n1 = node * 2 + 1;
	int n2 = n1 + 1;
	return __gcd(query(le, re, n1, l, m),query(le, re, n2, m+1, r)); 
}
int main()
{
	scanf("%d", &n);
	pos[0] = empty; 
	for (int i = 0; i < n; i++)
		scanf("%d", a+i);
	for (int i = 0; i < n; i++)
		pos[i+1] = insert(pos[i], a[i]);  
	build();
	scanf("%d", &q);
	while(q--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		int g = query(l-1, r-1);
		int c = count(pos[l-1], pos[r], g); 
		printf("%d\n", r-l+1-c);
	}
}
