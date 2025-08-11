#include<bits/stdc++.h>
using namespace std;
 
const int MOD=1e9+7;

void solve(){
	int n;
	cin>>n;
	vector<vector<int>>grid(n,vector<int>(n));
	char c;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>c;
			grid[i][j]=(c=='*'?-1:0);
		}
	}
	if(grid[0][0]==-1){
		cout<<0<<'\n'; 
		return;
	}
	grid[0][0]=1;
	for(int i=1;i<n;i++){
		if(grid[i][0]==-1) grid[i][0]=0;
		else grid[i][0]=grid[i-1][0];
	}
	for(int j=1;j<n;j++){
		if(grid[0][j]==-1) grid[0][j]=0;
		else grid[0][j]=grid[0][j-1];
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			if(grid[i][j]==-1) grid[i][j]=0;
			else{
				grid[i][j]=(grid[i-1][j]+grid[i][j-1])%MOD;
			}
		}
	}
	cout<<grid[n-1][n-1];
}
 
int main(){
	solve();
}