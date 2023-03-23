// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int n, s; 
int B[N], S[N]; 
int main()
{
 scanf("%d%d", &n, &s); 
 for (int i = 0; i < n; i++)
 {
  char c;
  int p, q; 
  scanf(" %c%d%d", &c, &p, &q); 
  if (c == 'B')
  B[p] += q; 
  else 
  S[p] += q;
 }
 stack<int> tk; 
 for (int i = 0; tk.size() != s && i < N; i++)
 {
  if (S[i])
  {
   tk.push(i); 
  }
 }
 while(!tk.empty())
 {
  int i = tk.top();tk.pop();
  printf("S %d %d\n", i, S[i]); 
 }
 for (int i = N-1, c = 0; c != s && ~i; i--)
 {
  if (B[i])
  {
   c++;
   printf("B %d %d\n", i, B[i]); 
  }
 }
}
