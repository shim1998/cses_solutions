#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
 
void solve(){
	int n,t;
	cin>>n>>t;
	vector<int>a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	long long int l=0,r=1e18;
	while(l<=r){
		long long int mid=(l+r)/2,sum=0;
		for(int i=0;i<n;i++){
			sum+=(mid/a[i]);
			if(sum>=t) break;
		}
		if(sum>=t){
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	cout<<l<<'\n';
}
 
int main(){
	solve();
}