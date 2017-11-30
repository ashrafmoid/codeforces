#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;cin>>n;int maxx=0;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];maxx=max(maxx,a[i]);
    }
    long long int f[maxx+1];
    for(int i=0;i<=maxx;i++)f[i]=0;
    for(int i=0;i<n;i++){
        f[a[i]]++;
    }
    long long int ans[maxx+1];ans[0]=0;
    for(int i=1;i<=maxx;i++){
          if(i==1){
            ans[i]=max(ans[i-1],f[i]*i);
          }
          else if(i==2){
            ans[i]=max(ans[i-1],ans[i-2]+f[i]*i);
          }
          else {
            ans[i]=max(ans[i-1],ans[i-2]+f[i]*i);
          }
    }
    cout<<ans[maxx]<<endl;
    return 0;
}
