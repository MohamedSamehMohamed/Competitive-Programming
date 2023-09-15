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
const int N = 301;
int a[N], n, F, S;
vector<int> v[3];
int input[N][2];
int seen[N];
vector<int> vec;
void Fill(int l, int r)
{
  vec.clear();
  for (int i = l; i <= r; i++)if (!seen[i])vec.pb(a[i]);
  sort(all(vec),[](int u, int v){
    return u < v;
  });
}
ll ans = 0;
void solve(int l, int r, vector<int> moveA)
{
  // cout <<"START\n";
  Fill(l, r);
  l = 0, r = SZ(vec)-1;
  // for (int i : vec)cout << i <<" ";
  // cout <<"\n";
  for (auto i: moveA)
  {
    // cout << i <<" " << vec[l] << " " << vec[r] <<"\n";
    if (i <= vec[l] || i > vec[r])
    {
      if (i > vec[l])ans += i;
      l++;
    }else
    {
      r--;
    }
    // cout << l <<" " << r <<"\n";
  }
  // cout <<"end\n";
}
int main()
{
  freopen("fans.in", "r", stdin);
  freopen("fans.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> input[i][0] >> input[i][1];
    a[i] = input[i][0];
    F += (input[i][1] == 1);
    S += (input[i][1] == 2);
  }
  vector<int> moveA, moveB, moveC;
  for (int i = 1; i <= n; i++)
  {
    if (input[i][1] == 1)
    {
      if (i > F)moveA.pb(a[i]);
      else seen[i] = 1;
    }else if (input[i][1] == 2)
    {
      if (i < n - S + 1)moveB.pb(a[i]);
      else seen[i] = 1;
    }else
    {
      if (i <= F || i >= n - S + 1)moveC.pb(a[i]);
      else seen[i] = 1;
    }
  }
  sort(all(moveA),[](int u, int v){return u > v;});
  sort(all(moveB),[](int u, int v){return u > v;});
  sort(all(moveC),[](int u, int v){return u > v;});
  solve(1, F, moveA);
  solve(F+1, n - S, moveC);
  solve(n-S+1, n, moveB);
  cout << ans << '\n';


}
