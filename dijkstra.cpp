#include<bits/stdc++.h>
using namespace std;
vector<pair<long int,int> >v[100001];
int vis[100001];
int parent[100001];
long int INF=numeric_limits<long int>::max();
void print(int src,int target){
	if(src==target){printf("%d ",parent[src]);return;}
	print(src,parent[target]);
	printf("%d ",target);
	return ;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	long int dis[100001];
	for(int i=0;i<100001;i++){dis[i]=INF;vis[i]=0;parent[i]=-1;}
	int n,m;cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;long int w;cin>>a>>b>>w;
		v[a].push_back(make_pair(w,b));
		v[b].push_back(make_pair(w,a));
	}
	multiset <pair<long int,int> >s;
	s.insert(make_pair(0,1));vis[1]=1;dis[1]=0;parent[1]=1;
	while(!s.empty()){
		pair<long int,int> p=*s.begin();
		s.erase(s.begin());
		int u=p.second;
		vis[u]=1;
		for(int i=0;i<v[u].size();i++){
			if(vis[v[u][i].second]==0&&dis[v[u][i].second]>dis[u]+v[u][i].first){
				dis[v[u][i].second]=dis[u]+v[u][i].first;parent[v[u][i].second]=u;
				s.insert(make_pair(dis[v[u][i].second],v[u][i].second));
			}
		}	
	}
	if(dis[n]==INF){cout<<"-1";return 0;}
	print(1,n);
	//s.free()
	return 0;
}