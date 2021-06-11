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
const int N = 2e5 + 9;
priority_queue<ll> pq;
ll ans[N][2];
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
  {
    int n;
    scanf("%d", &n);
    while(!pq.empty())pq.pop();
    for (int i = 1; i <= n; i++)pq.push(i);
    n--;
    int idx = 0;
    while(n--)
    {
      ll num1 = pq.top();
      pq.pop();
      ll num2 = pq.top();
      pq.pop();
      ans[idx][0] = num1;
      ans[idx][1] = num2;
      idx++;
      pq.push((num1+ num2+1)/2);
    }
    printf("%lld\n", pq.top());
    for (int i = 0; i < idx; i++)
      printf("%lld %lld\n", ans[i][0], ans[i][1]);
  }
}
