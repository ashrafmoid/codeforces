#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
  long long int n;cin>>n;
  long long int temp;int flag=0;
  double sqr;
  for(int i=1;i<100000&&i*(i+1)<2*n;i++){
    temp=i*(i+1);
    temp=2*n-temp;
    sqr=sqrt(4*temp+1);
  //  cout<<i<<"\n";
    if(ceil(sqr)-floor(sqr)==0.0){
      flag=1;break;
    }
  }
  if(flag)cout<<"YES";
  else cout<<"NO";
  return 0;
}
