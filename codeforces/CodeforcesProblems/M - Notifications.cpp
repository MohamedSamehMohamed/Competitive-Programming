#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
const int N=2e5+5,M=1e9+7,OO=0x3f3f3f3f;
int n,m,k;
int t[N];
int d[N];
 
int main(){
    //freopen("icecream.in","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("myfile.txt","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d%d",t+i,d+i);
    ll cur=t[0]+d[0];
    for(int i=1;i<n;++i){
        if(cur>t[i]){
            cur+=d[i];
        }
        else{
            cur=t[i]+d[i];
        }
    }
    printf("%lld\n",cur);
    return 0;
}
