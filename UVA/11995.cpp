// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 9;
int a[N][2], n; 
bool isStack()
{
 stack<int> stk;
 for (int i = 0; i < n; i++)
 {
  if (a[i][0] == 1)
   stk.push(a[i][1]); 
  else 
  {
   if (stk.empty())return 0; 
   int x = stk.top();stk.pop();
   if (x != a[i][1])return 0; 
  }
 }
 return 1; 
}
bool isQueue()
{
 queue<int> que; 
 for (int i = 0; i < n; i++)
 {
  if (a[i][0] == 1)
   que.push(a[i][1]); 
  else 
  {
   if (que.empty())return 0; 
   int x = que.front();que.pop(); 
   if (x != a[i][1])return 0; 
  }
 }
 return 1; 
}
bool isPQ()
{
 priority_queue<int> pq; 
 for (int i = 0; i < n; i++)
 {
  if (a[i][0] == 1)
   pq.push(a[i][1]); 
  else 
  {
   if (pq.empty())return 0; 
   int x = pq.top();pq.pop();
   if (x != a[i][1])return 0;
  }
 }
 return 1; 
}
int main()
{
 while(~scanf("%d", &n))
 {
  for (int i = 0; i < n; i++)
   scanf("%d%d", a[i], a[i]+1);
  bool stk = isStack();
  bool que = isQueue();
  bool pq  = isPQ(); 
  if (stk + que + pq != 1)
   printf("%s\n", (stk+que+pq > 1? "not sure": "impossible"));
  else if (stk)
   printf("stack\n");
  else if (que)
   printf("queue\n"); 
  else
   printf("priority queue\n"); 
  
 }
}
