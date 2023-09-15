#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
const int N=2e5+5,M=1e9+7,OO=0x3f3f3f3f;
int n,m,k;
vector<ll> a;
 
ll sum(ll x){
    return x*(x+1)/2;
}
 
ll val(int x){
    return a[x-1]-sum(x);
}
 
bool can(int x){
    if(x==0) return 1;
    return val(x)>0;
}
 
int main(){
    //freopen("icecream.in","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("myfile.txt","w",stdout);
    scanf("%d",&n);
    a.resize(n);
    for(int i=0;i<n;++i)
        scanf("%lld",&a[i]);
    sort(a.rbegin(),a.rend());
    for(int i=1;i<n;++i)
        a[i]+=a[i-1];
    int lo=0,hi=n,md;
    while(lo<hi){
        md=lo+(hi-lo+1)/2;
        if(can(md)) lo=md;
        else hi=md-1;
    }
    ll mx=0;
    for(int i=1;i<=lo;++i){
        mx=max(mx,val(i));
    }
    printf("%lld\n",mx);
    return 0;
}
