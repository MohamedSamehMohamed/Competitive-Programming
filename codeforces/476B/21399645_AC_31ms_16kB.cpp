// Author : Mohamed Sameh
#include <bits/stdc++.h>
typedef long long ll ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define SZ(a) (int)a.size()
#define Flush fflush(stdout);
using namespace std ;
int N , P ;
float A,B;
int main()
{
string a , b ;
	cin >> a >> b ;
	for (int i =0 ; i < b.size();i++)
	{

		if (a[i] == '+')P++;
		else if (a[i]=='-')N++;

	}

	queue<pair<int,pair<int,int>>>BFS;
	BFS.push({ 0, {0,0}});

	while (!BFS.empty())
	{
		int curp , cp , cn ;
		curp = BFS.front().f;
		cp = BFS.front().s.f;
		cn = BFS.front().s.s;
		BFS.pop();
		if (curp == b.size())
		{
			B++;
			if (cp == P && cn == N )
			A++;
			continue ;
		}
		if (b[curp] == '+')
		{
			cp++;

		}else if (b[curp] == '-')
		{
			cn++;
		}else
		{
			BFS.push({ curp+1 , {cp+1,cn}});
			BFS.push({ curp+1 , {cp,cn+1}});

			continue ;
		}
		BFS.push({ curp+1 , {cp,cn}});
	}

printf ("%.10f\n" ,  A / B) ;
}
