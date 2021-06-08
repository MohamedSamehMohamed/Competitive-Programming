#include<bits/stdc++.h>
using namespace std;
int n;
string x;
int frq[26];
void test()
{
  cin >> n >> x;
  memset(frq, 0, sizeof frq);
  bool ok = 1;
  for (int i = 0; i < n; i++)
  {
    if (frq[x[i] - 'A'])
    {
      ok = 0;break;
    }
    int j = i+1;
    while(j < n && x[j] == x[j-1])
      j++;
    frq[x[i] - 'A'] = 1;
    i = j-1;
  }
  if (ok)
    cout <<"YES\n";
  else
    cout <<"NO\n";
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
