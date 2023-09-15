// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int a[N], n;
queue<int> nxt[N]; 
int main()
{
 scanf("%d", &n);
 for (int i = 0; i < n; i++)
  scanf("%d", a+i), nxt[a[i]].push(i);
 int ans = 0; 
 int lst1, lst2;
 lst1 = lst2 = 0;
 for (int i = 0; i < n; i++)
 {
  if (lst1 == lst2 && a[i] == lst1)continue; 
  if (a[i] == lst1)
   ans += (a[i] != lst2), lst2 = a[i];
  else if (a[i] == lst2)
   ans += (a[i] != lst1), lst1 = a[i]; 
  else 
  {
   while(!nxt[lst1].empty() && nxt[lst1].front() <= i)nxt[lst1].pop(); 
   while(!nxt[lst2].empty() && nxt[lst2].front() <= i)nxt[lst2].pop();
   int nxt1 = (nxt[lst1].empty()? n: nxt[lst1].front());
   int nxt2 = (nxt[lst2].empty()? n: nxt[lst2].front()); 
   if (nxt1 < nxt2)
    lst1 = a[i]; 
   else 
    lst2 = a[i]; 
   ans++; 
  }
 }
 printf("%d\n", ans); 
}
