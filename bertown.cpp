#include<bits/stdc++.h>
using namespace std;
int visit[100001];
int a[100001];
int f[100001];
int main(){
  memset(visit,0,sizeof(visit));
  int n;cin>>n;
  //pair<int,int> p[n+1];
  for(int i=1;i<n+1;i++){
    //int x;cin>>x;x;p[i]=make_pair(i,x);
    cin>>a[i];
  }
  queue<int> qy;
  int j=0;
  long long int ans=0;long long int cnt,max1=0,max2=0;
  for(int i=1;i<n+1;i++){
    cnt=0;
    if(visit[i]==1)continue;
    qy.push(i);cnt++;visit[i]=1;
    while(!qy.empty()){
      int u=qy.front();qy.pop();
      if(visit[a[u]]==0){visit[a[u]]=1;cnt++;qy.push(a[u]);}
    }
    if(cnt>=max1){max2=max1;max1=cnt;}
    else if(cnt>max2)max2=cnt;
    //else if(cnt>max2){max2=cnt;}
    ans+=cnt*cnt;
    //f[j++]=cnt;
  }
  //sort(f,f+j);
//  max1=f[j-1];max2=f[j-2];
  cout<<(ans+2*max1*max2);
  return 0;
}
