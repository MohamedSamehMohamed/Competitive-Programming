#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
const int N=3e5+5,M=1e9+7,OO=0x3f3f3f3f;
int t,n,m,k;
int arr[N];
string s;
 
bool valid(int a,int b){
    int fr=n/(a+b)+(n%(a+b)!=0);
    int sr=n/(a+b);
    return fr*a+sr*b==n;
}
 
int main(){
    //freopen("input.in","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("myfile.txt","w",stdout);
    scanf("%d",&n);
    printf("%d:\n",n);
    vector<pair<int,int> >v;
    for(int i=2;i<n;++i){
        if(valid(i,i-1)) v.push_back({i,i-1});
        if(valid(i,i)) v.push_back({i,i});
    }
    //sort(v.begin(),v.end());
    for(int i=0;i<v.size();++i){
        printf("%d,%d\n",v[i].first,v[i].second);
    }
    return 0;
}
