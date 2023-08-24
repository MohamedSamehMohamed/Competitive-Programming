#include<bits/stdc++.h>
using namespace std;
mt19937 eng{random_device{}()};
uniform_int_distribution<int> uid(0, (int)1e9); 
extern struct node* empty;
typedef int nodeType; 
struct node{
  nodeType val;
  int priority, sz, frq;
  node* ch[2], *par;
  node():ch({this, this}), par(this), priority(INT_MIN), sz(0), frq(0){}
  node(nodeType val):ch({empty, empty}), par(empty), priority(uid(eng)), sz(1), frq(1), val(val){}
};
node* empty = new node();
void push_up(node* root)
{
  root->sz = root->frq + root->ch[0]->sz + root->ch[1]->sz; 
}
void link(node* par, node* child, int dir)
{
  if (child != empty)
    child->par = par;
  if (par != empty)
    {
      par->ch[dir] = child;
      push_up(par);
    }
}
int getDir(node* par, node* child)
{
  return par->ch[1] == child; 
}
void rotate(node*& p, int dir)
{
  node* par = p->par, *q = p->ch[!dir];
  link(p, q->ch[dir], !dir);
  link(q, p, dir);
  link(par, q, getDir(par, q));
  p = q; 
}
void print(node* root, int dp = 0)
{
  if (root == empty)
    return;
  print(root->ch[0], dp + 1);
  printf("%s%3d\n", string(3 * dp, ' ').c_str(), root->val);
  print(root->ch[1], dp + 1);
}
void balance(node*& root)
{
  if (root->ch[0]->priority > root->priority)
    rotate(root, 1);
  if (root->ch[1]->priority > root->priority)
    rotate(root, 0);
}
void insert(node*& root, nodeType val)
{
  if (root == empty)
    root = new node(val);
  else if (root->val == val)
    root->frq++, root->sz++;
  else if (val < root->val)
    insert(root->ch[0], val);
  else
    insert(root->ch[1], val);
  push_up(root);
  balance(root);
}
node* remove_node(node* root)
{
  for (int d = 0; d < 2; d++)
  {
    if (root->ch[d] == empty)
    {
      auto to_del = root;
      link(root->par, root->ch[!d], getDir(root->par, root));
      root = root->ch[!d];
      delete to_del;
      return root; 
    }
  }
  if (root->ch[0]->priority > root->ch[1]->priority)
  {
    rotate(root, 1);
    root->ch[1] = remove_node(root->ch[1]);
  }else 
  {
    rotate(root, 0);
    root->ch[0] = remove_node(root->ch[0]);
  }
  return root; 
}
void del(node*& root, nodeType val)
{
  if (root == empty) return;
  if (root->val == val)
  {
    if (--root->frq == 0)
    {
      root = remove_node(root);
    }
  }else if (val < root->val)
    del(root->ch[0], val);
  else 
    del(root->ch[1], val);
  push_up(root);
}
nodeType getByIndex(node* root, int idx)
{
  if (idx == 0)
    return root->val; 
  if (root->ch[0]->sz > idx)
    return getByIndex(root->ch[0], idx);
  int totSz = root->ch[0]->sz + root->frq;
  if (totSz <= idx)
    return getByIndex(root->ch[1], idx - totSz);
  return root->val;
}
int main()
{
  node* root = empty;
  vector<int> to_insert = {7, 6, 5, 4, 3};
  for (auto i: to_insert)
    insert(root, i);
  print(root);
  del(root, 6);
  printf("__________________\n");
  print(root);
}