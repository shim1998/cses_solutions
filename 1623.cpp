#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
 
int n;
long long int recurse(vector<int>&a, long long int s1,long long int s2,int i){
	if(i==n) return abs(s1-s2);
	long long int x=LONG_MAX;
	x=min(recurse(a,s1-a[i],s2+a[i],i+1),recurse(a,s1,s2,i+1));
	return x;
}

void solve(){
	cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	long long int s=0;
	for(int i=0;i<n;i++) s+=a[i];
	cout<<recurse(a,s,0,0);
}
 
int main(){
	solve();
}