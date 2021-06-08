#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
const int N=2e5+5,M=1e9+7,OO=0x3f3f3f3f;
int t,n,m,k;
int arr[N];
vector<int> ids[N];
 
int main(){
    //freopen("icecream.in","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("myfile.txt","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        int a,c;
        scanf("%d%d",&a,&c);
        ids[c].push_back(a);
    }
    bool failed=0;
    for(int i=1;i<=200000&&!failed;++i){
        for(int j=1;j<ids[i].size();++j){
            if(ids[i][j]<ids[i][j-1]){
                failed=1;
            }
        }
    }
    if(failed) printf("NO\n");
    else printf("YES\n");
    return 0;
}
