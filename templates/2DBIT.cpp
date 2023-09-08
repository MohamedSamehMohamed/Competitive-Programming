#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Fenwick2D
{
  int N, M;
  vector<vector<T>> tree;
public:
  Fenwick2D(int row, int col){
    N = row;
    M = col;
    tree = vector<vector<T>> (N);
    for (int i = 0; i < N; i++){
      tree[i] = vector<T>(M, {});
    }
  }
  T get(int i, int j)
  {
      T  ret = 0;
      for(i++ ; i ; i -= (i & (-i)))
      {
          for(int jj = j + 1 ; jj ; jj -= (jj & (-jj)))
          {
              ret = (ret + tree[i - 1][jj - 1]); 
          }
      }
      return ret;
  }
  void add(int i, int j, T  val)
  {
      for(i++ ; i <= N ; i += (i & (-i)))
      {
          for(int jj = j + 1 ; jj <= M ; jj += (jj & (-jj)))
          {
              tree[i - 1][jj - 1] = (tree[i - 1][jj - 1]+ val); 
          }
      }
  }
  int  get(int si, int sj, int ei, int ej)
  {
      return get(ei, ej) - get(ei, sj - 1) - get(si - 1, ej) + get(si - 1, sj - 1);
  }
};
int main(){
  Fenwick2D<int> fen(10, 10);
  fen.add(5, 5, 1);
  printf("%d\n", fen.get(9, 9));
}