#include<bits/stdc++.h>
using namespace std;
 
vector<int>dp,a;
int recurse(int n){
	if(n<0) return INT_MAX;
	if(n==0) return 0;
	if(dp[n]!=-1) return dp[n]; 
	int ans=INT_MAX;
	for(int i:a){
		int sub=recurse(n-i);
		if(sub!=INT_MAX) ans=min(ans,sub+1);
	}
	return dp[n]=ans;
}
 
int main(){
	int n,x;
	cin>>n>>x;
	a=vector<int>(n);
	for(int i=0;i<n;i++) cin>>a[i];
	// sort(a.begin(),a.end(),greater<int>());
	dp=vector<int>(x+1,-1);
	int ans=recurse(x);
	cout<<(ans==INT_MAX?-1:ans);
}