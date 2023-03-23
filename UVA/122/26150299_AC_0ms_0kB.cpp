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
const int N = 100;
vector<pair<string,int>> adj[N];
pair<string, int> extract(string x)
{
  int num = 0;
  string pos = "";
  int i = 1;
  string tm = "";
  while (i < SZ(x) && x[i] != ',')
  {
    tm += x[i];
    i++;
  }
  i++;
  num = atoi(tm.c_str());
  while(i < SZ(x) && x[i] != ')')
  {
    pos+=x[i];
    i++;
  }
  return {pos, num};
}
bool cmp (pair<string,int> &a, pair<string,int> &b)
{
  if (a.f != b.f)return a.f < b.f ;
  return a.s < b.s;
}
int main()
{
  string x;
  while(cin >> x)
  {
    for (int i = 0; i < N; i++)adj[i].clear();
    if (x == "()")
    {
      cout <<"not complete\n";
      continue;
    }
    pair<string,int> cur = extract(x);
    adj[ SZ(cur.f) ].pb(cur);
    while(cin >> x && x != "()")
    {
      cur = extract(x);
      adj[ SZ(cur.f) ].pb(cur);
    }
    bool ok = 1;
    for (int i = 0; i < N; i++)
    {
      sort(all(adj[i]), cmp);
      for (int j = 0 ; j < SZ(adj[i]); j++)
        for (int k = j+1; k < SZ(adj[i]); k++)
          if (adj[i][j].f == adj[i][k].f)ok=0;
    }
    for (int i = 0; ok && i < N; i++)
    {
      if (SZ(adj[i]))continue;
      for (int j = i+1;ok && j < N; j++)
        if (SZ(adj[j]))ok=0;
    }
    if (!ok)
    {
      cout <<"not complete\n";
      continue;
    }
    cout << adj[0][0].s ;
    for (int i =1; i < N; i++)
    {
      for (int j = 0; j < SZ(adj[i]); j++)
      cout << " " << adj[i][j].s;
    }
    cout <<"\n";


  }
}
