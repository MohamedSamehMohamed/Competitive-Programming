#include<bits/stdc++.h>
using namespace std ;
/*#######################################################################*/
/*#######################################################################*/
/*#######################################################################*/
/*#                                                                     #*/
/*#                                                                     #*/
/*#                           MOHAMED SAMEH                             #*/
/*#                                                                     #*/
/*#                                                                     #*/
/*#                                                                     #*/
/*#######################################################################*/
/*#######################################################################*/
/*#######################################################################*/
typedef long long ll ;
typedef vector<int> V ;
typedef vector<ll > VL ;
typedef vector<pair<int,int> >VP;
typedef vector<pair<ll,ll > >VPL;
typedef map<int,int>  MP ;
typedef map<char,int>MCI;
typedef map<ll,ll >  MPL;
typedef set<int> ST ;
typedef stack<int>SK ;
typedef stack<pair<int,int > >SKP;
typedef queue <int> Q ;
typedef priority_queue<int> PQ ;
typedef deque<int> DQ;
////////////////////////////////////////////////////////////////////
#define pf push_front
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define M_P make_pair
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

void start ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

}
void step1 (ll &a , ll &b );
void step2 (ll &a , ll &b );
void step3 (ll &a , ll &b );
int main ()
{
    ll a ,b ;
    cin >>a >> b ;
    step1(a,b);
    cout << a <<" "<<b ;


    return 0 ;
}
void step1 (ll &a , ll &b )
{
    if (a==0 || b==0)
        return ;
    step2(a,b);
}

void step2 (ll &a , ll &b )
{
    if (a >= 2*b )
    {
        a =a% (2*b);
        step1(a,b);
    }else
    step3(a,b);

}

void step3 (ll &a , ll &b )
{
    if (b>=2*a)
    {
        b=b%(2*a);
        step1(a,b);
    }
}