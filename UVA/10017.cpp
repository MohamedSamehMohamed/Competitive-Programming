#include<bits/stdc++.h>
using namespace std;
int n, m; 
deque<int> dq[3]; 
void Print()
{
 if (!m)return; 
 m--; 
 for (int i = 0; i < 3; i++)
 {
  printf("%c=>", 'A'+i); 
  if (dq[i].empty())
  {
   printf("\n");
   continue; 
  }
  printf("   "); 
  int sz = dq[i].size(); 
  while(sz--)
  {
   printf("%d", dq[i].front()); 
   int temp = dq[i].front(); 
   dq[i].pop_front(); 
   dq[i].push_back(temp); 
   printf("%c", (sz == 0? '\n': ' '));  
  }
 }
 printf("\n"); 
}
void move(int from, int to)
{
 if (!m)return; 
 int temp = dq[from].back();
 dq[from].pop_back(); 
 dq[to].push_back(temp); 
 Print(); 
}
void solve(int rem = n, int from = 0, int buffer = 1, int to = 2)
{
 if (!m)return; 
 if (rem == 1)
 {
  move(from, to);
  return;
 }
 solve(rem-1, from, to, buffer);
 move(from, to);   
 solve(rem-1, buffer, from, to); 
}
void test()
{
 for (int i = 0; i < 3; i++)dq[i].clear(); 
 for (int i = n; i > 0; i--)dq[0].push_back(i);
 m++; 
 Print();  
 solve(); 
}
int main()
{
 int t = 1; 
 while(scanf("%d%d", &n, &m) && (n||m))
 {
  printf("Problem #%d\n\n", t++);
  test(); 
 }
}
