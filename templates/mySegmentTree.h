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
      return l + r;
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
