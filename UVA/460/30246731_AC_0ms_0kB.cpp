#include<bits/stdc++.h>
using namespace std;
int a[4], b[4], x_left, x_right, y_up, y_down; 
int get_common()
{
 if (b[0] < a[0])
  for (int i = 0; i < 4; i++)swap(a[i], b[i]); 
 x_left  = b[0]; 
 x_right = min(a[2], b[2]); 
 y_up = min(a[3], b[3]); 
 y_down = max(a[1], b[1]); 
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
  if (common)
    printf("%d %d %d %d\n", x_left, y_down, x_right, y_up); 
  else 
   printf("No Overlap\n");
  if (i + 1 <= t)
   printf("\n"); 
 }
}
