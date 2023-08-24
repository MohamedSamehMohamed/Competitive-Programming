#include<bits/stdc++.h>
using namespace std; 
const int N = 1e5 + 9; 

struct BIT
{
    int tree[N];
    void init()
    {
        memset(tree, 0, sizeof tree);
    }
    void add(int pos, int val)
    {
        for(++pos ; pos <= N ; pos += (pos & (-pos))) tree[pos - 1] += val;
    }
    int get(int pos)
    {
        int ret = 0;
        for(++pos ; pos ; pos -= (pos & (-pos))) ret += tree[pos - 1];
        return ret;
    }
}bit;


template <typename T>
class FenwickTree {
  public:
    vector<T> bitArray;
    int n;

    FenwickTree(int _n) : n(_n) {
      bitArray.resize(n);
    }

    void add(int x, T v) {
      while (x < n) {
          bitArray[x] += v;
          x |= (x + 1);
      }
    }

    T get(int x) {
      T v{};
      while (x >= 0) {
          v += bitArray[x];
          x = (x & (x + 1)) - 1;
      }
      return v;
    }
    T kth(int k) {
      // 1 based 
      T v{};
      int l = 0, r = n-1, m;
      while (l <= r)
      {
        m = (l+r) >> 1;
        if (get(m) > k)
          r = m - 1; 
        else 
          l = m + 1, v = m; 
      }
      return v; 
    }
};
