#include<bits/stdc++.h>
using namespace std;
int has[100001];
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  map<string,int> mp;
  int n;cin>>n;string s;
  for(int i=0;i<n;i++){
    cin>>s;
    if(!mp.empty()&&mp.find(s)!=mp.end()){
      cout<<s<<has[mp[s]]<<"\n";
      has[mp[s]]++;
    }
    else {
      mp.insert(make_pair(s,i));
      has[i]++;cout<<"OK\n";
    }
  }
  return 0;
}
