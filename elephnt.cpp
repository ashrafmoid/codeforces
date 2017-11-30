#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
  long long int res[19];
  res[0]=0;res[1]=9;res[2]=9;res[3]=90;
  for(int i=4;i<19;i++){
    res[i]=9*pow(10,i-2);
  }
  long long int ans=0;
  long long int l,r;
  cin>>l>>r;
  int dgtlft=0,dgtrt=0;
  long long int templ=l,tempr=r;
  while(templ>0){
    dgtlft++;
    templ=templ/10;
  }
  while(tempr>0){
    dgtrt++;tempr=tempr/10;
  }
  if(dgtrt>1&&r%10>=r/((long long int)pow(10,dgtrt-1))){
    ans+=((r/10-((r/10)/((long long int)pow(10,dgtrt-2)))*pow(10,dgtrt-2))+1);
  }
  //if(dgtrt>1)
  ans+=(r/((long long int )pow(10,dgtrt-1))-1)*(long long int)pow(10,dgtrt-2);
  for(int i=1;i<dgtrt;i++){
    ans+=res[i];
  }
  if(dgtlft>1&&l%10>=l/((long long int)pow(10,dgtlft-1))){
    ans-=((l/10-((l/10)/((long long int)pow(10,dgtlft-2)))*pow(10,dgtlft-2))+1);
  }
  if(dgtlft>1)
  ans-=(l/((long long int )pow(10,dgtlft-1))-1)*(long long int)pow(10,dgtlft-2);
  for(int i=1;i<dgtlft;i++){
    ans-=res[i];
  }
  cout<<ans;
  return 0;
}
