#include<bits/stdc++.h>
using namespace std;
const int N = 100, INF = 1e9;
int n;
int mat[N][N]; 
map<string, int> mp;
int getIdx(string &x)
{
	if (mp.find(x) == mp.end())
	{
		int sz = mp.size(); 
		mp[x] = sz; 
	}
	return mp[x]; 
}
int main()
{
	int t = 0;
	int n, m; 
	while(cin >> n >> m && (n || m)){
		cout << "Network " << ++t << ": "; 
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				mat[i][j] = (i==j?0:INF);
		mp.clear();  
		for (int i = 0; i < m; i++)
		{
			int u, v;
			string x, y;
			cin >> x >> y; 
			u = getIdx(x);
			v = getIdx(y); 
			mat[u][v] = mat[v][u] = 1; 
		}
		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]); 
		int ans = 0; 
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				ans = max(ans, mat[i][j]); 
		if (ans == INF)
			cout << "DISCONNECTED\n"; 
		else 
			cout << ans << '\n'; 
		cout << '\n'; 
	}
	
	
}

