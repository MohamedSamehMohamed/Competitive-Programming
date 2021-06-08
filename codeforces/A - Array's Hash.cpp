#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
const int N=5e5+5,M=1e9+7,OO=0x3f3f3f3f;
int t,n,m,k;
int arr[N];
int flips[N];
 
int main(){
    //freopen("icecream.in","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("myfile.txt","w",stdout);
    ll sum=0;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",arr+i);
    bool flip=1;
    for(int i=n;i>0;--i){
        flips[i]=flip?1:-1;
        if(flip)
            sum+=arr[i];
        else
            sum-=arr[i];
        flip=!flip;
    }
    for(int i=2;i<=n;++i)
        flips[i]+=flips[i-1];
    scanf("%d",&m);
    while(m--){
        int l,r,v;
        scanf("%d%d%d",&l,&r,&v);
        int pos=flips[r]-flips[l-1];
        sum+=pos*1ll*v;
        printf("%lld\n",sum);
    }
    return 0;
}
