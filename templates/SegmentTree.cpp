// includes
#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Node{
  public:
    T val;
    bool ignore;
    Node(T val){
      this->val = val;
      ignore = false;
    }
    Node(bool ignore){
      this->ignore = ignore;
    }
};

template<typename T>
Node<T> operator+(Node<T>& l, Node<T>& r){
  if (l.ignore && r.ignore)
    return l;
  if (l.ignore) return r;
  if (r.ignore) return l;
  Node<T> ret = Node<T>(max(l.val, r.val));
  return ret;
}

template<typename T>
class SegmentTree{
  vector<Node<T>> nodes;
  int n;
  void set_size(int _n){
    n = 1;
    while (n < _n)
      n *= 2;
  }
  void update(int node, int l, int r, int index, T val){
    if (index < l || index > r) return;
    if (l == r){
      nodes[node] = Node<T>(val);
      return;
    }
    int m = (l+r) >> 1;
    update(node * 2 + 1, l, m, index, val);
    update(node * 2 + 2, m+1, r, index, val);
    nodes[node] = nodes[node * 2 + 1] + nodes[node * 2 + 2];
  }
  Node<T> query(int node, int l, int r, int left, int right){
    if (left > r || right < l)
      return Node<T>(true);
    if (l >= left && r <= right)
      return nodes[node];
    int m = (l+r) >> 1;
    return
    query(node * 2 + 1, l, m, left, right) +
    query(node * 2 + 2, m+1, r, left, right);
  }
  public:
    SegmentTree(int _n){
      set_size(_n);
    }
    SegmentTree(int _n, vector<int>& a): SegmentTree(_n){
      build(0, 0, n-1, a);
    }
    void build(int node, int l, int r, vector<T>& a){
      if (l == r){
        nodes[node] = Node<T>(a[l]);
        return;
      }
      int m = (l+r) >> 1;
      build(node * 2 + 1, l, m, a);
      build(node * 2 + 2, m+1, r, a);
      nodes[node] = nodes[node * 2 + 1] + nodes[node * 2 + 2];
    }
    void update(int index, T val){
      update(0, 0, n-1, index, val);
    }
    Node<T> query(int l, int r){

    }
  };