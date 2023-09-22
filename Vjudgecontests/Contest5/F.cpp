// Author : Mohamed Sameh
// created in: 9:13 PM
#include <bits/stdc++.h>
using namespace std;
template <typename T>
class segmentTree {
public:
  struct Node{
    T val;
    T hasLazy;
    Node():val(0), hasLazy(0){}
    Node(T _val): val(_val), hasLazy(0){}
    Node(T _val, T _hasLazy): val(_val), hasLazy(_hasLazy){}
    void addLazy(int l, int r, T lazyValue)
    {
      val = lazyValue * (r - l + 1);
      hasLazy = lazyValue;
    }
    void addVal(int l, int r, T _val, T _lazyValue)
    {
      val = _val * (r - l + 1);
      hasLazy = _lazyValue;
    }
    Node operator+(Node& other)
    {
      Node ret = Node();
      ret.val = val + other.val;
      return ret;
    }
  };
  vector<Node> segTree;
  vector<T> a;
  int n;
  segmentTree(int _n)
  {
    n = _n;
    segTree.resize(4 * n);
  }
  segmentTree(int _n, vector<T>& _a)
  {
    n = _n;
    a = _a;
    segTree.resize(4 * n);
    build(0, 0, n-1);
  }
  void pushdown(int node, int l, int r)
  {
    if (segTree[node].hasLazy != 0)
    {
      int n1 = node * 2 + 1;
      int n2 = n1 + 1;
      int m = (l+r) >> 1;
      segTree[n1].addLazy(l, m, segTree[node].hasLazy);
      segTree[n2].addLazy(m+1, r, segTree[node].hasLazy);
      segTree[node].hasLazy = 0;
    }
  }
  void build(int node, int l, int r)
  {
    if (l == r)
    {
      segTree[node] = Node(a[l]);
      return;
    }
    int m = (l+r) >> 1;
    int n1 = node * 2 + 1;
    int n2 = n1 + 1;
    build(n1, l, m);
    build(n2, m+1, r);
    segTree[node] = segTree[n1] + segTree[n2];
  }
  Node queryHelper(int node, int l, int r, int le, int re)
  {
    if (l >= le && r <= re)
      return segTree[node];
    pushdown(node, l, r);
    int m = (l+r) >> 1;
    int n1 = node * 2 + 1;
    int n2 = n1 + 1;
    if (re <= m)
      return queryHelper(n1, l, m, le, re);
    else if (le > m)
      return queryHelper(n2, m+1, r, le, re);
    return mergeNode(queryHelper(n1, l, m, le, re) , queryHelper(n2, m+1, r, le, re));
  }
  Node mergeNode(Node l, Node r)
  {
    return min(l.val, r.val);
  }
  Node query(int l, int r)
  {
    return queryHelper(0, 0, n-1, l, r);
  }
  void updateHelper(int node, int l, int r, int le, int re, T newVal, T lazy)
  {
    if (l > re || r < le)return;
    if (l >= le && r <= re)
    {
      segTree[node].addVal(l, r, newVal, lazy);
      return;
    }
    pushdown(node, l, r);
    int m = (l+r) >> 1;
    int n1 = node * 2 + 1;
    int n2 = n1 + 1;
    updateHelper(n1, l, m, le, re, newVal, lazy);
    updateHelper(n2, m+1, r, le, re, newVal, lazy);
    segTree[node] = segTree[n1] + segTree[n2];
  }
  void update(int l, int r, T newVal, T lazy = 0)
  {
    updateHelper(0, 0, n-1, l, r, newVal, lazy);
  }

};

const int N = 2e5 + 9;

int n, m;
int a[N];
set<int> adj[11][15];
vector<segmentTree<int>> segs[11][15];
void add(int index){
  int p = 0;
  int x = a[index];
  while (x){
    int d = x % 10;
    if (d){
      adj[d][p].insert(index);
      //segs[d][p][0].update(index, index, a[index]);
    }
    x /= 10;
    p++;
  }
}
void rem(int index){
  int p = 0;
  int x = a[index];
  while (x){
    int d = x % 10;
    if (d){
      adj[d][p].erase(index);
      //segs[d][p][0].update(index, index, (int)2e9);
    }
    x /= 10;
    p++;
  }
}
void solve(int l, int r){
  int mn = -1;
  for (int d1 = 1; d1 <= 9; d1++){
    for (int d2 = 1; d2 <= 9; d2++){
      for (int p = 0; p < 11; p++){
        /*
         * if (d1 == d2 && adj[d1][p].size() == 1) continue;

        auto mn1 = segs[d1][p][0].query(l, r);
        auto mn2 = segs[d2][p][0].query(l, r);
        int mx = 2e9;
        if (max(mn1.val, mn2.val) == mx)continue;
        if (mn == -1) mn = mn1.val + mn2.val;
        mn = min(mn, mn1.val + mn2.val);
        */
        auto it1 = adj[d1][p].lower_bound(l);
        auto it2 = adj[d2][p].lower_bound(l);
        if (it1 == adj[d1][p].end() || *it1 > r) continue;
        if (it2 == adj[d2][p].end() || *it2 > r) continue;
        if (d1 == d2 && adj[d1][p].size() == 1) continue;

        vector<int> one, two;
        while (it1 != adj[d1][p].end() && *it1 <= r){
          one.push_back(*it1);
          it1++;
        }
        while (it2 != adj[d2][p].end() && *it2 <= r){
          two.push_back(*it2);
          it2++;
        }

        for(auto ii: one){
          for(auto jj: two){
            if (ii == jj) continue;
            if (mn == -1) mn = a[ii] + a[jj];
            mn = min(mn, a[ii] + a[jj]);
          }
        }
      }
    }
  }
  printf("%d\n", mn);
}
void test(){
  scanf("%d%d", &n, &m);
  /*
  for (int i = 0; i < 11; i++)
    for (int j = 0; j < 15; j++){
      segs[i][j].push_back(segmentTree<int>(n));
      segs[i][j][0].update(0, n-1, (int)2e9);
    }
    */
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  for (int i = 0; i < n; i++)
    add(i);
  while (m--){
    int type, l, r;
    scanf("%d%d%d", &type, &l, &r);
    if (type == 1){
      l--;
      rem(l);
      a[l] = r;
      add(l);
    }else {
      l--;r--;
      solve(l, r);
    }
  }
}
int main()
{

  test();
}