#include<bits/stdc++.h>
using namespace std;
template<typename T>  
class BST{
  struct Node{
    T val;
    int left, right; 
    Node(): val{}, left(0), right(0){}
    Node(T _val): val(_val), left(0), right(0){}
    Node(T _val, int _left, int _right): val(_val), left(_left), right(_right){}
  };
  vector<Node> nodes; 
  int root = 0;
  void insert(int& root, T val)
  {
    if (root == 0)
    {
      root = nodes.size(); 
      nodes.emplace_back(Node(val)); 
      return; 
    }
    if (nodes[root].val == val)
    {
      return; 
    }
    else if (nodes[root].val < val)
    {
      insert(nodes[root].right, val);  
    }else 
    {
      insert(nodes[root].left, val); 
    }
  }
  int find_min(int root)
  {
    while(nodes[root].left != 0)
      root = nodes[root].left; 
    return nodes[root].val; 
  }
  void erase(int& root, T val)
  {
    if (root == 0)
      return; 
    if (nodes[root].val == val)
    {
      if (nodes[root].left == 0 && nodes[root].right == 0)
      {
        root = 0;
        return;
      }
      if (nodes[root].left != 0 && nodes[root].right != 0)
      {
        int mn = find_min(nodes[root].right); 
        nodes[root].val = mn; 
        erase(nodes[root].right, mn); 
      }else 
      {
        root = (nodes[root].left != 0? nodes[root].left: nodes[root].right);
      }
    }
    else if (nodes[root].val < val)
    {
      erase(nodes[root].right, val);  
    }else 
    {
      erase(nodes[root].left, val); 
    }
  }
  bool contains(int root, T val)
  {
    if (root == 0)return 0;
    if (nodes[root].val == val)return 1; 
    if (nodes[root].val > val)
      return contains(nodes[root].left, val);
    return contains(nodes[root].right, val); 
  }
  T lower_bound(int root, T val)
  {
    if (root == 0)
    {
      // no lower bound exist 
      // for simplicity 
      return INT_MAX; 
    }
    if (nodes[root].val == val)
    {
      return val; 
    }else if (nodes[root].val < val)
      return lower_bound(nodes[root].right, val);
    else 
    {
      int lower = lower_bound(nodes[root].left, val); 
      // current root have a value > val 
      // current root is the lowerbound if the left subtree doesn't have 
      // any value >= val 
      if (lower != INT_MAX)
        return lower; 
      return nodes[root].val; 
    }
  }
  void print(int root)
  {
    if (root == 0)return; 
    print(nodes[root].left); 
    printf("%d ", nodes[root].val);
    print(nodes[root].right);
  }
  public:
    BST()
    {
      nodes.emplace_back(Node()); 
      root = 0; 
    }
    ~BST()
    {
      nodes.clear(); 
    }

    void insert(T val)
    {
      insert(root, val); 
    }
    void erase(T val)
    {
      erase(root, val); 
    }
    bool contains(T val)
    {
      return contains(root, val); 
    }
    T lower_bound(T val)
    {
      return lower_bound(root, val); 
    }
    T upper_bound(T val)
    {
      return lower_bound(root, val + T(1)); 
    } 
    void print()
    {
      print(root);
      printf("\n"); 
    }
};
int main()
{
  BST<int> st; 
  st.insert(1); 
  cout << st.contains(1) << "\n"; 
  st.erase(1); 
  cout << st.contains(1) <<"\n"; 


  for(int i = 1; i < 20; i+=3)st.insert(i);
  st.print(); 
  for(int i = 0; i < 20; i++)
  {
    cout << i <<" lowerBound: " << st.lower_bound(i) <<"\n"; 
    cout << i <<" upper bound: "<< st.upper_bound(i) <<"\n"; 
  }
}
