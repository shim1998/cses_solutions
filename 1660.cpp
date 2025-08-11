#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
 
void solve(){
	int n,t;
	cin>>n>>t;
	vector<int>a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	long long int curr_sum=0;
	int ans=0;
	int l=0,r=0;
	for(r;r<n;r++){
		curr_sum+=a[r];
		if(curr_sum>t){
			while(l<=r){
				curr_sum-=a[l];
				l++;
				if(curr_sum==t){
					ans++;
				}
				if(curr_sum<t) break;
			}
		}
		if(curr_sum==t){
			ans++;
		}
	}
	cout<<ans;
}
 
int main(){
	solve();
}