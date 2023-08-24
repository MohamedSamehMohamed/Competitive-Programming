// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std;
int a, b, c;
void test()
{
    scanf("%d%d%d", &a, &b, &c);
    int dif = abs(a-b) - 1;
    long long cir = 2 * dif + 2;
    if (max({c, a, b}) > cir)
    {
        printf("-1\n");
        return;
    }
    int ans = c + dif + 1;
    if (ans > cir)
        ans = c - dif - 1;
    printf("%d\n", ans);
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
        test();
}