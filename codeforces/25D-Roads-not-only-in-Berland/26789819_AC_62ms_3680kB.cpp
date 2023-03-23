// Author : Mohamed Sameh
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>
#include<list>
#include<stack>
#include<deque>
#include <sstream>
#include <string.h>

typedef long long ll ;
#define OO 2000000000
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define IN(n) scanf ("%d" , &n ) 
#define LN(n) scanf ("%lld" , &n)
#define FOR(st,n) for (int i = st ; i < n ; i++)
using namespace std ;
int n ;
int parent[1001];
int Rank[1001]; 
int find (int x )
{
    if (parent[x] == x )return x ;
    return parent[x] = find (parent[x]); 
}
int main()
{
    IN(n); 
    vector <pair<int,int>> del ; 
    for (int i = 1; i <= n ;i++)
        parent[i] = i , Rank[i] =1;
    for (int i = 1 ; i < n ;i++)
    {
        int u , v;
        IN(u); 
        IN(v); 
        int a = find (u); 
        int b = find (v); 
        if (a != b )
        {
            if (Rank[a] < Rank[b])
                swap(a,b); 
            parent[b] = a; 
            Rank[a]+= b; 
        }else 
            del.pb({u,v}); 
    }
    printf ("%d\n" , SZ(del)); 
    int nx = 0;
    for (int i =1 ; i <= n ;i++)
        for (int j = i+1 ; j <= n ;j++)
        {
            int a = find (i); 
            int b = find (j);
            if (a != b )
            {
                printf ("%d %d %d %d\n" , del[nx].f , del[nx].s , i , j);
                if (Rank[a] < Rank[b])
                swap(a,b); 
                parent[b] = a; 
                Rank[a]+= b;
                nx++;
            }
        }
    return 0;
}