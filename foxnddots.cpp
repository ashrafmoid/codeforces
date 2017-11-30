#include<bits/stdc++.h>
using  namespace std;
//int vis[60][60];
char clr[60][60];
//string s[60];
char s[60][60];
  int n,m;
bool dfs(int x,int y,int prntx,int prnty){
  clr[x][y]='G';
  bool b=false;
  if(x+1<n&&clr[x+1][y]=='G'&&s[x+1][y]==s[x][y]&&!(x+1==prntx && y==prnty))return true;
  if(x>0&&clr[x-1][y]=='G'&&s[x-1][y]==s[x][y]&&!(x-1==prntx && y==prnty))return  true;
  if(y+1<m&&clr[x][y+1]=='G'&&s[x][y+1]==s[x][y]&&!(x==prntx && y+1==prnty))return true;
  if(y>0&&clr[x][y-1]=='G'&&s[x][y]==s[x][y-1]&&!(x==prntx && y-1==prnty))return true;
  if(x+1<n&&clr[x+1][y]=='W'&&b==false&&s[x+1][y]==s[x][y]){b=dfs(x+1,y,x,y);}
  //if(b)return b;
  //if(!b){
    if(x>0&&clr[x-1][y]=='W'&&b==false&&s[x-1][y]==s[x][y]){b=dfs(x-1,y,x,y);}
    //if(b)return b;
    //else if(!b){
      if(y>0&&clr[x][y-1]=='W'&&b==false&&s[x][y-1]==s[x][y]){b=dfs(x,y-1,x,y);}
      //if(b)return b;
      if(y+1<m&&clr[x][y+1]=='W'&&b==false&&s[x][y+1]==s[x][y]){b=dfs(x,y+1,x,y);}
      clr[x][y]='B';
      return b;
    //}
  //}
}
int main(){
//  memset(vis,0,sizeof(vis));
  memset(clr,'W',sizeof(clr));
  cin>>n>>m;
  for(int i=0;i<n;i++)cin>>s[i];
  int flag=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      //if(i==j)
      flag=0;
    if(clr[i][j]!='W')continue;
    if(dfs(i,j,i,j)) {flag=1;break;}
  }
  if(flag==1)break;
  }
  if(flag==1){cout<<"Yes\n";}
  else {cout<<"No\n";}
//  cout <<"hey\n";
  return 0;
}
