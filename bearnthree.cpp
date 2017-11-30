#include<bits/stdc++.h>
using namespace std;
int has[4001];
int INF=numeric_limits<int>::max();
int main(){
  int n,m;cin>>n>>m;
  int ans=INF;
  pair<int,int> p[4000];
  memset(has,0,sizeof(has));
  int adj[n+1][n+1];
  memset(adj,0,sizeof(adj));
  for(int i=0;i<m;i++){
    int x,y;cin>>x>>y;p[i]=make_pair(x,y);
    adj[x][y]=1;adj[y][x]=1;
    has[x]++;has[y]++;
  }
  for(int i=0;i<m;i++){
    int x=p[i].first;int y=p[i].second;
    for(int j=1;j<n+1;j++){
      if(j==x||j==y)continue;
      if(adj[x][j]==1&&adj[y][j]==1){
        ans=min(ans,has[x]+has[y]+has[j]-6);
      }
    }
  }
  if(ans==INF)cout<<"-1";
  else 
  cout<<ans;
  return 0;
}
