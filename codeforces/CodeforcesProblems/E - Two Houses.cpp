#include<bits/stdc++.h>
using namespace std;
int n; 
int a[600];
int reach[600][600]; 
bool ask(int a, int b)
{
 cout << "? " << a + 1 << " " << b + 1<< endl;
 string x;cin >> x;
 return x == "Yes";
}
priority_queue<array<int, 3>> pq;
int main()
{
 
 cin >> n;
 for (int i = 0; i < n; i++)cin >> a[i];
 
 for (int i = 0; i < n; i++)
  for (int j = i+1; j < n; j++)
  {
   pq.push({abs(a[i] - a[j]), i, j}); 
  }
 while(!pq.empty())
 {
   auto cur = pq.top();pq.pop();
   int u = cur[1];
   int v = cur[2];
   if (a[u] < a[v])swap(u, v); 
   if (ask(u, v))
   {
    cout << "! " << u+1 << " " << v + 1 << endl;
    return 0;
   }
 }
 cout << "! " << 0 << " " << 0 << endl; 
}
