#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int n;
vector<vector<int>>dp;

int recurse(int i,int s1,int s2){
	if(i==0) return 0;
	if(s1==s2) return 1;
	if(dp[i][s1]!=-1) return dp[i][s1];
	return dp[i][s1]=(recurse(i-1,s1-i,s2+i)+recurse(i-1,s1,s2))%MOD;
}
 
void solve(){
	cin>>n;
	int s=0;
	for(int i=1;i<=n;i++) s+=i;
	dp=vector<vector<int>>(n+1,vector<int>(s+1,-1));
	cout<<recurse(n,s,0);
}
 
int main(){
	solve();
}