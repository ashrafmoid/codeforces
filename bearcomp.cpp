#include<iostream>
#include<algorithm>
#include<cstring>
#include<limits>
#include<string>
using namespace std;
int q;
long int dp[8][8];
/*typedef struct node{
  string a,b;
}node;*/
//node qry[40];
long int solve(int n,int lstchr,char a[][3],char b[][2]){
  if(n==0)return 1;
  if(dp[n][lstchr]!=-1)return dp[n][lstchr];
  long int x=0;
  for(int i=0;i<q;i++){
    if(b[i][0]-'a'==lstchr){
      x+=solve(n-1,a[i][0]-'a',a,b);
    }
  }
  dp[n][lstchr]=x;
  return x;
}
int main(){
  int n;cin>>n>>q;
  memset(dp,-1,sizeof(dp));
  char a[40][3],b[40][2];
  for(int i=0;i<q;i++){
    cin>>a[i]>>b[i];
  }
  /*for(int i=0;i<q;i++){
    cout<<a[i]<<" "<<b[i]<<"\n";
  }*/
  cout<<solve(n-1,0,a,b)<<"\n";
  return 0;
}
