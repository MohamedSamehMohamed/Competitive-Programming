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
const int N = 2e5+9;
int w, h, n;
int q[N][2];
int R[N], L[N], U[N], D[N];
int mxH, mxV;
int main()
{
  cin >> w >> h >> n;
  memset(L, -1, sizeof L);
  memset(R, -1, sizeof R);
  memset(U, -1, sizeof U);
  memset(D, -1, sizeof D);
  R[0] = 0;
  R[w] = 0;
  U[0] = 0;
  U[h] = 0;
  for (int i = n-1; ~i ; i--)
  {
    char c;
    cin >> c >> q[i][0];
    q[i][1] = (c == 'H' ? 0: 1);
    if (c == 'H')
    {
      U[q[i][0]] = 0;
    }else
    {
      R[q[i][0]] = 0;
    }
  }
  int lst = 0;
  for (int i = 1; i <= w; i++)
  {
    if (R[i] == 0)
    {
      L[i] = lst;
      R[lst] = i;
      mxV = max(mxV, i - lst);
      lst = i;
    }
  }
  lst = 0;
  for (int i = 1; i <= h; i++)
  {
    if (U[i] == 0)
    {
      D[i] = lst;
      U[lst] = i;
      mxH = max(mxH, i - lst);
      lst = i;
    }
  }
  stack<ll> ans;
  ans.push(1LL * mxH * mxV);
  for (int i = 0; i < n-1; i++)
  {
    if (q[i][1])
    {
      R[L[q[i][0]]] = R[q[i][0]];
      L[R[q[i][0]]] = L[q[i][0]];
      mxV = max(mxV, R[q[i][0]] - L[q[i][0]]);
    }else
    {
      U[D[q[i][0]]] = U[q[i][0]];
      D[U[q[i][0]]] = D[q[i][0]];
      mxH = max(mxH, U[q[i][0]] - D[q[i][0]]);
    }
    ans.push(1LL * mxH * mxV);
  }
  while(SZ(ans))
  {
    cout << ans.top() <<"\n";
    ans.pop();
  }
}
