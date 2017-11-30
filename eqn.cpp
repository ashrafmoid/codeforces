#include<iostream>
#include<algorithm>
using namespace std;
long long int gpow( int base,int power){
  long long int ans=1;
  while(power>0){
    ans=ans*base;
    power--;
  }
  return ans;
}
int main(){
  int a,b,c;
  int count=0;
  cin>>a>>b>>c;
  int ans=0;
  long long int store[100];
  int sx=1;long long int temp1,temp2;
  while(sx<=81){
    ans=0;
    temp1=gpow(sx,a)*b+c;temp2=temp1;
    while(temp2>0){
      ans=ans+temp2%10;
      temp2=temp2/10;
    }
    if(ans==sx&&temp1<=1000000000){
      count++;store[count-1]=temp1;}
    sx++;
  }
  cout<<count<<endl;
  if(count){
    for(int i=0;i<count;i++){
      if(store[i]<=1000000000){
      cout<<store[i]<<" ";}
    }
  }
  return 0;
}
