#include<bits/stdc++.h>
using namespace std;
class Halving
{
  set<int> diff;
  void gen(int x)
  {
    if (diff.find(x) != diff.end())return;
    diff.insert(x);
    if (x < 2)return;
    gen(x/2);
    gen((x+1)/2);
  }
  map<int, int> mp;
  int minSteps(int x, int y)
  {
    if (x == y)return 0;
    if (x < y)return 200;
    if (mp.find(x) != mp.end())return mp[x];
    mp[x] = 1 + min(minSteps(x/2, y), minSteps((x+1)/2, y));
    return mp[x];
  }
  int solve(vector<int>& a, int target)
  {
    int steps = 0;
    for (int i = 0; i < a.size(); i++)
    {
      mp.clear();
      steps += minSteps(a[i], target);
    }
    return steps;
  }
  public:
  int minSteps(vector<int> a)
  {
    int mn = a[0];
    for (int i = 0; i < a.size(); i++)
      mn = min(mn, a[i]);
    gen(mn);
    int answer = 1e9;
    for (int i: diff)
      answer = min(answer, solve(a, i));
    return answer;
  }
};
