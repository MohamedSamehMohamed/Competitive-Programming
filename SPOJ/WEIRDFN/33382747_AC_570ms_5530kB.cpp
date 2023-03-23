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

int main()
{
  int t;scanf("%d", &t);
  while (t--)
  {
    MedianClass C; 
    int a, b, c, n, f, mod = 1e9 + 7; 
    f = 1; 
    C.add(1); 
    scanf("%d%d%d%d", &a, &b, &c, &n);
    long long sum = 1;
    for(int i = 1; i < n; i++)
    {
      int m = C.get_med(); 
      f = (1LL * a * m + 1LL * b * (i+1) + c) % mod; 
      sum += f; 
      C.add(f); 
    }
    printf("%lld\n", sum);
  }
}
