#include<bits/stdc++.h>
using namespace std;
 
const int MOD=1e9+7;
int recurse(int target,vector<int> &pages,vector<int> &cost,int i,vector<vector<int>> &dp){
	if(i<0 or target<0) return 0;
	if(dp[i][target]!=-1) return dp[i][target];
	if(target<cost[i]) return dp[i][target]=recurse(target,pages,cost,i-1,dp);
	return dp[i][target]=max(recurse(target-cost[i],pages,cost,i-1,dp)+pages[i],recurse(target,pages,cost,i-1,dp));
}

void solve(){
	int n,x;
	cin>>n>>x;
	vector<int>h(n),s(n);
	for(int i=0;i<n;i++) cin>>h[i];
	for(int i=0;i<n;i++) cin>>s[i];
	vector<vector<int>> dp(n+1,vector<int>(x+1,-1));	
	// cout<<recurse(x,s,h,n-1,dp);	
	for(int i=0;i<=n;i++){
		for(int j=0;j<=x;j++){
			if(i==0 or j==0) dp[i][j]=0;
			else{
				if(h[i-1]<=j) dp[i][j]=max(s[i-1]+dp[i-1][j-h[i-1]],dp[i-1][j]);
				else dp[i][j]=dp[i-1][j];
			}
		}
	}
	cout<<dp[n][x];
}
 
int main(){
	solve();
}