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
const int N = 1e5;
int a[N];
int ans[N];
void test(int n)
{
  for (int i = 0; i < (1<<n); i++)
  {
    int cur = 0;
    for (int j = 0; j < n; j++)
    {
      if (  (i & (1<<j)) ) ans[cur++] = a[j];
    }
    if (cur < 2)continue;
    for (int j = 0; j < cur; j++)cout << ans[j] <<" ";
    cout <<"::";
    int sum =0;
    for (int j =0; j +1 < cur; j++)sum += abs(ans[j] - ans[j+1]);
    cout << sum <<"\n";
  }
}
int n;
void sol()
{
  int lst = 0;
  int an = 0;
  for (int i = 1; i + 1 < n; i++)
  {
    int cur = abs(a[lst] - a[i+1]);
    int with = abs(a[lst] - a[i]) + abs(a[i] - a[i+1]);
    if (cur == with)
    {
      an++;
      a[i] = 0;
    }else
    lst = i;
  }
  printf("%d\n", n - an);
  for (int i = 0; i < n; i++)
  {
    if (a[i])printf("%d ", a[i]);
  }
  printf("\n");
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
      scanf("%d", &n);
      for (int i = 0; i < n; i++)
      {
        scanf("%d", a+i);
      }
      sol();
    }
}
