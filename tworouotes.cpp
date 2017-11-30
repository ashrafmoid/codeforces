#include<bits/stdc++.h>
using namespace std;
int adj[500][500];
queue<int> qy;
void bfs(int* dis,vector<vector<int> > *v){
	int visit[500];memset(visit,0,sizeof(visit));
	visit[1]=1;qy.push(1);
	while(!qy.empty()){
		int u=qy.front();qy.pop();
		for(int i=0;i<v->at(u).size();i++){
			if(visit[v->at(u).at(i)]==0){
				visit[v->at(u).at(i)]=1;qy.push(v->at(u).at(i));dis[v->at(u).at(i)]=1+dis[u];
			}
		}
	}
	return ;
}
void modify(int* source,int* dest,vector<vector<int> > *v){
	int visit[500];memset(visit,0,sizeof(visit));
	visit[1];source[1]=0;
	qy.push(1);
	while(!qy.empty()){
		int u=qy.front();qy.pop();
		for(int i=0;i<v->at(u).size();i++){
			if(visit[v->at(u).at(i)]==0){
				if(source[v->at(u).at(i)]==dest[v->at(u).at(i)]){
					source[v->at(u).at(i)]+=2;
				}
				visit[v->at(u).at(i)]=1;qy.push(v->at(u).at(i));
			}
		}
	}
	return ;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	vector<vector<int> > rail(500,vector<int>(500));
	vector<vector<int> > road(500,vector<int> (500));
	int dis1[500];int dis2[500];
	memset(dis1,-1,sizeof(dis1));
	memset(dis2,-1,sizeof(dis2));
	int n,m;cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		rail[x].push_back(y);rail[y].push_back(x);
		adj[x][y]=adj[y][x]=1;
	}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<n+1;j++){
			if(adj[i][j]==0){road[i].push_back(j);road[j].push_back(i);}
		}
	}
	dis1[1]=0;dis2[1]=0;
	vector<vector<int> > *temp;temp=&rail;
	bfs(dis1,temp);temp=&road;bfs(dis2,temp);
	if(dis1[n]==-1||dis2[n]==-1){cout<<"-1\n";return 0;}
	int chn=0;
	if(dis1[n]>dis2[n]){temp=&road;modify(dis2,dis1,temp);}
	else {temp=&rail;modify(dis1,dis2,temp);}
	cout<<max(dis1[n],dis2[n])<<"\n";
	return 0;
}