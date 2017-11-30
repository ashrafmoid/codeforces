#include<iostream>
#include<algorithm>
#include<cstring>
#include<stdio.h>
using namespace std;
double cache[2001][2001];
double p;
/*double solve(int req,int t,int n){
  if(req==0&&(n==0||t==0))return 1.0;
  if(req!=0&&(n==0||t==0))return 0.0;
  if(cache[req][t]!=-1.0)return cache[req][t];
  if(req>0)
  cache[req][t]=p*solve(req-1,t-1,n-1)+(1-p)*solve(req,t-1,n);
  else cache[req][t]=(1-p)*solve(req,t-1,n);
  return cache[req][t];
}*/
int main(){
  for(int i=0;i<2001;i++){
    for(int j=0;j<2001;j++)cache[i][j]=0.0;
  }
  cache[0][0]=1.0;
  int n,t;
  cin>>n>>p>>t;
/*  if(p==1.0){
    cout<<(double) min(n,t);return 0;
  }*/
  double ans=0.0;
  for(int i=1;i<=t;i++){
    for(int j=0;j<=n;j++){
      if(j==n){
        cache[i][j]+=cache[i-1][j];
        continue;
      }
      cache[i][j]+=cache[i-1][j]*(1-p);
      cache[i][j+1]+=cache[i-1][j]*p;
    }
  }
  for(int i=0;i<=n;i++){
    ans+=cache[t][i]*i;
  }
  //cout<<ans;
  printf("%.100lf",ans);
  return 0;
}
