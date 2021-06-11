//https://codeforces.com/contest/1333/problem/D
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
vector<vector<int>> ans ;
vector<int> tem;
int n, k;
string x;    
void select ()
{
    tem.clear();
    for (int i =0 ;i + 1 < n ;i++)
        {
            if (x[i] == 'R' && x[i+1] == 'L')
            {
                tem.pb(i);
                i++; 
            }
        }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k >> x; 
    int al =0 ; 
    while (1)
    {
        select(); 
        if (SZ(tem) == 0 )break; 
        ans.pb(tem);
        for (auto i : tem)
        {
            swap(x[i] , x[i+1]);
        }
        al+=SZ(tem);
    }
    if (k > al || k < SZ(ans))
    {
        cout <<"-1\n";
    }else 
    {
        for (int i =0 ; i < SZ(ans) ;i++)
        {
            while (SZ(ans[i]) > 1  && k > SZ(ans))
            {
                k--;
                cout << "1 " << ans[i].back()+1 <<"\n"; 
                ans[i].pop_back(); 
            }
            cout << SZ(ans[i]) <<" "; 
            for (auto j : ans[i])
            cout << j + 1 <<" "; 
            cout <<"\n"; 
            
        }
    }
 
    
    
}
