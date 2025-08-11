#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n,m;
	cin>>n>>m;
	vector<int>a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a.begin(),a.end());
	long long int val=1,ans;
	for(int i: a){
		if(i>val){
			ans=val;
			break;
		}
		val+=i;
	}
	cout<<ans;
}
 
int main(){
	solve();
}