#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int n;
int a[N], b[N], c[N], seen[N];
void test()
{
 scanf("%d", &n);
 for (int i = 0; i < n; i++)scanf("%d", a+i), b[i] = -1, c[i] = -1, seen[i+1] = 0;
 for (int i = 0; i < n; i++)
 {
  if (!seen[a[i]])
  {
   b[i] = a[i];
   c[i] = a[i];
   seen[a[i]] = 1;
  }
 }
 int j = 1;
 for (int i = 0; i < n; i++)
 {
  if (b[i] != -1)continue;
  while(seen[j])j++;
  b[i] = j;
  j++;
 }
 set<int> st;
 for (int i = 1; i <= n; i++)if (!seen[i])st.insert(i);
 for (int i = 0; i < n; i++)
 {
  if (c[i] != -1)continue;
  auto it = st.lower_bound(a[i]);
  if (it == st.end())it--; 
  if (*it > a[i])it--;
  c[i] = *it;
  st.erase(*it);
 }
 for (int i = 0; i < n; i++)printf("%d%c", b[i], (i + 1 == n? '\n': ' '));
 for (int i = 0; i < n; i++)printf("%d%c", c[i], (i + 1 == n? '\n': ' '));
}
int main()
{
 int t;
 scanf("%d", &t);
 while(t--)
  test();
}
