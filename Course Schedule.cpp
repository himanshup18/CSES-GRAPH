#include <bits/stdc++.h>
using namespace std;
#define int long long
int e=1e-9;
int32_t main() {
	int n,m;
	cin>>n>>m;
	vector<vector<int>> adj(n+1);
	vector<int> indeg(n+1);
	vector<int> outdeg(n+1);
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		indeg[b]++;
		outdeg[a]++;
	}
 
	queue<int> q;
	vector<int> topo;
	for(int i=1;i<=n;i++){
		if(indeg[i]==0){
			q.push(i);
			
		}
	}
	bool h=1;
	while(!q.empty()){
		int p=q.front();
		topo.push_back(p);
		q.pop();
		for(auto it:adj[p]){
			indeg[it]--;
			if(indeg[it]==0){
			
				q.push(it);
			}
		}
	}
	if(topo.size()==n){
		for(int i=0;i<n;i++){
			cout<<topo[i]<<" ";
		}
		cout<<endl;
	}
	else{
		cout<<"IMPOSSIBLE"<<endl;
	}
	
	
}