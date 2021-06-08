#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
const int N=1e6+5,M=1e9+7,OO=0x3f3f3f3f;
const double eps=1e-7;
int t,n;
map<string,int> mp;
 
int a[N];
int b[N];
 
 
 
int main(){
    //freopen("icecream.in","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("myfile.txt","w",stdout);
 
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            string s;
            cin>>s;
            a[i]=i;
            mp[s]=i;
        }
        for(int i=0;i<n;++i){
            string s;
            cin>>s;
            b[i]=mp[s];
        }
        set<int> elms;
        int sz=0;
        for(int i=0;i<n;++i){
            if(elms.find(a[i])==elms.end()) elms.insert(a[i]);
            else elms.erase(a[i]);
            if(elms.find(b[i])==elms.end()) elms.insert(b[i]);
            else elms.erase(b[i]);
            if(elms.size()==0) printf("%d%c",(i+1)-sz," \n"[i+1==n]),sz=i+1;
        }
    }
 
    return 0;
}
