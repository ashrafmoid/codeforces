#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  /*int f[200];
  memset(f,0,sizeof(f));
  for(int i=0;i<200;i++){
    if(i%4==0)f[i]=1;
  }*/
  string s;cin>>s;long long int res=0;
  int len=s.size();
  for(int i=len-1;i>=0;i--){
    if(i>0&&(s[i]-'0'+(s[i-1]-'0')*10)%4==0){
      res+=i;
    }
    if((s[i]-'0')%4==0){
      res++;
    }
  }
  cout<<res<<"\n";
  return 0;
}
