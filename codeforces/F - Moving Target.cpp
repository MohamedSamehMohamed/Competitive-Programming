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
    scanf("%d",&n);
    printf("%d\n",(n+2)/2);
    for(int i=1;i<=n;i+=2)
        printf("%d ",i);
    if(n%2==0) printf("%d",n);
    return 0;
}
