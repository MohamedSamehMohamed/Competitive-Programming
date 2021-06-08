#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
const int N=2e5+5,M=1e9+7,OO=0x3f3f3f3f;
int t,n,m,k;
map<int,int> mp;
 
int main(){
    //freopen("icecream.in","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("myfile.txt","w",stdout);
 
    scanf("%d",&t);
    while(t--){
        int mx=0;
        mp.clear();
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            int v;
            scanf("%d",&v);
            mx=max(mx,++mp[v]);
        }
        for(map<int,int>::iterator it=mp.begin();it!=mp.end();++it){
            if((*it).second==mx){
                printf("%d\n",(*it).first);
                break;
            }
        }
    }
 
    return 0;
}
