// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
const int N = 2e5 + 9;
int tem[N], n, m;
void test()
{
  scanf("%d%d", &n, &m);
  priority_queue<int> pq[3];
  for (int i = 0; i < n; i++)
    scanf("%d", tem+i);
  for (int i = 0; i < n; i++)
  {
    int ty;
    scanf("%d", &ty);
    pq[ty].push(tem[i]);
  }
  int mn = 0;
  while(m > 0 && (!pq[1].empty()||!pq[2].empty()))
  {
    if (pq[1].empty())
    {
      mn+=2;
      m -= pq[2].top();
      pq[2].pop();
    }else if (pq[2].empty())
    {
      mn++;
      m -= pq[1].top();
      pq[1].pop();
    }else
    {
      if ( (pq[1].top() >= m) ||(pq[1].top() >= pq[2].top()))
      {
        mn++;
        m -= pq[1].top();
        pq[1].pop();
      }else
      {
        if (pq[1].size() > 1)
        {
          int x = pq[1].top();pq[1].pop();
          int y = pq[1].top();pq[1].pop();
          if (x+y >= pq[2].top())
          {
            mn++;
            m -= x;
            pq[1].push(y);
          }else
          {
            pq[1].push(x);
            pq[1].push(y);
            m -= pq[2].top();pq[2].pop();
            mn+=2;
          }
        }else
        {
          m -= pq[2].top();
          pq[2].pop();
          mn+=2;
        }
      }
    }
  }
  if (m > 0)mn = -1;
  printf("%d\n", mn);
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
