#include<bits/stdc++.h>
using namespace std;
int n;
const int MOD=1e9+7;
vector<vector<int>>dp;
set<int>sum_sets;
int recurse(vector<int>&a,int s,int i){
	if(i==n+1) return 0;
	if(dp[i][s]!=-1) return dp[i][s];
	if(sum_sets.find(s)==sum_sets.end()) sum_sets.insert(s);
	return dp[i][s]=recurse(a,s+a[i],i+1) or recurse(a,s,i+1) or recurse(a,a[i],i+1);
}
 
void solve(){
	int s=0;
	cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;i++) cin>>a[i],s+=a[i];
	dp=vector<vector<int>>(n+2,vector<int>(s+1,-1));
	recurse(a,a[0],1);
	cout<<sum_sets.size()<<'\n';
	for(int val: sum_sets) cout<<val<<' ';
}
 
int main(){
	solve();
}