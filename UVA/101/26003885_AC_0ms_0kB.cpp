// Author : Mohamed Sameh
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
stack<int> sk[30];
int StackN[30];
int n;
bool valid (int a, int b)
{
  if (a == b || StackN[a] == StackN[b])return 0;
  return 1;
}
void C1(int a, int b)
{
  int sa = StackN[a];
  int sb = StackN[b];
  vector<pair<int,int>> v;
  v.pb({sa, a});
  v.pb({sb, b});
  for (auto i : v){
    while (!sk[i.f].empty() && sk[i.f].top() != i.s)
    {
      int cur = sk[i.f].top();
      sk[i.f].pop();
      sk[cur].push(cur);
      StackN[cur] = cur;
    }
}
if (!sk[sa].empty())
sk[sa].pop();
sk[sb].push(a);
StackN[a] = sb;
}
void C2(int a, int b)
{
  int sa = StackN[a];
  while (!sk[sa].empty() && sk[sa].top() != a)
  {
    int cur = sk[sa].top();
    sk[sa].pop();
    sk[cur].push(cur);
    StackN[cur] = cur;
  }
  int sb = StackN[b];
  if (!sk[sa].empty())
  sk[sa].pop();
  sk[sb].push(a);
  StackN[a] = sb;
}
void C3(int a, int b)
{
  int sb = StackN[b];
  while (!sk[sb].empty() && sk[sb].top() != b)
  {
    int cur = sk[sb].top();
    sk[sb].pop();
    sk[cur].push(cur);
    StackN[cur] = cur;
  }
  int sa = StackN[a];
  stack<int> tsk;
  while(!sk[sa].empty() && sk[sa].top() != a)
  {
    tsk.push(sk[sa].top());
    sk[sa].pop();
  }
  if (!sk[sa].empty())
  {
    tsk.push(sk[sa].top());
    sk[sa].pop();
  }
  while (!tsk.empty())
  {
    int cur = tsk.top();
    sk[sb].push(cur);
    StackN[cur] = sb;
    tsk.pop();
  }
}
void C4(int a, int b)
{
  int sa = StackN[a];
  int sb = StackN[b];
  stack<int> tsk;
  while(!sk[sa].empty() && sk[sa].top() != a)
  {
    tsk.push(sk[sa].top());
    sk[sa].pop();
  }
  if (!sk[sa].empty())
  {
    tsk.push(sk[sa].top());
    sk[sa].pop();
  }
  while (!tsk.empty())
  {
    int cur = tsk.top();
    sk[sb].push(cur);
    StackN[cur] = sb;
    tsk.pop();
  }
}
void Print()
{
  stack<int> tem[30];
  for (int i = 0; i < n; i++)
  {
    tem[i] = sk[i];
  }
  stack<int> tsk;
  for (int i = 0; i < n; i++)
  {
    cout << i <<":";
    if (SZ(tem[i]) == 0)
    {
      cout <<"\n";
      continue;
    }
    while (!tem[i].empty())
    {
      tsk.push(tem[i].top());
      tem[i].pop();
    }
    while (!tsk.empty())
    {
      cout <<" ";
      cout << tsk.top();
      tsk.pop();
    }
    cout <<"\n";
  }
}
int main()
{
  cin >> n;
  for (int i = 0; i < n; i++){
    sk[i].push(i);
    StackN[i] = i;
  }
  string x, y;
  while (cin >> x && x != "quit")
  {
    int a, b;
    cin >> a >> y >> b;
    x += y;
    if (!valid(a, b))continue;
    if (x == "moveonto")
    {
      C1(a, b);
    }else if (x == "moveover")
    {
      C2(a, b);
    }else if (x == "pileonto")
    {
      C3(a, b);
    }else
    {
      C4(a, b);
    }
    //Print();
  }
  Print();
}
