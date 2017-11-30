#include<iostream>
#include<algorithm>
#include<cstring>
#include<limits>
using namespace std;
typedef long long ll;
int decide(int status,int a,int b){
    if(status==0){
      if(a==b)return 0;
      else if(a<b)return 1;
      else return 2;
    }
    return status;
}
long long int dp[80][3][3][3];
  long long int l,r;
long long int INF=numeric_limits<ll>::min() ;
long long int solve(int bits,int la,int ab,int br){
    if(bits<0){
      if(la<2&&ab<2&&br<2)return 0;
      return INF;
    }
    if(dp[bits][la][ab][br]!=-1)return dp[bits][la][ab][br];
    long long int sum=1,maxx=INF;
    //dp[bits][la][ab][br]=INF;
    for(int i=0;i<2;i++){
      sum=1;
      for(int j=0;j<2;j++){
        //if(solve(bits-1,decide(la,(l>>bits)&1,i),decide(ab,i,j),decide(br,(r>>bits)&1,j))!=INF){}
        if(i!=j)
        maxx=max(maxx,(sum<<bits)+solve(bits-1,decide(la,(l>>bits)&1,i),decide(ab,i,j),decide(br,j,(r>>bits)&1)));
        else
              maxx=max(maxx,solve(bits-1,decide(la,(l>>bits)&1,i),decide(ab,i,j),decide(br,j,(r>>bits)&1)));
      }
    }
    dp[bits][la][ab][br]=maxx;
    return maxx;
}
int main(){
  memset(dp,-1,sizeof(dp));
  cin>>l>>r;
  long long int temp=1;
  int bits=1;
  while((temp<<bits)<r){
    bits++;
  }
  cout<<solve(bits,0,0,0);
  return 0;
}
