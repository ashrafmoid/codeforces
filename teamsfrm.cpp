#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int main(){
  long int n;long long int  k,m,tot;
  cin>>n>>k>>m;tot=n*m;
  int a[n];long long int ans=0;int b[n+1];
  for(int i=0;i<n;i++)cin>>a[i];
  if(n==1){
    cout<<m-(m/k)*k;
    return 0;
  }
  if(k==1){cout<<"0";return 0;}
  int lt[n];
  int l=0,r=n-1,i,j=0;
  int cnt=0;
  while(l<n){
    i=l;
    cnt=0;
    while(l<n&&a[i]==a[l]){l++;cnt++;}
    if(j>0&&b[j-1]==a[i]){
      if((lt[j-1]+cnt)%k==0){
        ans+=(lt[j-1]+cnt)*m;j--;
      }
      else{
        ans+=((lt[j-1]+cnt)/k)*k*m;
        lt[j-1]=(lt[j-1]+cnt)%k;
      }
      continue;
    }
    ans=ans+m*(cnt/k)*k;
    if(cnt%k!=0){
      lt[j]=cnt%k;b[j]=a[i];
        j++;
      }
  }
  j--;
  l=0;r=j;
  while(l<r){
    cnt=0;
    if(b[l]!=b[r])break;
    cnt+=lt[l];l++;
    cnt+=lt[r];r--;
    ans=ans+(cnt/k)*k*(m-1);
    if(cnt%k!=0)break;
  }
  cnt=0;
  if(l==r){
    cnt+=lt[l];
    if((cnt*m)%k==0)ans=tot;
    else{
      ans=ans+((cnt*m)/k)*k;
    }
  }
  cout<<tot-ans;
  return 0;
}
