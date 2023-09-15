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
const int M =2e5 + 1;  
int a[M]; 
int n ; 
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i =0 ; i < n ;i++)
    {
        cin >> a[i]; 
    }
    map<ll,int> mp ;
    ll sum =0, ans =0;
    int last =-1 ; 
    mp[0]=0; 
    for (int i =0 ; i < n ;i++)
    {
        sum += a[i]; 
        if (mp.count(sum))
        last = max (last, mp[sum]); 
        ans += i-last; 
        mp[sum] = i+1 ;
    }
    cout << ans <<"\n"; 
    
}
