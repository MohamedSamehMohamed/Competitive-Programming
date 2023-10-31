// Author : Mohamed Sameh
// created in: 2:40 PM
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int n, k, d;
int X[N], P[N];
long long min_cost_for_merge(vector<int>& idx){
  int sz = idx.size();
  vector<long long> power(sz, 0);
  multiset<long long> mst;
  int j = 0;
  for (int i = 0; i < sz; i++){
    while (j < i && X[idx[i]] - X[idx[j]] >= d){
      mst.erase(power[j++]);
    }
    power[i] += P[idx[i]];
    if (!mst.empty()){
      auto end = mst.end();
      end--;
      power[i] += *end;
    }
    mst.insert(power[i]);
  }
  return power[--sz] - P[idx[0]] - P[idx.back()];
}
void test(){
  scanf("%d%d%d", &n, &k, &d);
  for (int i = 0; i < n; i++)
    scanf("%d", X+i);
  for (int i = 0; i < n; i++)
    scanf("%d", P+i);
  vector<vector<long long>> ranges;
  for (int i = 0; i < n; i++){
    if (P[i] < 0) continue;
    long long current_power = P[i];
    int j = i + 1;
    while (j < n && X[j] - X[j-1] < d && P[j] >= 0)
    {
      current_power += P[j++];
    }
    if (current_power >= 0){
      ranges.push_back({current_power, i, j - 1});
    }
    i = j - 1;
  }
  vector<long long> values, costs;
  for (auto cur: ranges)
    values.push_back(cur[0]);
  for (int i = 1; i < ranges.size(); i++){
    int r1 = ranges[i-1][2], l2 = ranges[i][1];
    if (r1 + 1 == l2) continue;
    vector<int> idx;
    while (r1 <= l2){
      idx.push_back(r1++);
    }

    long long cost = X[l2] - X[r1] < d? 0: min_cost_for_merge(idx);
    costs.push_back(cost);
  }
  set<vector<long long>> mn1, mn2;
  for (int i = 0; i < values.size(); i++)
    mn1.insert({values[i], i});
  for (int i = 0; i < costs.size(); i++)
    mn2.insert({-costs[i], i});
  int cur = values.size();
  long long ans = 0;
  for (int i = 0; i < values.size(); i++) ans += values[i];

  set<int> merged;
  set<int> deleted;
  while (cur > k){
    long long cost1 = 1e18;
    long long cost2 = 1e18;
    int idx1 = -1, idx2 = -1;
    if (mn1.size())
    {
      auto id_mn1 = mn1.begin();
      idx1 = id_mn1->at(1);
      cost1 = id_mn1->at(0);
    }
    if (mn2.size()){
      auto id_mn2 = mn2.begin();
      idx2 = id_mn2->at(1);
      cost2 = id_mn2->at(0);
    }
    if (cost1 < cost2){
      if (merged.count(idx1)){
        // undo
        ans += cost1;
        cur++;
      }else
        deleted.insert(idx1);
      ans -= cost1;
      mn1.erase({cost1, idx1});
    }else {
      // two segments must exist know for merging
      // not handled
      int l = idx2, r = idx2+1;
      if (deleted.count(l) || deleted.count(r)){
        ans += cost2;
        cur++;
      }else {
        merged.insert(l);
        merged.insert(r);
      }
      ans -= cost2;
      mn2.erase({cost2, idx2});
    }
    cur--;
  }
  printf("%lld\n", ans);
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
/*
 * merge  ->  l1 r1   l2 r2, l1 <= r1, l2 <= r2, r1 <= l2
 * iff l2 - r1 < d -> merged with zero cost
 * otherwise find x: r1 < x < l2, l2 - x < d and x - r1 < d
 * l2 - x, x - r1  < d
 *
 */