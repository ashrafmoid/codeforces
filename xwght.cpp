#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
bool get_ans(string& s,int left,int right,int indx,int limit){
    if(indx==0)return true;
    for(int i=0;i<10;i++){
      if(s[i]!='0'&&indx){

      }
    }
}
int main(){
  string s;
  cin>>s;
  int m;cin>>m;
  if(get_ans(s,0,0,m)==true)cout<<"YES";
  else cout<<"NO";
  return 0;
}
