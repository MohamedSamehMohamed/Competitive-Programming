// Author : Mohamed Sameh
// created in: 5:47 PM
#include <bits/stdc++.h>
using namespace std;
class Trie{
public:
  Trie(){
    next = vector<int>(2, -1);
    cnt = vector<int> (2, 0);
    isLeaf = 0;
  }
  vector<int> next;
  vector<int> cnt;
  int isLeaf;
};
const int N = 2e5 + 9;
int n, k, a[N];
vector<Trie> T;
void add(int number){
  int index = 0;
  for (int i = k-1; i >= 0; i--){
    int p = (number & (1<<i)) != 0;
    if (T[index].next[p] == -1){
      T.push_back(Trie());
      T[index].next[p] = T.size() - 1;
    }
    T[index].cnt[p]++;
    index = T[index].next[p];
  }
  T[index].isLeaf++;
}
void del(int number){
  int index = 0;
  for (int i = k-1; i >= 0; i--){
    int p = (number & (1<<i)) != 0;
    T[index].cnt[p]--;
    index = T[index].next[p];
  }
  T[index].isLeaf--;
}
vector<long long> solve(int number){
  int x = 0;
  int num = 0;
  int index = 0;
  long long val = 0;
  for (int i = k-1; i >= 0; i--){
    int p = (number & (1<<i)) != 0;
    if (p){
      if (T[index].cnt[p] > 0){
        index = T[index].next[p];
        val |= (1<<i);
        num |= (1<<i);
      }else {
        index = T[index].next[p^1];
      }
    }else {
      if (T[index].cnt[p] > 0){
        index = T[index].next[p];
        val |= (1<<i);
        x |= (1<<i);
      }else {
        num |= (1<<i);
        index = T[index].next[p^1];
      }
    }
  }
  return {val, num, x};
}
void test(){
  scanf("%d%d", &n, &k);
  T.clear();
  T.push_back(Trie());
  for (int i = 0; i < n; i++){
    scanf("%d", a+i);
    add(a[i]);
  }
  long long mx = -1;
  int id1, id2, x;
  int num1, num2;
  for (int i = 0; i < n; i++){
    del(a[i]);
    auto cur = solve(a[i]);
    if (cur[0] > mx){
      mx = cur[0];
      num1 = a[i];
      num2 = cur[1];
      x = cur[2];
    }
    add(a[i]);
  }
  id1 = id2 = -1;
  for (int i = 0; i < n; i++){
    if (a[i] == num1 && id1 == -1)
      id1 = i + 1;
    else if (a[i] == num2 && id2 == -1)
      id2 = i + 1;
  }
  printf("%d %d %d\n", id1, id2, x);
}
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}