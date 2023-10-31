// Author : Mohamed Sameh
// created in: 10:34 AM
#include <bits/stdc++.h>
using namespace std;
template <typename T, class F = function<T(const T&, const T&)>>
class SparseTable {
public:
  int n;
  vector<vector<T>> mat;
  F func;
  SparseTable(const vector<T>& a, const F& f) : func(f) {
    n = static_cast<int>(a.size());
    int max_log = 32 - __builtin_clz(n);
    mat.resize(max_log);
    mat[0] = a;
    for (int j = 1; j < max_log; j++) {
      mat[j].resize(n - (1 << j) + 1);
      for (int i = 0; i <= n - (1 << j); i++) {
        mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
      }
    }
  }

  T get(int from, int to) const {
    assert(0 <= from && from <= to && to <= n - 1);
    int lg = 32 - __builtin_clz(to - from + 1) - 1;
    return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
  }
};

void merge(vector<vector<int>>& ranges){
  sort(ranges.begin(), ranges.end());
  stack<vector<int>> stk;
  stk.push({ranges[0][0], ranges[0][1], ranges[0][2]});
  for (int i = 1; i < ranges.size(); i++){
    if (ranges[i][0] <= stk.top()[1]){
      stk.top()[1] = max(stk.top()[1], ranges[i][1]);
      stk.top()[2] = max(stk.top()[2], ranges[i][3]);
    }else
      stk.push({ranges[i][0], ranges[i][1], ranges[i][2]});
  }
  int idx = 0;
  while (!stk.empty()){
    ranges[idx++] = stk.top();
    stk.pop();
  }
  ranges.erase(ranges.begin() + idx, ranges.end());
}
void get_max(vector<vector<int>>& range, int& st){
  int l = 0, r = range.size()-1, m, idx = -1;
  while (l <= r){
    m = (l+r) >> 1;
    if (st >= range[m][0] && st <= range[m][1]){
      idx = m;
      r = m - 1;
    }else{
      if (st > range[m][1])
        l = m + 1;
      else
        r = m - 1;
    }
  }
  if (idx == -1) return;
  st = max(st, range[idx][2]);
}
void test(){
  int n;
  scanf("%d" ,&n);
  vector<vector<int>> can_go_range, first_time_range;
  for (int i = 0; i < n; i++){
    int l, r, a, b;
    scanf("%d%d%d%d", &l, &r, &a, &b);
    can_go_range.push_back({a, b, b});
    first_time_range.push_back({l, b, b});
  }
  merge(can_go_range);
  sort(first_time_range.begin(), first_time_range.end());
  vector<int> a;
  for (int i = 0; i < first_time_range.size(); i++)
    a.push_back(first_time_range[i][2]);
  SparseTable<int> st(a,[&](int i, int j){return max(i, j); });
  auto get_max_from_start = [&](int st){
    int l = 0, r = first_time_range.size()-1, m, L = -1, R = -1;
    while (l <= r){
      m = (l+r) >> 1;
      if (st >= first_time_range[m][0]){
        L = m;
        r = m - 1;
      }else {
        l = m + 1;
      }
    }
    if (L == -1) return st;

    return st;
  };
  int q;
  scanf("%d", &q);
  while (q--){
    int st;
    scanf("%d", &st);
    st = get_max_from_start(st);
    get_max(can_go_range, st);
    printf("%d ", st);
  }
  printf("\n");
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}