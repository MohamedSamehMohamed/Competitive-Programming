// Author : Mohamed Sameh
#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
typedef long long ll ;
using namespace std ;
const int M = 1e3 + 1; 
int n ;
int a[M];
int dp[M][2]; 
string x ;
void printfAnswer(int idx )
{
    if (idx == dp[idx][1])
    {
        printf ("%d\n" , a[idx]); 
        return ; 
    }
    printfAnswer( dp[idx][1] ); 
    printf ("%d\n" , a[idx]); 
}
int main ()
{   
    int t ;
    scanf ("%d" , &t) ; 
    while (t--)
    {
        int cur ;
        n =0 ;
        char nx ;
        while (getline(cin , x) && x == ""){}
        do{
            cur = atoi(x.c_str());
            a[n++] = cur ;
        }while (getline(cin , x) && x != "");
        memset(dp , 0 ,sizeof dp); 
        for (int i =0 ; i < n ;i++)
        {
            dp[i][0] = 1 ; 
            dp[i][1] = i ; 
        }
        for (int i =1 ; i < n ;i++)
        {
            for (int j = i-1 ; j >= 0 ;j--)
            {
                if (a[i] > a[j])
                {
                    if (dp[i][0] < dp[j][0] + 1 )
                    {
                        dp[i][0] = dp[j][0] + 1 ; 
                        dp[i][1] = j ; 
                    }
                }
            }
        }
        int idx =0 ;
        for (int i =1 ; i < n ;i++)
        {
            if (dp[i][0] > dp[idx][0])
            {
                idx = i; 
            }
        }
        printf ("Max hits: %d\n" , dp[idx][0]); 
        printfAnswer(idx);
        if (t != 0 )
        printf ("\n");

    }
}

