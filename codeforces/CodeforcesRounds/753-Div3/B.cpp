#include <bits/stdc++.h>
using namespace std;
void read_file()
{
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
}
long long x, n;
void test()
{
  scanf("%lld%lld", &x, &n);
  if (n == 0)
  {
    printf("%lld\n", x);
    return;
  }
  long long sum = (n * (n+1))/2;
  if (abs(x) % 2 == 0)
  {
    long long odd = (n+1) / 2;
    long long sum_odd = odd * odd; 
    x += (n > 1? 4: 1) * sum_odd; 
    x -= sum; 
    printf("%lld\n", x);
  }else 
  {
    long long odd = (n+1) / 2;
    long long sum_odd = odd * odd; 
    x -= (n > 1? 4: 1) * sum_odd; 
    x += sum; 
    printf("%lld\n", x);  
  }
}
int main()
{
  read_file();
  int t;
  scanf("%d", &t);
  while(t--)
    test();
}
/*
x{0, 2, 4, 6, 8, 10, . . ., }
4 * (i + x) + 1


4 * sum(1, 3, 5, 7, 9)
i -> pos of even 

2i+2i+1 -> 4i + 1 

2(i+2)+2*(i+2) + 1 -> 4(i+2) + 1 

2-
3-

4
5

6-
7-

8
9

10-
11-

-1
2+3
-4
5+6

1 4 7 10 13 16 

*/