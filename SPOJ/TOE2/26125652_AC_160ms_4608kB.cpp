// Author : Mohamed Sameh
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>
#include<list>
#include<stack>
using namespace std ;


typedef long long ll ;

#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
bool win (string &t )
{
	for (int i =0 ; i < 9 ; i+=3 )
	if (t[i] == t[i+1] && t[i+1] ==  t[i+2] && t[i] != '.')
		return true ; 
	for (int i =0 ; i < 3 ; i++ )
	if (t[i] == t[i+3] && t[i+3] ==  t[i+6] && t[i] != '.')
		return true ; 
	
	if (t[0] == t[4] && t[4] ==  t[8] && t[0] != '.')return true ; 
	if (t[2] == t[4] && t[4] ==  t[6] && t[2] != '.')return true ; 
	for (int i =0 ; i < 9 ; i++)
		if (t[i] == '.')return false ; 
	
	
	return true;  

}
int main ()
{
	bool ok , turn ;  
	string target , t  ; 
	while (1)
	{
		ok =0 ; 
		// 1 -> x : 0 -> o 
		cin >> target ;
		if (target == "end")break; 
		
		t = "........."; 
		queue<pair<string , bool>> BFS; 
		BFS.push({t,1}); 
		map<string,bool> vis; 
		vis[t]=1; 
		while (!BFS.empty())
		{
			t = BFS.front().f ;
			turn = BFS.front().s;  
			BFS.pop(); 
			if (t == target )
			{
				ok =win(t); 
				break; 
			}
			if (win(t))continue ;
			 
			for (int i =0 ; i < 9 ; i++)
			{
				if (t[i] == '.')
				{
					t[i]=(turn  ? 'X' : 'O' );
					if (!vis[t]){
					BFS.push({t,!turn});
					vis[t]=1;
					} 
					t[i]='.';
				}
			}
			
		}
		puts(ok ? "valid":"invalid");
		
	}

return 0; 
}
