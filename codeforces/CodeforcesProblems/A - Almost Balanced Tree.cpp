//       Author: Mostafa Mounir Shehab
 
#include <bits/stdc++.h>
using namespace std;
 
#define PI  acos(-1)
#define EPS (1e-10)
#define endl "\n"
#define SZ(v) (int)(v.size())
#define IO ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL), cerr.tie(NULL);
typedef long long ll;
typedef long double ld;
 
 
 
ll MOD=9901;
int OO=1e9 + 1;
const int N=1e5 + 5,M= 1e6 + 5;
 
int n,m,k,SU,idx,len,MN,MX,T;
int l,r,mid;
int a,b,c;
 
struct Node{
 int val,sum;
 int num;
 Node *lt,*rt;
 Node(){
  val = 0;
  sum = 0;
  lt = nullptr;
  rt = nullptr;
 }
 
 
 
};
 
Node *root;
 
void BulidB(Node *&root,int x){
 if(x < 1) return;
 if(root == nullptr) root = new Node();
 int val = x;
 if(val&1){
  root->val = 2;
  --val;
 }
 BulidB(root->lt,val/2);
 BulidB(root->rt,val/2);
 
}
void Bulid(Node *&root){
 if(root == nullptr) return;
 
 if(root->val == 0){
  root->val = 1;
  --a;
 }
 Bulid(root->lt);
 Bulid(root->rt);
}
 
void BulidA(Node *&root,int x){
 if(x < 1) return;
 if(root == nullptr) root = new Node();
 
 if(root->val == 0){
  root->val = 1;
  --x;
 }
 int l = x/2,r = x - l;
 if(rand()%2){
  BulidA(root->lt,l);
  BulidA(root->rt,r); 
 }else{
  BulidA(root->lt,r);
  BulidA(root->rt,l); 
 }
 
}
 
bool flage = true;
int DFS(Node *&root){
 if(root == nullptr) return 0;
 
 int l = DFS(root->lt);
 int r = DFS(root->rt);
 flage &= abs(l - r) <= 1;
 return root->val + l + r;
}
vector<int> adj[N];
void DFSn(Node *&root){
 if(root == nullptr) return;
 root->num = ++k;
 DFSn(root->lt);
 DFSn(root->rt);
 int u = root->num;
 adj[u].push_back(root->val);
 if(root->lt != nullptr)
  adj[u].push_back(root->lt->num);
 else
  adj[u].push_back(0);
 if(root->rt != nullptr)
  adj[u].push_back(root->rt->num);
 else
  adj[u].push_back(0);
}
 
int main(){
 //IO
// freopen("in.txt","r",stdin);
// freopen("out.txt","w",stdout);
 
 cin>>a>>b;
 
 BulidB(root,b);
 
 Bulid(root);
 if(a < 0){
  cout<<"-1";
  return 0;
 }
 BulidA(root,a);
 DFS(root);
 if(!flage){
  cout<<"-1";
  return 0;
 }
 DFSn(root);
 
 for(int i=1;SZ(adj[i]);++i){
  for(int j:adj[i])
   cout<<j<<" ";
  cout<<"\n";
 }
 
}
