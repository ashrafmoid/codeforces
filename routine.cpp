#include<iostream>
#include<algorithm>
using namespace std;
int hcf(int a,int b){
  if(a==0)return b;
  if(b==0)return a;
  return hcf(b,a%b);
}
int main(){
  int a,b,r,s;
  cin>>a>>b>>r>>s;
  int numr,denm;numr=r*b;denm=s*a;
  int divs=1;
  if(numr>denm){
    divs=hcf((numr-denm),numr);
    cout<<(numr-denm)/divs<<"/"<<numr/divs;
  }
  else if(numr<denm){
    divs=hcf(denm-numr,denm);
    cout<<(denm-numr)/divs<<"/"<<denm/divs;
  }
  else{
    cout<<"0/1";//return 0;
  }
  //cout<<"\n"<<divs;
  return 0;
}
