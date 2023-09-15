#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int n, m, q;
char s[N];
int l[N], r[N], query[N];
template <typename T>
class FenwickTree {
  public:
    vector<T> bitArray;
    int n;

    FenwickTree(int _n) : n(_n) {
      bitArray.resize(n);
    }

    void add(int x, T v) {
      while (x < n) {
          bitArray[x] += v;
          x |= (x + 1);
      }
    }
    T get(int x) {
      T v{};
      while (x >= 0) {
          v += bitArray[x];
          x = (x & (x + 1)) - 1;
      }
      return v;
    }
};
void read(){
  scanf("%d%d%d", &n, &m, &q);
  scanf(" %s", s);
  for (int i = 0; i < m; i++){
    scanf("%d%d", l+i, r+i);
    l[i]--;r[i]--;
  }
  for (int i = 0; i < q;i++){
    scanf("%d", query+i);
    query[i]--;
  }
}
void test(){
  read();
  FenwickTree<int> fen(n+1);
  int ones = 0;
  set<int> st;
  for (int i = 0; i < n; i++)
    st.insert(i);

  vector<int> needToFix;
  map<int, int> order;
  for (int i = 0; i < m; i++){
    while (l[i] <= r[i]){
      auto it = st.lower_bound(l[i]);
      if (it == st.end() || *it > r[i]) break;
      needToFix.push_back(*it);
      st.erase(*it);
      order[*it] = needToFix.size();
      l[i] = *it + 1;
    }
  }
  for(int i: st)
  {
    needToFix.push_back(i);
    order[i] = needToFix.size();
  }

  for (int i = 0; i < n; i++){
    if (s[i] == '1')
    {
      ones++;
      fen.add(order[i], 1);
    }
  }
  
  for (int i = 0; i < q; i++){
    int index = query[i];
    if (s[index] == '1'){
      ones--;
      fen.add(order[index], -1);
      s[index] = '0';
    }else {
      ones++;
      fen.add(order[index], 1);
      s[index] = '1';
    }
    int toChange = min(ones, n - (int)st.size());
    int ans = toChange -  fen.get(toChange);
    printf("%d\n", ans); 
  }
}
int main(){
  test();
}