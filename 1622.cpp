#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
 
int n, freq[26];
string s;
void permute(vector<string>& st, string curr){
	if(s.size()==curr.size()){
		st.push_back(curr);
		return;
	}
	for(int i=0;i<26;i++){
		if(freq[i]>0){
			freq[i]--;
			permute(st,curr+(char)(i+'a'));
			freq[i]++;
		}
	}
}

void solve(){
	cin>>s;
	for(char c:s) freq[c-'a']++;
	vector<string> st;
	permute(st,"");
	cout<<st.size()<<'\n';
	for(string ans:st){
		cout<<ans<<'\n';
	}
}
 
int main(){
	solve();
}