#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
  string s;
  int minn=999999;
  cin>>s;
  int len=s.size();
  int lwr[len];lwr[0]=0;
  for(int i=0;i<len;i++){
    if(s[i]>=97){
      if(i>0)
      lwr[i]=1+lwr[i-1];
      else lwr[i]=1;
    }
  else   if(i>0) 
    lwr[i]=lwr[i-1];
  }
  for(int i=0;i<len;i++){
    minn=min((2*lwr[i]-lwr[len-1]+len-1-i),minn);
  }
  minn=min(min(lwr[len-1],len-lwr[len-1]),minn);
  cout<<minn;
  return 0;
}
