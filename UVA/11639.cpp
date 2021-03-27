#include<bits/stdc++.h>
using namespace std;
int a[4], b[4]; 
int get_common()
{
 if (b[0] < a[0])
  for (int i = 0; i < 4; i++)swap(a[i], b[i]); 
 int x_left  = b[0]; 
 int x_right = min(a[2], b[2]); 
 int y_up = min(a[3], b[3]); 
 int y_down = max(a[1], b[1]); 
 return max(0, (x_right-x_left)) * max(0, (y_up - y_down));  
}
int get_total()
{
 int area = 0;
 area += (a[2] - a[0]) * (a[3] - a[1]); 
 area += (b[2] - b[0]) * (b[3] - b[1]); 
 return area; 
}
int main()
{
 int t; 
 scanf("%d", &t);
 for (int i = 1; i <= t; i++)
 {
  for (int j = 0; j < 4; j++)scanf("%d", a+j); 
  for (int j = 0; j < 4; j++)scanf("%d", b+j);
  int common = get_common(); 
  int tot = get_total(); 
  printf("Night %d: %d %d %d\n", i, common, tot - 2 * common, 10000 - tot + common); 
 }
}
