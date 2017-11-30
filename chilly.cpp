#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int main(){
  int n;cin>>n;
  if(n<3){cout<<"-1\n";return 0;}
  if(n==3){cout<<"210\n";return 0;}
  int f[500];
  memset(f,0,sizeof(f));
  for(int  i=20;i<500;i=i+30){
    f[i]=i%7;
  }
  int rem[7];
  rem[0]=1;rem[1]=3;rem[2]=2;rem[3]=6;rem[4]=4;rem[5]=5;
  int c1=rem[(n-1)%6];
  int i;
  for( i=20;i<500;i=i+30){
    if(c1+f[i]==7)break;
  }
  int digits=0,temp=i;
  while(temp>0){
    digits++;temp=temp/10;
  }
  cout<<"1";
  for(int i=2;i<=n-digits;i++)cout<<"0";
  cout<<i<<"\n";
}
