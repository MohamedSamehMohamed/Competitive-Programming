// Author : Mohamed sameh
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
pair<int,int> st, en;
int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int cost[8][8];
string x, y;
int main()
{
  while(cin >> x >> y)
  {
    st.f = x[1] - '0' - 1;
    st.s = x[0] - 'a';
    en.f = y[1] - '0' - 1;
    en.s = y[0] - 'a';
    for (int i = 0;i < 8; i++)
      for (int j = 0; j < 8; j++)
        cost[i][j] = 100;
    queue<pair<pair<int,int>,int>> q;
    q.push({st, 0});
    cost[st.f][st.s] = 0;
    while(!q.empty())
    {
      auto cur = q.front();
      q.pop();
      if (cur.f == en)
      {
        printf("To get from %s to %s takes %d knight moves.\n", x.c_str(), y.c_str(), cur.s);
        break;
      }
      for (int i = 0; i < 8; i++)
      {
        int nx = dx[i] + cur.f.f;
        int ny = dy[i] + cur.f.s;
        if (min(nx, ny) < 0 || max(nx, ny) >= 8 || cost[nx][ny] < cur.s+1)continue;
        q.push({{nx, ny}, cur.s+1});
        cost[nx][ny] = cur.s+1;
      }
    }
  }
}
