#include<bits/stdc++.h>
using namespace std;
int NoofWays(vector<vector<int>> &a,int n,int m)
{
	vector<vector<int>> dp(n,vector<int>(m));
	dp[0][0] = 1;
	
	for(int i=0;i<n;i++)
	dp[0][i] = 1;
	
	for(int i=0;i<m;i++)
	dp[i][0] = 1;
	
	for(int i=1;i<n;i++)
	for(int j=1;j<m;j++)
	{
		if(a[i][j])
		dp[i][j] = 0;
		
		else
		dp[i][j] = dp[i-1][j] + dp[i][j-1];
	}
	
	return dp[n-1][m-1];
}
signed main()
{
	vector<vector<int>> a = { {0,0,0},
							  {0,1,0},
							  {0,0,0} };
							  
	int n = a.size(), m = a[0].size();
	
	cout<< NoofWays(a,n,m) <<endl;
	
	return 0;
}
