#include <bits/stdc++.h>
using namespace std;
void read_file()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
}
#include<bits/stdc++.h>
using namespace std;
template <typename T>
class PresistanceSegmentTree{
  struct Node
  {
      T val; 
      int left, right; 
      Node(): val(0), left(0), right(0){}
      Node(T _val): val(_val), left(0), right(0){}
      Node(T _val, int _left, int _right): val(_val), left(_left), right(_right){}
  };
  vector<Node> nodes; 
  vector<int> segments; 
  public:
    int st, en; 
    PresistanceSegmentTree(int _st, int _en): st(_st), en(_en){
      nodes.emplace_back(Node());
      nodes.emplace_back(Node());
      segments.emplace_back(0);
      //segments.emplace_back(1);  
    }
    void create(int& node, int force = 0)
    {
      if (force)node = 0; 
      if (node)return; 
      node = nodes.size(); 
      nodes.emplace_back(Node());
    }
    int insert_helper(int node, long long idx, T val, long long l, long long r, int force)
    {
      if (l > idx || r < idx)
          return node; 
      if (l == r)
      {
        create(node, force);
        nodes[node] = Node(val); 
        return node; 
      }
      long long m = (l+r) >> 1LL; 
      int left  = insert_helper(nodes[node].left, idx, val, l, m, force); 
      int right = insert_helper(nodes[node].right, idx, val, m+1, r, force); 
      create(node, force);
      nodes[node] = Node(nodes[left].val + nodes[right].val, left, right);
      return node;
    }
    T query_helper(int node, long long le, long long re, long long l, long long r)
    {
      if (l > re || r < le)return 0; 
      if(l >= le && r <= re) return nodes[node].val; 
      long long m = (l+r) >> 1LL; 
      return query_helper(nodes[node].left, le, re, l, m) + query_helper(nodes[node].right, le, re, m+1, r); 
    }
    void insert(int segmentId, long long idx, T val)
    {
      segments[segmentId] = insert_helper(segments[segmentId], idx, val, st, en, 0);
    }
    void update(int segmentId, long long idx, T val)
    {
      segments[segmentId] = insert_helper(segments[segmentId], idx, val, st, en, 1);
    }
    T query(int segmentId, int l, int r)
    {
      if (l > r)return 0;
      if (l < st) l = st; 
      if (r > en) r = en;
      assert(l >= 0 && l <= en);
      assert(r >= 0 && r <= en); 
      assert(l <= r); 
      return query_helper(segments[segmentId], l, r, st, en); 
    }
    void clone(int segmentId)
    {
      segments.emplace_back(segments[segmentId]); 
    }
};
const int N = 2e5 + 9;
int n; 
int main()
{
  read_file();
  scanf("%d", &n);
  vector<array<int, 4>> v(n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d%d", &v[i][0], &v[i][1]);
    v[i][2] = v[i][3] = 0;  
  }  
  sort(v.begin(), v.end()); 
  for(int i = 1; i < n; i++)
  {
    if (v[v[i-1][2]][1] > v[i][1])
        v[i][2] = v[i-1][2];
    else 
        v[i][2] = i; 

    if (v[v[i-1][3]][1] < v[i][1])
        v[i][3] = v[i-1][3];
    else 
        v[i][3] = i; 
  }
  auto can = [&](long long dist)
  {
    for(int i = 0; i < n; i++)
    {
      long long max_x = v[i][0] - dist; 
      int l = 0, r = i-1, m, idx = -1;
      while(l <= r)
      {
        m = (l+r) >> 1;
        if (v[m][0] <= max_x)
          idx = m, l = m + 1;
        else 
          r = m-1; 
      }
      if (~idx)
      {
        int mx = v[v[idx][2]][1];
        int mn = v[v[idx][3]][1]; 
        if (abs(v[i][1] - mx) >= dist)return 1; 
        if (abs(v[i][1] - mn) >= dist)return 1;
      } 
    }
    return 0; 
  };
  long long l = 1, r = 1e9 + 20, m, ans = 0;
  while(l <= r)
  {
    m = (l+r) >> 1LL; 
    if (can(m))
      ans = m, l = m + 1; 
    else 
      r = m-1; 
  }
  printf("%lld\n", ans);
}