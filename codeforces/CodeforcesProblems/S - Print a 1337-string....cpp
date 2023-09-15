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
string str = "1337";
int arr[4];
int n;
void Print()
{
  int len = 0;
  for (int i = 0; i < 4; i++)
  {
    while(arr[i])
    {
      ll rm = (1LL*arr[i] * (arr[i]-1))/2;
      while (n && i == 2 && rm > 0 && rm <= n)
      {
        //cout << n <<" " << rm <<" " << arr[i] <<"\n";
        len++;
        cout << 1;
        n-=rm;
      }
      len++;
      cout << str[i];
      arr[i]--;
    }
  }
  cout <<"\n";
  //cout << len <<"\n";
}
int main()
{
  FAST
  int t;
  scanf("%d", &t);
  int Mx = 1e5;
  while (t--)
  {
    memset(arr, 0, sizeof arr);
    scanf("%d", &n);
    if (n + 3 <= Mx)
    {
      arr[0] = n;
      arr[1] = arr[2] = arr[3] = 1;
      n = 0;
      Print();
      continue;
    }
    ll l = 2, r = 1e7, m, ans = -1;
    while (l <= r)
    {
      m = (l+r)>>1LL;
      ll cur = (m * (m-1))/2;
      if (cur <= n)
      {
        ans = m;
        l = m+1;
      }else
      r = m-1;
    }
    ll cur = (ans * (ans-1))/2;
    arr[2] = ans - 1;
    arr[1] = 1;
    arr[0] = 1;
    arr[3] = 1;
    n-=cur;
    Print();
    //cout << n <<"v\n";
  }
}
