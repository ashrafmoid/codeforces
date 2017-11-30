#include<bits/stdc++.h>
using namespace std;
vector<int> v[101];
int a[101];
int visit[101];
int prnt[101];
int main(){
  int cnt=0;
  memset(visit,0,sizeof(visit));
  int n,m;cin>>n>>m;
  for(int i=0;i<n;i++){
    int k;cin>>k;//int x;
    if(k==0)cnt++;
    else {
      for(int i=0;i<k;i++){
        cin>>a[i];
      }
      sort(a,a+k);
      for(int i=0;i<k;i++){
        if(visit[i]==0){prnt[i]=a[0];visit[i]=1;}
      }
    }
  }
}
