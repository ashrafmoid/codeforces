#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;long long int k;
  cin>>n>>k;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  if(k>=n){
    cout<<n;return 0;
  }
  int flag=0;
  int f[n+1];int maxx=0;
  memset(f,0,sizeof(f));
  for(int i=0;i<n;i++){
    int j=i+1;
    if(a[i]<maxx)continue;
     maxx=max(a[i],maxx);
     if(i>0)
     f[a[i]]++;
    while(j<n&&a[j]<a[i]){
      f[a[i]]++;j++;
    }
    if(f[a[i]]>=k){cout<<a[i];flag=1;break;}
  }
  if(flag==0)
  cout<<n;
  //for(int i=0;i<n)
  return 0;
}
