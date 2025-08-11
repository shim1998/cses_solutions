#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
 
void solve(){
	int n;
	cin>>n;
	vector<vector<int>>customers;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		customers.push_back(vector<int>({a,b,i}));
	}
	sort(customers.begin(),customers.end());
    priority_queue<pair<int, int>, vector<pair<int, int> >,
                greater<pair<int, int> > >
        occupiedRooms;
    int roomCnt = 0;
    vector<int>ans(n);
    for(int i=0;i<n;i++){
    	int at=customers[i][0],dep=customers[i][1],idx=customers[i][2];
    	if(occupiedRooms.empty() or occupiedRooms.top().first>=at){
    		roomCnt++;
    		occupiedRooms.push({dep,roomCnt});
    		ans[idx]=roomCnt;
    	}
    	else{
    		int vac = occupiedRooms.top().second;
    		occupiedRooms.pop();
    		occupiedRooms.push({dep,vac});
    		ans[idx] = vac;
    	}
    }
    cout<<roomCnt<<'\n';
    for(int i: ans) cout<<i<<" ";
}
 
int main(){
	solve();
}