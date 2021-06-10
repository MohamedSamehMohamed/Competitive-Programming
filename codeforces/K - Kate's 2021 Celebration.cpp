#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const int N=1e3+10,M=1e9,OO=0x3f3f3f3f;
 
 
int main(){
 
    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);
 
 
    int n;
    scanf("%d",&n);
 
    int mn=OO,id=0;
 
    for(int i=0;i<n;++i){
        int p;
        scanf("%d",&p);
        char s[105];
        scanf("%s",s);
        vector<int> freq(26,0);
        for(int j=0;s[j];++j)
            ++freq[s[j]-'0'];
 
        if(freq[2]>=2&&freq[1]>=1&&freq[0]>=1){
            if(p<mn){
                mn=p;
                id=i+1;
            }
        }
    }
 
    printf("%d\n",id);
 
    return 0;
}
