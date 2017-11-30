#include<iostream>
#include<algorithm>
#include<stack>
#include<string>
using namespace std;
int main(){
  int count[1000001];
  for(int i=0;i<1000001;i++){count[i]=0;}
  stack<int>  open;
  stack<int> close;
  long int len=0,i=0,maxx=0,slen;
  string s;cin>>s;
  slen=s.size();
  while(i<slen){
    if(s[i]=='(')open.push(i);
    else close.push(i);
    i++;
  }
  int dmyop=open.top(),dmycl=close.top();
  while(!open.empty()&&(!close.empty())){
    if(open.top()==close.top()+1){
      len+=2;count[len]++;maxx=max(len,maxx);
      open.pop();close.pop();
    }
    else if(open.top()>close.top()){
      len=0;open.pop();
    }
    else{
      len=0;close.pop();
    }
  }
  if(maxx==0){
    cout<<"0 1";return 0;
  }
  cout<<maxx<<" "<<count[maxx];
  return 0;
}
