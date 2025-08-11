#include<bits/stdc++.h>
using namespace std;
int n,m;
const int MOD=1e9+7;
vector<vector<int>>dp;
int recurse(vector<int>&a,int x,int i){
	if(i==n){
		return 1;
	}
	if(dp[i][x]!=-1) return dp[i][x];
	int a1=0,a2=0,a3=0;
	if(a[i]==0){
		a1=recurse(a,x,i+1);
		if(x-1>0) a2=recurse(a,x-1,i+1);
		if(x<m) a3=recurse(a,x+1,i+1);
		return dp[i][x]=(((a1+a2)%MOD)+a3)%MOD;
	}
	if(abs(a[i]-x)<=1) return dp[i][x]=recurse(a,a[i],i+1);
	else return 0;
}
 
void solve(){
	cin>>n>>m;
	int ans=0;
	vector<int>a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	dp=vector<vector<int>>(n+1,vector<int>(m+1,-1));
	if(a[0]==0){
		for(int i=1;i<=m;i++){
			ans=(ans+recurse(a,i,1))%MOD;
		}
	}
	else ans=recurse(a,a[0],1);
	cout<<ans;
}
 
int main(){
	solve();
}