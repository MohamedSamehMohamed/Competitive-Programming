// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
long long pre[N], tem[N]; 
// add range start with value st
// st, st+add, st + 2 * add, st + 3 * add, ..., st + (r-l)*add
// final values in pre array 
void addRange(int l, int r, int st, int add)
{
 pre[l] += st;
 pre[r+1] -= st + (r-l)*add;
 tem[l+1] += add;
 tem[r+1] -= add;  
}
int main()
{
 int q;scanf("%d", &q);
 while(q--)
 {
  int l, r, st, add; 
  scanf("%d%d%d%d", &l, &r, &st, &add); 
  addRange(l, r, st, add); 
 }
 long long add = tem[0];
 for (int i = 1; i < N; i++)
 {
  add += tem[i];
  pre[i] += pre[i-1] + add; 
 }
}
