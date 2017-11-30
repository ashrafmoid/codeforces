#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
  string s1,s2;
  string s;string m;
  cin>>s1>>s2;
  int len1,len2;
  len1=s1.size();len2=s2.size();
  int anslen=1;int minlen=min(len1,len2);int flag=0;int maxlen=max(len1,len2);
  if(len1==minlen){
    s=s1;m=s2;
  }
  else{
    s=s2;m=s1;
  }
  for(;anslen<=minlen/2;anslen++){
    if(minlen%anslen!=0)continue;
  //  flag=0;
    int i;
    for(i=0;i<anslen;i++){
      int temp=i;
      char c=s[i];
      while(temp<minlen&&c==s[temp]){
        temp+=anslen;
      }
      if(temp<minlen){break;}
    }
    if(i==anslen){
      flag=1;
      break;
    }
  }
  if(flag!=1){
    anslen=minlen;
    if(maxlen%anslen!=0){
      cout<<"0";return 0;
    }
    int i;
    for(i=0;i<anslen;i++){
      int temp=i;
      char c=s[i];
      while(temp<maxlen&&c==m[temp]){
        temp+=anslen;
      }
      if(temp<maxlen){
        cout<<"0";return 0;
      }
    }
    if(i==anslen){
      cout<<"1";return 0;
    }
  }
  for(int i=0;i<anslen;i++){
    int temp=i;
    char c=s[i];
    while(temp<maxlen&&c==m[temp]){
      temp+=anslen;
    }
    if(temp<maxlen){
      cout<<"0";return 0;
    }
  }
  int ans=0;
  for(int i=anslen;i<=minlen;i=i+anslen){
    if(minlen%i==0&&maxlen%i==0)ans++;
  }
  cout<<ans;
  return 0;
}
