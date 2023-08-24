#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
char x[N];
int n, q;
set<int> adj[26];
int main()
{
  scanf(" %s", x);
  n = strlen(x);
  for (int i = 0; i < n; i++)adj[x[i]-'a'].insert(i);
  stack<int> lst;
  lst.push(-1);
  scanf("%d", &q);
  while(q--)
  {
    scanf(" %s", x);
    if (x[1] == 'u')
    {
     scanf(" %s", x);
     auto it = adj[x[0]-'a'].lower_bound(lst.top() + 1);
     if (it == adj[x[0]-'a'].end())
      lst.push(n);
    else
      lst.push(*it);
    }else
    {
      lst.pop();
    }
    if (lst.top() != n)
      printf("YES\n");
    else
      printf("NO\n");
  }
}
