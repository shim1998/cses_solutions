#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n,m;
	cin>>n>>m;
	vector< vector< pair<int,int> > >adj(n+1);
	for(int i=0;i<m;i++){
		int u,v,p;
		cin>>u>>v>>p;
		adj[u].push_back({p,v});
	}
	priority_queue<pair<long long int,int>, vector<pair<long long int,int>>, greater<pair<long long int,int>>>q;
	q.push({0,1});
	vector<long long int>dist(n+1,LONG_MAX);
	dist[1]=0;
	while(!q.empty()){
		auto v=q.top();
		q.pop();
		if(v.first!=dist[v.second])
			continue;
		for(auto u: adj[v.second]){
			if(dist[v.second]+u.first<dist[u.second]){
				dist[u.second]=dist[v.second]+u.first;
				q.push({dist[u.second],u.second});
			}
		}
	}
	for(long long int i=1;i<n+1;i++) cout<<dist[i]<<' ';
}
 
int main(){
	solve();
}