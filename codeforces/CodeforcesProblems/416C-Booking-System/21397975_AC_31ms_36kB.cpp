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
int n , k ;
bool cmp (pair< pair<int,int> , int > a , pair< pair<int,int> , int > b )
{
    if (a.f.s != b.f.s )return a.f.s > b.f.s ;
    return a.f.f < b.f.f ;
}
int main()
{
    cin >> n ;
    vector<pair< pair<int,int> , int >> v(n);
    for (int i =0 ; i <  n ;i++)
    {
        cin >> v[i].f.f >> v[i].f.s ;
        v[i].s = i+1 ;
    }
    sort(all(v) , cmp );
    cin >> k ;
    vector <pair<int,int>> tp(k) ;
    for (int i =0 ; i < k ;i++)
    {
        cin >> tp[i].f ;
        tp[i].s = i+1 ;
    }
    sort(all(tp));
    vector <pair<int,int>> ans ;
    int ac = 0 ;
    int sum =0 ;
    for (int i =0 ; i < n ;i++)
    {
        for (int j =0 ; j < k ;j++){
        if (tp[j].f == -1 || tp[j].f < v[i].f.f )continue ;
        ac++;
        sum+=v[i].f.s ;
        ans.pb({v[i].s , tp[j].s });
        tp[j].f = -1 ;
        break ;
        }
    }
    cout << ac <<" " << sum <<"\n";
    for (int i =0 ; i < SZ(ans) ;i++)
    {
        cout << ans[i].f <<" " << ans[i].s <<"\n";
    }

}
