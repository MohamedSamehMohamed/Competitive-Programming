#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const int N=1e5+10,M=1e9,OO=0x3f3f3f3f;
 
 
int main(){
 
    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);
 
 
    int n;
    scanf("%d",&n);
 
    vector<vector<int> > vvi(n);
 
    for(int i=0;i<n;++i){
        int k;
        scanf("%d",&k);
        for(int j=0;j<k;++j){
            int x;
            scanf("%d",&x);
            vvi[i].push_back(x);
        }
    }
 
    vector<int> lst(N,0);
    vector<int> used(N,0);
 
    for(int i=n-1;~i;--i){
        int mx=0;
        for(int j=0;j<vvi[i].size();++j)
            mx=max(lst[vvi[i][j]],mx);
 
        for(int j=0;j<vvi[i].size();++j)
            lst[vvi[i][j]]=mx+1;
 
        used[mx+1]=1;
    }
 
    int cnt=0;
    for(int i=0;i<N;++i)
        if(used[i]) ++cnt;
 
    printf("%d\n",cnt);
 
    return 0;
}
