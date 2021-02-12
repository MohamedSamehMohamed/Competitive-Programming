// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
int f, s, g, u, d;
int dist[N];
int main()
{
 scanf("%d%d%d%d%d", &f, &s, &g, &u, &d);
 queue<int> q;
 q.push(s);
 memset(dist, -1, sizeof dist); 
 int ans = -1;
 dist[s] = 0;
 while(!q.empty())
 {
  int cur = q.front();
  q.pop();
  if (cur == g)
  {
   ans = dist[cur];
   break;
  }
  int up = cur + u;
  int down = cur - d);
  if (up <= f && dist[up] == -1)
  {
   dist[up] = dist[cur] + 1;
   q.push(up); 
  }
  if (down > 0 && dist[down] == -1)
  {
   dist[down] = dist[cur] + 1;
   q.push(down); 
  }
 }
 // s --> x 
 // s <= x 
 // d = x-s 
 // d = a*u - b*d
 if (ans != -1)
  printf("%d\n", ans); 
 else 
  printf("use the stairs\n");
}
