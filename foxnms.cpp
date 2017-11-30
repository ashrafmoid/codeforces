#include<bits/stdc++.h>
using namespace std;
clr[30];
char s[105][105];
vector<int> v[30];
int vis[30];//for book keeping of ans printing
int main(){
  memset(clr,'W',clr);
  int n;cin>>n;
  int len[n];
  for(int i=0;i<n;i++){cin>>s[i];len[i]=strlen(s[i]);}
  for(int  i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      int k=0;int minn=min(len[i],len[j]);
      while(k<minn&&s[i][k]==s[j][k]){k++;}
      if(k<minn)v[s[i][k]-'a'].push_back(s[j][k]-'a');
    }
  }
  if(!dfs()){cout<<"Impossible\n";}
  else{
    //do topological sorting
  }
  return 0;
}
