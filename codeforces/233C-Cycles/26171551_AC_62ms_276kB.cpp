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
int n;
int mat[N][N];
void Set(int i, int j)
{
  mat[i][j] = mat[j][i] = 1;
}
int main()
{
  scanf("%d", &n);
  for (int i = 1;n && i < N; i++)
    {
      Set(0, i);
      for (int j = 1;n>=j && j < i; j++)
      {
        Set(i, j);
        n-=j;
      }
    }
  printf("%d\n", N);
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++)printf("%d", mat[i][j]);
    printf("\n");
  }
}
