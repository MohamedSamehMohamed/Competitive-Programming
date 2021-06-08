#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
const int N=2e5+5,M=1e9+7,OO=0x3f3f3f3f;
int t,n,m,k;
int arr[N];
 
int main(){
    //freopen("icecream.in","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("myfile.txt","w",stdout);
    vector<int> a,b;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i){
        scanf("%d",arr+i);
        if(arr[i]>0)
            a.push_back(arr[i]);
        else
            b.push_back(-arr[i]);
    }
    reverse(b.begin(),b.end());
    int ans=upper_bound(b.begin(),b.end(),m)-b.begin();
    ans=max(ans,upper_bound(a.begin(),a.end(),m)-a.begin());
    for(int i=0;i<a.size();++i){
        int rem=m-2*a[i];
        if(rem<0) break;
        ans=max(ans,(i+1)+upper_bound(b.begin(),b.end(),rem)-b.begin());
    }
    for(int i=0;i<b.size();++i){
        int rem=m-2*b[i];
        if(rem<0) break;
        ans=max(ans,(i+1)+upper_bound(a.begin(),a.end(),rem)-a.begin());
    }
    printf("%d\n",ans);
    return 0;
}
