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
};
int main()
{
  BST<int> st; 
  st.insert(1); 
  cout << st.contains(1) << "\n"; 
  st.erase(1); 
  cout << st.contains(1) <<"\n"; 
}
