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
int main()
{
    int n ,  k ;
    scanf ("%d%d" , &n ,&k);
    string x[n];
    for (int i =0 ; i < n ;i++)
    {
        x[i] = "";
        for (int j =0 ; j< n ;j++)
        {
            if (i % 2 )
            {
                x[i] += ( j % 2 == 0 ? 'S' : 'L');
            }else
            {
                x[i] += (j % 2 == 0 ? 'L' : 'S');
            }
            if (x[i][j] == 'L')k--;
        }
    }
    for (int i = 0 ; i < n && k != 0 ; i++)
    {
        for (int j = 0 ; j < n && k != 0 ; j++)
        {
            if (x[i][j] == 'L')
            {
                x[i][j] = 'S';
                k++;
            }
        }
    }
    if (k == 0 )
    {
        printf ("YES\n");
        for (int i =0 ; i < n ;i++)cout << x[i] <<"\n";
    }else
    printf ("NO\n");
}
