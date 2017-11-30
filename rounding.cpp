#include<iostream>
#include<algorithm>
#include<cmath>
#include<limits>
#include<iomanip>
#include<stdio.h>
int getdgt(int num){
  int i=0;
    for(;num>0;num=num/10){
      i++;
    }
    return i;
}
using namespace std;
int main(){
  int n;
  cin>>n;
  int cnt=0;
  double x;double decimal[2*n];double res=0;
  for(int i=0;i<2*n;i++){
    cin>>x;
    if(x-floor(x)==0)cnt++;
    else{
      res+=x-floor(x);}
  }
  //int sze=(2*n-cnt)/2;
  int ulmt,llmt;
  if(2*n-cnt<=n)ulmt=2*n-cnt;
  else ulmt=n;
  if(cnt<=n)llmt=n-cnt;
  else llmt=0;
  //double ans[sze+1][sze+1];ans[0][0]=0;
  //for(int i=1;i<=2*sze;i++){
    //for(int j=0;j<=min(sze,i);j++){
      //if(i-j>sze)continue;
      //if(i-j-1<0)continue;
      //ans[i-j][j]=min(decimal[i-1]+ans[i-1-j][j],decimal[i-1]-1+ans[i-j][j-1]);
    //}
  //}
  //res=min(abs(res-sze),abs(res-1-sze));
  double minn=99999.9;
  for(int i=llmt;i<=ulmt;i++){
    minn=min(abs(res-i),minn);
  }
  res=minn;
  int digts=getdgt((int)res);
  if(digts==0)digts++;
//  cout<<res;
//  cout << left << setfill('0') << setw(digts+4) << res << "\n";
  //cout<<res;
  printf("%.3F",res);
  return 0;
}
