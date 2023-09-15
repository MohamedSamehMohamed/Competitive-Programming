// Author: Mohamed Sameh
#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 9;
int a[N], n;
void test()
{

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a+i);
    }
    if (n == 1)
    {
        if (a[1])
        {
            printf("2 1\n");
        }else
        {
            printf("1 2\n");
        }
        return;
    }
    if (!a[n])
    {
        for(int i = 1; i <= n+1; i++)
            printf("%d ", i);
        printf("\n");
        return;
    }
    if (a[1])
    {
        printf("%d ", n+1)
        for(int i = 1; i <= n; i++)
            printf("%d ", i);
        printf("\n");
        return;
    }
    int pos = -1;
    for(int i = 1; i < n; i++)
    {
        if (!a[i] && a[i+1])
        {
            pos = i;
            break;
        }
    }
    if (~pos)
    {
        for(int i = 1; i <= pos; i++)printf("%d ", i);
        printf("%d ", n+1);
        printf("%d ", pos + 1);
        for(int i = pos + 2; i <= n; i++)
            printf("%d ", i);
        printf("\n");
    }else
        printf("-1\n");


}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
        test();
}
/*
 * if i to n+1
 * and
 *  n+1 to i+1
 *
 */