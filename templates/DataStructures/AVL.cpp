#include<bits/stdc++.h>
using namespace std;
template<typename T>  
class AVL{
  struct Node{
    T val;
    int height = -1; 
    int left = 0, right = 0; 
    Node(): val{}{}
    Node(T _val): val(_val){}
    Node(T _val, int _left, int _right): val(_val), left(_left), right(_right){}
  };
  static const int ALLOWED_IMBALANCE = 1;
  vector<Node> nodes; 
  int root = 0;
  int height(int root)
  {
    assert(root >= 0 && root < nodes.size()); 
    return nodes[root].height; 
  }
  void single_rotate(int& root, int dir)
  {
    assert(root >= 0 && root < nodes.size()); 
    if (dir == 0)
    {
      int temp = nodes[root].left; 
      assert(temp >= 0 && temp < nodes.size()); 
      nodes[root].left = nodes[temp].right; 
      nodes[temp].right = root; 
      nodes[root].height = max(height(nodes[root].left), height(nodes[root].right)) + 1;
      nodes[temp].height = max(height(nodes[temp].left), nodes[root].height) + 1; 
      root = temp;
    }else 
    {
      int temp = nodes[root].right; 
      assert(temp >= 0 && temp < nodes.size()); 
      nodes[root].right = nodes[temp].left; 
      nodes[temp].left = root; 
      nodes[root].height = max(height(nodes[root].left), height(nodes[root].right)) + 1;
      nodes[temp].height = max(height(nodes[temp].right), nodes[root].height) + 1; 
      root = temp;
    }
     
  }
  void double_rotate(int& root, int dir)
  {
    assert(root >= 0 && root < nodes.size()); 
    if (dir == 0)
    {
      single_rotate(nodes[root].left, 1); 
      single_rotate(root, 0); 
    }else 
    {
      single_rotate(nodes[root].right, 0); 
      single_rotate(root, 1); 
    }
  }
  void balance(int& root)
  {
    if (root == 0)return; 
    assert(root >= 0 && root < nodes.size());
    if (height(nodes[root].left) - height(nodes[root].right) > ALLOWED_IMBALANCE)
    {
      if (height(nodes[nodes[root].left].left) >= height(nodes[nodes[root].left].right))
        single_rotate(root, 0); 
      else 
        double_rotate(root, 0); 
    }else if (height(nodes[root].right) - height(nodes[root].left) > ALLOWED_IMBALANCE) 
    {
      if (height(nodes[nodes[root].right].right) >= height(nodes[nodes[root].right].left))
        single_rotate(root, 1); 
      else 
        double_rotate(root, 1); 
    }
    nodes[root].height = max(height(nodes[root].left), height(nodes[root].right)) + 1; 
  }
  void insert(int& root, T val)
  {
    assert(root >= 0 && root < nodes.size()); 
    if (root == 0)
    {
      root = nodes.size(); 
      nodes.emplace_back(Node(val)); 
      return; 
    }
    if (nodes[root].val < val)
    {
      insert(nodes[root].right, val);  
    }else if (nodes[root].val > val) 
    {
      insert(nodes[root].left, val); 
    }
    balance(root);
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
      }
      else if (nodes[root].left != 0 && nodes[root].right != 0)
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
    balance(root);
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
  int get_max_height(int root)
  {
    if (root == 0)return 0;
    return 1 + max(get_max_height(nodes[root].left), get_max_height(nodes[root].right));
  }
  public:
    AVL()
    {
      nodes.emplace_back(Node()); 
      root = 0; 
    }
    ~AVL()
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
    int MAX()
    {
      return get_max_height(root); 
    }
};
int main()
{
  AVL<int> avl;
  for(int i = 0; i < (int)1e6; i++)
    avl.insert(i);
  cout << avl.MAX() <<"\n";
}