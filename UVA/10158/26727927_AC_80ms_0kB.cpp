// Author : Mohamed Sameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
using namespace std ;
const int N = 2e4+9;
int n, par[N];
int get_par(int u)
{
  return u == par[u]? u: par[u] = get_par(par[u]);
}
void uni(int u, int v)
{
  u = get_par(u);
  v = get_par(v);
  if (u == v)return;
  if (u > v)swap(u, v);
  par[u] = v;
}
bool areFriends(int u, int v)
{
  return ( get_par(u) == get_par(v) )|| (get_par(u+n) == get_par(v+n));
}
bool areEnemies(int u, int v)
{
  return (get_par(u) == get_par(v+n)) || (get_par(v) == get_par(u+n));
}
void setFriends(int u, int v)
{
  if ((get_par(u) == get_par(v+n)) || (get_par(u+n) == get_par(v)))
  {
    cout <<"-1\n";return;
  }
  uni(u, v);
  uni(u+n, v+n);
}
void setEnemies(int u, int v)
{
  if ((get_par(u) == get_par(v)) || (get_par(u+n) == get_par(v+n)))
  {
    cout <<"-1\n";
    return;
  }
  uni(u, v+n);
  uni(v, u+n);
}
int main()
{
  for (int i = 0; i < N; i++)par[i] = i;
  cin >> n;n++;
  int op, x, y;
  while(cin >> op >> x >> y && (op||x||y))
  {
    switch (op) {
      case 1:
      setFriends(x, y);
      break;
      case 2:
      setEnemies(x, y);
      break;
      case 3:
      cout << areFriends(x, y) << '\n';
      break;
      case 4:
      cout << areEnemies(x, y) << '\n';
      break;
    }
  }

}
