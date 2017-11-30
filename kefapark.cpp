#include<bits/stdc++.h>
using namespace std;
int a[100001];
vector<int> v[100001];
char clr[100001];
int m,ans=0;
void dfs(int root,int sum){
  clr[root]='G';
  if(sum>m)return ;
  int len=v[root].size();
  if(len==1&&root!=1){
    ans++;return ;
  }
  for(int i=0;i<len;i++){
    if(clr[v[root][i]]=='G')continue;
    if(a[v[root][i]]==1)
    dfs(v[root][i],sum+1);
    else{
      dfs(v[root][i],0);
    }
  }
  return ;
}
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;cin>>n>>m;
  for(int i=1;i<n+1;i++){cin>>a[i];clr[i]='W';}
  for(int i=0;i<n-1;i++){
    int x,y;cin>>x>>y;v[x].push_back(y);v[y].push_back(x);
  }
  int sum=0;
  if(a[1]==1)sum++;
  dfs(1,sum);
  cout<<ans;
  return 0;
}
