// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
priority_queue<int> odd, even;
long long Ascore, Bscore;
void Atake(bool ok = 1)
{
  Ascore += ok * even.top();
  even.pop();
}
void Btake(bool ok = 1)
{
  Bscore += ok * odd.top();
  odd.pop();
}
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
      if (x % 2)
        odd.push(x);
      else
        even.push(x);
    }
    bool alice = 1;
    Ascore = Bscore = 0;
    while(!even.empty() || !odd.empty())
    {
      if (alice)
      {
        if (odd.empty() || (!even.empty() && (even.top() - odd.top()) > 0))
          Atake();
        else
          Btake(0);
      }else
      {
        if (even.empty() || (!odd.empty() && (odd.top() - even.top()) > 0))
          Btake();
        else
          Atake(0);
      }
      alice ^= 1;
    }
    
    if (Ascore > Bscore)
      printf("Alice\n");
    else if (Ascore < Bscore)
      printf("Bob\n");
    else
      printf("Tie\n");
  }
}
