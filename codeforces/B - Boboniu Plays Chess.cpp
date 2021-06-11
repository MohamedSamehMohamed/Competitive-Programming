// Author : Mohamed Sameh
#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define FAST ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
typedef long long ll ;
using namespace std ;
int n, m, stx, sty;
bool vis[104][104];
int vist;
vector<pair<int,int>> ans;
void Down()
{
  while(stx < n && (sty >= 1 && sty <= m))
  {
    stx++;
    if (!vis[stx][sty])
    {
      vis[stx][sty] = 1;
      ans.pb({stx, sty});
      vist++;
    }
  }
}
void UP()
{
  while(stx > 1 && (sty >= 1 && sty <= m))
  {
    stx--;
    if (!vis[stx][sty])
    {
      vis[stx][sty] = 1;
      ans.pb({stx, sty});
      vist++;
    }
  }
}
int main()
{
  cin >> n >> m >> stx >> sty;
  ans.pb({stx, sty});
  vis[stx][sty] = 1;
  while(sty > 1)
  {
    sty--;
    if (!vis[stx][sty])
    {
      ans.pb({stx, sty});
      vist++;
      vis[stx][sty] = 1;
    }
  }
  Down();
  UP();
 
  bool turn = 1;
  while(SZ(ans) != n * m){
  sty++;
  if (sty <= m &&vis[stx][sty] == 0)
  {
    vis[stx][sty] = 1;
    ans.pb({stx, sty});
  }
  if (turn){
  Down();
  }else
  {
  UP();
  }
  turn=!turn;
  }
  for (auto i: ans)
    cout << i.f <<" " << i.s <<"\n";
 
}
