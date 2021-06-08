#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const int N=2e5+5,M=1e3+7,OO=0x3f3f3f3f;
 
 
int main(){
 
 
    ll n;
    scanf("%lld",&n);
    if(n==1){
        printf("0");
    }
    else if(n==2){
        printf("0");
    }
    else{
        ll f=n/3;
        ll s=n-f;
        printf("%lld",f*s+(f*(f-1)/2));
    }
 
    return 0;
}
