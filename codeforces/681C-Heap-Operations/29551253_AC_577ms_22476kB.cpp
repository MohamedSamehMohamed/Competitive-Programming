// Author : MohamedSameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define debug(x) cout<<#x<<" = { "<<x<<" }\n"
void fo (){fflush(stdout);}
using namespace std;
map <int , int > mp ;
int main ()
{
	 int n ; 
	 cin >> n ; 
	 vector <pair<string , int >> ans ; 
	 priority_queue <int> pq ; 
	 while (n--)
	 {
		 string op ; 
		 int val  ; 
		 cin >> op ; 
		 if (op == "insert")
		 {
			 cin >> val ;
			 pq.push(-val); 
			 ans.pb({op , val});
			 continue ; 
		 }
		 if (op == "getMin")
		 {
			 cin >> val ; 
			 while (!pq.empty() && -pq.top() < val )
			 {
				 ans.pb({"removeMin" , 1 }); 
				 pq.pop(); 
			 }
			 if (pq.empty() || -pq.top() > val )
			 {
				 pq.push(-val); 
				 ans.pb({"insert" , val });
			 }
		 }else 
		 {
			 if (pq.empty())
			 {
				 ans.pb({"insert" , 1}); 
			 }else pq.pop(); 
		 }
		 ans.pb({op , val }); 
	 }
	 	 printf ("%d\n" , SZ(ans) ); 
	 for (int i =0 ; i < SZ(ans) ; i++)
	 {
		 cout << ans[i].f ; 
		 if (ans[i].f[0] == 'r')
		 {
			 cout <<"\n"; 
		 } else 
		 cout << " " << ans[i].s <<"\n"; 
	 }
}	
 