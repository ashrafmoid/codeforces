#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long int v;cin>>v;
  int a[10];
  for(int i=1;i<10;i++)cin>>a[i];
  long int* res=(long int*)malloc((v+1)*sizeof(long int));
  int* ans=(int*)malloc((v+1)*sizeof(int));
  res[0]=0;
  for(long int i=1;i<=v;i++){
    res[i]=0;
    ans[i]=0;
    for(int j=1;j<10;j++){
      if(i>=a[j]){
        if(res[i]<=1+res[i-a[j]]){
          res[i]=1+res[i-a[j]];
          ans[i]=j;
        }
      }
    }
  }
  if(res[v]==0){cout<<"-1";return 0;}
  for(long int i=v;i>0&&ans[i]>0;){
    cout<<ans[i];
    i=i-a[ans[i]];
  }
  return 0;
}
