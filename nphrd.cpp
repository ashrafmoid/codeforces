#include<bits/stdc++.h>
using namespace std;
//pair<int,int> p[1000005];
//int vis[1000005];
char clr[100005];
vector<int> adj[100005];
vector<int> v1;
vector<int> v2;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	memset(clr,'w',sizeof(clr));
	//memset(vis,0,sizeof(vis));
	int n,m;int flag=0;
	
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		adj[x].push_back(y);adj[y].push_back(x);
	}
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(clr[i]!='w')continue;
		if(adj[i].empty())continue;
		q.push(i);clr[i]='r';v1.push_back(i);
		while(!q.empty()){
			int u=q.front();q.pop();
			for(int i=0;i<adj[u].size();i++){
				if(clr[adj[u][i]]=='w'){
					if(clr[u]=='r'){clr[adj[u][i]]='b';v2.push_back(adj[u][i]);}
					else {clr[adj[u][i]]='r';v1.push_back(adj[u][i]);}
					q.push(adj[u][i]);
				}
				else if(clr[adj[u][i]]==clr[u]){flag=1;}
			}
		}
		if(flag)break;
	}
	if(flag){cout<<"-1\n";return 0;}
	cout<<v1.size()<<"\n";
	for(int i=0;i<v1.size();i++)cout<<v1[i]<<" ";
	cout<<"\n"<<v2.size()<<"\n";
	for(int i=0;i<v2.size();i++)cout<<v2[i]<<" ";
	return 0;
}