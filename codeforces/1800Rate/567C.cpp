// Author : Mohamed Sameh
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
map<long long, int> pre, suf;
int a[N], n, k;
int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++)
        scanf("%d", a+i);

    for(int i = 1; i < n; i++)
        suf[a[i]]++;
    pre[a[0]]++;

    long long ans = 0;
    for(int i = 1; i < n-1; i++)
    {
        suf[a[i]]--;
        if (a[i] % k == 0)
        {
            ans += 1LL * pre[a[i] / k] * suf[1LL*a[i] * k];
        }
        pre[a[i]]++;
    }
    printf("%lld\n", ans);
}