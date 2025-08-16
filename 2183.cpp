#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n,m;
	cin>>n>>m;
	vector< vector< pair<int,int> > >adj(n+1);
	for(int i=0;i<m;i++){
		int u,v,p;
		cin>>u>>v>>p;
		adj[u].push_back({v,p});
	}
	queue<pair<int,int>>q;
	q.push({1,0});
	vector<int>dist(n+1,INT_MAX);
	dist[1]=0;
	while(!q.empty()){
		auto v=q.front();
		q.pop();
		for(auto u: adj[v.first]){
			if(dist[v.first]+u.second<dist[u.first]){
				dist[u.first]=dist[v.first]+u.second;
				q.push({u.first,dist[u.first]});
			}
		}
	}
	for(int i=1;i<n+1;i++) cout<<dist[i]<<' ';
}
 
int main(){
	solve();
}