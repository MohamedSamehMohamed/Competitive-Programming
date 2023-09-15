// Author : Mohamed Sameh
#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
typedef long long ll ;
using namespace std ;
const int N = 1e6;
int c[N], d[N];
string x;
int main()
{
  cin >> x;
  stack<int> sk;
  int n = SZ(x);
  memset(c, -1, sizeof c);
  memset(d, -1, sizeof d);
  for (int i = 0;i < n; i++)
  {
    if (x[i] == '(')sk.push(i);
    else if (!sk.empty())
    {
      c[i] = sk.top();
      sk.pop();
      d[i] = c[i];
      if (c[i] - 1 >= 0 && x[c[i] - 1] == ')' && ~d[c[i]-1])
      d[i] = d[c[i] - 1];
    }
  }
  int len = 0;
  for (int i = 0; i < n; i++)
  {
    if (~d[i])
    {
      len = max(len, i - d[i]+1);
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    if (~d[i] && i - d[i] + 1 == len)cnt++;
  }
  if (len == 0)cnt=1;
  cout << len <<" " << cnt <<"\n";
}
