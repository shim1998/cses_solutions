#include<bits/stdc++.h>
using namespace std;

vector<int>dp;
const int MOD=1e9+7;
int recurse(int n){
	if(n==0) return 1;
	if(dp[n]!=-1) return dp[n]; 
	int ans=0;
	for(int i=1;i<=6;i++){
		if(n-i>=0){
			ans+=recurse(n-i);
			if(ans>=MOD) ans-=MOD;
		}
	}
	return dp[n]=ans;
}

int main(){
	int n;
	cin>>n;
	dp=vector<int>(n+1,-1);
	cout<<recurse(n);
}