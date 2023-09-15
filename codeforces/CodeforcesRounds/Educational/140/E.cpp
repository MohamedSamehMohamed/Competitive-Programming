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
      segments.emplace_back(1);  
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
      return query_helper(segments[segmentId], l, r, st, en); 
    }
    void clone(int segmentId)
    {
      segments.emplace_back(segments[segmentId]); 
    }
};

int n, q; 
int main()
{
  #ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
  scanf("%d", &n); 
  PresistanceSegmentTree<int> seg(1, n);
  int cur_id = 1; 
  for(int i = 1, x; i <= n; i++)
  {
    scanf("%d", &x); 
    seg.insert(cur_id, i, x);
    if (i + 1 <= n)
    {
      seg.clone(cur_id); 
      cur_id++; 
    } 
  }
  scanf("%d", &q); 
  while(q--)
  {
    int l, r;
    scanf("%d%d", &l, &r); 

  }

}