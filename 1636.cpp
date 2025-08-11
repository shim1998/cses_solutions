#include<bits/stdc++.h>
using namespace std;
 
vector<int>dp,a;
const int MOD=1e9+7;
int recurse(int n){
	if(n==0) return 1;
	if(dp[n]!=-1) return dp[n]; 
	int ans=0;
	for(int i:a){
		if(n-i>=0){
			ans+=recurse(n-i);
			if(ans>=MOD) ans-=MOD;
		}
	}
	return dp[n]=ans;
}
 
int main(){
	int n,x;
	cin>>n>>x;
	a=vector<int>(n);
	for(int i=0;i<n;i++) cin>>a[i];
	dp=vector<int>(x+1,-1,0);
	cout<<recurse(x);
}