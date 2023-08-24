
#include <bits/stdc++.h>
using namespace std;
class MedianClass
{

  priority_queue<int> l, r; 
  public: 
    int n;
    MedianClass()
    {
      n = 0; 
    }
    void add(int val)
    {
      if (l.empty() || val < l.top())
        l.push(val); 
      else 
        r.push(-val); 
      n++; 
    }
    int get_med()
    {
      if (n == 1)return l.top(); 
      int left_sz = (n+1) / 2; 
      while(l.size() < left_sz)
      {
        l.push(-r.top()); 
        r.pop(); 
      }
      while(l.size() > left_sz)
      {
        r.push(-l.top());
        l.pop(); 
      }
      return l.top(); 
    }
};