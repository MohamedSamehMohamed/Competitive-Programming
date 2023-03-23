// Author : Mohamed Sameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
using namespace std ;
const int M = 1e7 + 6 ;
bool siev[M];
int frq[M];
bool circle (int x )
{
    int arr[10];
    int id =0 ;
    while (x)
    {
        arr[id++] = x%10;
        x/=10;
    }
    for (int i = 0 ; i < id ; i++)
    {
        int cur = 0 ;
        for (int j = i ,k=1,l=0; l < id ;l++,j=(j+1)%id,k*=10)
        {
            cur += arr[j] * k;
        }
        //cout << cur <<"\n";
        if (siev[cur])return 0;
    }
    return 1 ;
}
int main()
{
    for (int i = 2 ; i <= M/i ; i++)
    {
        if (siev[i])continue ;
        for (int j = i*i ; j < M ;j+=i)siev[j] =1 ;
    }
    siev[0] = siev[1] = 1 ;
    for (int i =2 ; i < M ;i++)
    {
        if (siev[i])
        {
            frq[i] += frq[i-1];
        }else
        {

            frq[i] += frq[i-1] + circle(i);
        }
    }
    int l , r ;
    while (scanf ("%d" , &l ))
    {
        if (l == -1 )break ;
        scanf ("%d" , &r );
        int ans = frq[r] - frq[l-1];
        if (ans == 0 )
        {
            printf ("No Circular Primes.\n");
        }else
        {
            if (ans == 1 )
            printf ("%d Circular Prime.\n" , ans );
            else
            printf ("%d Circular Primes.\n" , ans );
        }
    }

}
