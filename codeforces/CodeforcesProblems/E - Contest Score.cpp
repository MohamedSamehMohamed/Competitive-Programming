// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std ;
int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  priority_queue<int> pq;
  for (int i = 0; i < m; i++)
    pq.push(-v[i]);
  long long ans = 0;
  int cur = 0;
  while(m < n)
  {
    int curT = -pq.top();
    pq.pop();
    pq.push(-v[m]);
    m++;
    cur += curT;
    ans += cur;
  }
  while(!pq.empty())
  {
    int curT = -pq.top();
    pq.pop();
    cur += curT;
    ans += cur;
  }
  cout << ans << '\n';
}
