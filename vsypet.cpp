#include<bits/stdc++.h>
using namespace std;
int vis[1001];
int primes[1001];
vector<int>prms;
int main(){
  for(int i=2;i<1001;i++){
    if(vis[i]==0){
      vis[i]=1;
      primes[i]=1;
      prms.push_back(i);
      int j=2*i;
      while(j<1001){vis[j]=1;j=j+i;}
    }
  }
  int len=prms.size();
  int n;cin>>n;
  vector<int> ans;int cnt=0;
  for(int i=2;i<=n;i++){
  //  int cnt=0;
    if(primes[i]){cnt++;ans.push_back(i);}
    else {
      for(int k=0;k<len;k++){
        int temp=i;
        while(temp%prms[k]==0){temp=temp/prms[k];}
        if(temp==1){ans.push_back(i);cnt++;break;}
        //if(i%prms[k]==0&&(primes[i/prms[k]]==0||i==prms[k]*prms[k])){cnt++;ans.push_back(i);break;}
      }
    }
  }
  cout<<cnt<<"\n";
  for(int i=0;i<ans.size();i++){cout<<ans[i]<<" ";}
  return 0;
}
