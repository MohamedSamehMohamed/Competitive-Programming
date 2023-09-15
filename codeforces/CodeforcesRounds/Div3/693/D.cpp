// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
priority_queue<int> pq;
long long sum;
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
  {
    int n;scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
      int x;
      scanf("%d", &x);
      pq.push(x);
    }
    sum = 0;
    for (int i = 0; i < n; i++)
    {
      int x = pq.top();pq.pop();
      sum += (i % 2? -x * (x%2): x * (x%2==0)); 
    }
    if (sum > 0)
      printf("Alice\n");
    else if (sum < 0)
      printf("Bob\n");
    else
      printf("Tie\n");
  }
}
