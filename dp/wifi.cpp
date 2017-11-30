#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<limits>
using namespace std;
//long double  trgt=0.0;long double counts=0.0;
//vector<int>v;
int main(){
  long long int fact[11];
  fact[0]=1;
  for(int i=1;i<11;i++)fact[i]=i*fact[i-1];
  string s1,s2;
  cin>>s1>>s2;
  int len=s1.size();
  int sp=0,sn=0,tp=0,tn=0;
  for(int i=0;i<len;i++){
    if(s1[i]=='+')sp++;
    else if(s1[i]=='-')sn++;
    if(s2[i]=='+')tp++;
    else if(s2[i]=='-')tn++;
  }
  cout.precision(14);
  int remp,remn;
  remp=sp-tp;
  remn=sn-tn;
  double pwr=1.0;
  for(int i=0;i<len-tp-tn;i++)pwr=pwr*2;
  long double ans;
  if(remp<0||remn<0)cout<<"0.000000000000";
  else if(remp==0&&remn==0)cout<<"1.000000000000";
  else{
   ans=double ((fact[remp+remn]/(fact[remp]*fact[remn]))/pwr);
  //ans=double(3/8);
    cout<<ans;
  }
  return 0;
}
