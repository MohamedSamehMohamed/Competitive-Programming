#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
const int N=5e5+5,M=1e9+7,OO=0x3f3f3f3f;
int t,n,m,k;
int grid[105][105];
 
int sum(int r1,int c1,int r2,int c2){
    return grid[r1][c1]-grid[r2-1][c1]-grid[r1][c2-1]+grid[r2-1][c2-1];
}
 
int main(){
    //freopen("input.in","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("myfile.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                scanf("%d",grid[i]+j);
                grid[i][j]+=grid[i-1][j]+grid[i][j-1]-grid[i-1][j-1];
            }
        }
        int mx=1;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                for(int r=i;r<=n;++r){
                    int cur=sum(r,j,i,j);
                    if(cur>k) break;
                    int lo=j,hi=m,md;
                    while(lo<hi){
                        md=lo+(hi-lo+1)/2;
                        cur=sum(r,md,i,j);
                        if(cur<=k) lo=md;
                        else hi=md-1;
                    }
                    mx=max(mx,(r-i+1)*(lo-j+1));
                }
            }
        }
        printf("%d\n",mx);
    }
    return 0;
}
