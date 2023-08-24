// Author: MohamedSameh
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int n, k, a[N], b[N];
void test()
{
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++)
        scanf("%d", a+i), b[i] = a[i];
    sort(b, b+n);
    int sub = 0;
    for (int i = 0; i < n; i++)
    {
        int idx = lower_bound(b, b+n, a[i]) - b;
        int c = 0;
        while(idx + c < n && i + c < n && a[i+c] == b[idx + c])
            c++;
        i += c - 1;
        sub++;
    }
    printf("%s\n", (sub > k? "No": "Yes"));
}
int main() {
    int t;
    scanf("%d", &t);
    while(t--)
        test();
    return 0;
}