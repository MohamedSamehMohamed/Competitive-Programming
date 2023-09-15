// Author: MohamedSameh
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int a[N], n;
void test()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", a+i);
    sort(a, a+n);
    long long sum = 0;
    for(int i = 0; i < n; i++)sum += a[i];
    long long pre = 0;
    double ans = -1e18;
    for(int i = 0; i < n-1; i++)
    {
        pre += a[i];
        sum -= a[i];
        ans = max(ans, (1.0*pre / (i+1)) + (1.0 * sum / (n-i-1)) );
    }
    printf("%.9lf\n", ans);
}
int main() {
    int t;
    scanf("%d", &t);
    while(t--)
        test();
    return 0;
}