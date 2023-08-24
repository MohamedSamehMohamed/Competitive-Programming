#include <bits/stdc++.h>
using namespace std;
void read_file()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
}
const int S = 501, inf = 300;
int age[S], answer[S], N, M, I;
vector<int> adj[S];
void solve(int u)
{
  answer[u] = inf;
  for (int& v: adj[u])
  {
    if (answer[v] == inf)
      solve(v);
    answer[u] = min(answer[u], min(age[v], answer[v]));
  }
}
void calc()
{
  for (int i = 0; i < N; i++)
    answer[i] = inf;
  for (int i = 0; i < N; i++)
    {
      if (answer[i] == inf)
        solve(i);
    }
}
void flip(int u, int v)
{
  swap(adj[u], adj[v]);
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < adj[i].size(); j++)
      if (adj[i][j] == u)
        adj[i][j] = v;
      else if (adj[i][j] == v)
        adj[i][j] = u;
  }
}
void test()
{

}
int main()
{
  read_file();
  test();
}
