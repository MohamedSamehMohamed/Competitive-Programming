// Author: Mohamed Sameh
#include <bits/stdc++.h>
using namespace std;
int n;
int b[200];
void test()
{
    memset(b, 0, sizeof b);
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        long long x;scanf("%lld", &x);
        for(int j = 0; j < 31; j++)
            if (x & (1LL<<j))
                b[j]++;
    }
    long long ans = 0;
    for(int i = 0; i < 31; i++)
        if (b[i] == n)
            ans += (1LL<<i);
    printf("%lld\n", ans);
}
int main() {
    int t;
    scanf("%d", &t);
    while(t--)
        test();
}