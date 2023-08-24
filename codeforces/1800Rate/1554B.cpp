#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
vector<int> adj[N];
int a[N], n, k;
void test()
{
    scanf("%d%d", &n, &k);
    long long ans = -1e18;
    for(int i = 0; i < n; i++)scanf("%d", a+i);
    for(int i = 0; i < n; i++)
    {
        for(int j = max(i+1, n-2*k-1); j < n; j++)
            ans = max(ans, 1LL * (i+1) * (j+1) - k * (a[i] | a[j]));
    }
    printf("%lld\n", ans);
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
        test();
}