#include<iostream>
#include<algorithm>
#include<cstring>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int main(){
  int n;cin>>n;
  long int a[n];
  rep(i,0,n)cin>>a[i];
  int visit[n];memset(visit,0,sizeof(visit));
  int l=0,r=n-1,cnt=0;int flag=0;
  while(l<=r){
    //if(visit[i]==1)break;
    if(l>r)break;
    if(l==r){cnt++;break;}
    visit[l]=1;visit[r]=1;
    l++;r--;cnt++;
    while(l<n&&a[l]==1&&visit[l]==0){l++;visit[l]=1;}
    //if(visit[])
    while(r>=0&&a[r]==1&&visit[r]==0){r--;visit[r]=1;}
  }
  cout<<cnt<<"\n";
  return 0;
}
