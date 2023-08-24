#include <bits/stdc++.h>
using namespace std;
int n, m;
void test()
{
    scanf("%d%d", &n, &m);
    long long tot = (1LL * n * (n+1))/2;
    if (n-m != 0)
    {
        int each = (n-m) / (m+1);
        int rem = (n-m) % (m+1);
        tot -= 1LL * (each+1) * rem;
        tot -= 1LL * (m+1) * (1LL * each * (each+1))/2;
    }
    printf("%lld\n", tot);
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
        test();
    return 0;
}