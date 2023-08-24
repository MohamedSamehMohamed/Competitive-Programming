#include<bits/stdc++.h>
using namespace std; 

const int N = 100, M = 100; 

struct bit2D
{
  // N row, M col 
  int tree[N][M];
  void init()
  {
      memset(tree, 0, sizeof tree);
  }
  int get(int i, int j)
  {
      int  ret = 0;
      for(i++ ; i ; i -= (i & (-i)))
      {
          for(int jj = j + 1 ; jj ; jj -= (jj & (-jj)))
          {
              ret = (ret + tree[i - 1][jj - 1]); 
          }
      }
      return ret;
  }
  void add(int i, int j, int  val)
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
}_2bit;