#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
char x[N];
int n;
vector<int> adj[26];
int seen[N], id;
void test()
{
  id++;
  scanf(" %s", x);
  n = strlen(x);
  for (int i = 0; i < 26; i++)adj[i].clear();
  for (int i = 0; i < n; i++)adj[x[i] - 'a'].push_back(i);
  set<int> stay;
  for (int i = 0; i < 26; i++)
  {
    if (adj[i].size() <= 1)continue;
    for (int j = 0; j < adj[i].size()-1; j++)
    {
      if (stay.lower_bound(adj[i][j]) == stay.end())
        seen[adj[i][j]] = id;
      else
        {

        }
    }
  }
}
int main()
{
 int t;
 scanf("%d", &t);
 while(t--)
  test();
}
