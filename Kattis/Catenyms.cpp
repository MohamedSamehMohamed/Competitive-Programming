// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 1009, M = N*N; 
int head[N], to[M], nxt[M], ne, n; 
char x[30]; 
void init()
{
 memset(head, -1, n * sizeof head[0]); 
 ne = 0; 
}
void addEdge(int u, int v)
{
 to[ne] = v; 
 nxt[ne] = head[u];
 head[u] = ne++; 
}
void test()
{
 scanf("%d", &n);
 init(); 
 for (int i = 0; i < n; i++)
 {
  scanf(" %s", x); 
  int len = strlen(x); 
  addEdge(x[0], x[len-1]); 
 }
}
int main()
{
 int t; 
 scanf("%d", &t);
 while(t--)
  test(); 
}
