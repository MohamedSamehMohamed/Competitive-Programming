#include <bits/stdc++.h>
using namespace std;
int p1, p2, cntW, cntA, sW, aW;
void test()
{
    scanf("%d%d%d%d%d%d", &p1, &p2, &cntW, &cntA, &sW, &aW);
    int ans = 0;
    for(int _ = 0; _ < 2; _++) {
        for (int i = 0; i <= cntW; i++) {
            if (1LL * sW * i > p1)break;
            int remSwords = cntW - i;
            int tkAA   = min(cntA, (p1 - sW * i)/ aW);
            ans = max(ans, i + tkAA);
            int remAxes = cntA - tkAA;

            for(int __ = 0; __ < 2; __++)
            {
                int tkS = min(remSwords, p2 / sW);
                int tkA = min(remAxes,  (p2 - tkS * sW)/aW );
                ans = max(ans, tkS + tkA + i + tkAA);
                swap(remSwords, remAxes);
                swap(aW, sW);
            }

        }
        swap(cntW, cntA);
        swap(aW, sW);
    }
    printf("%d\n", ans);
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
        test();
}