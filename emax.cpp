#include<iostream>
#include<algorithm>
#include<limits>
using namespace std;
int main(){
  double r=0.0000000000001;
  //while(r)
  int m,n;cin>>m>>n;
  int digits=0,copy=m;
  while(copy>0){
    digits++;copy=copy/10;
  }
  long double ans=0.0;
  long  double temp;
  for(int i=1;i<m;i++){
    temp=1;
    for(int j=0;j<n&&temp>=r;j++){
      temp=(temp*i)/m;
    }
    ans+=temp;
  }
  ans=double(m-ans);
  cout.precision(12+digits);
  cout<<ans;
  return 0;
}
