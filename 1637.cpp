#include<bits/stdc++.h>
using namespace std;
 
unordered_map<int,int>dp;
const int MOD=1e9+7;
int recurse(int n){
	if(n==0) return 0;
	if(dp.contains(n)) return dp[n]; 
	int ans=INT_MAX,x=n;
	while(x){
		int i=x%10;
		if(i!=0) ans=min(ans,recurse(n-i)+1);
		x/=10;
	}
	return dp[n]=ans;
}
 
int main(){
	int n;
	cin>>n;
	cout<<recurse(n);
}