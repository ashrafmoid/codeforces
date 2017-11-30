#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
  return a>b;
}
int main(){
    long int sum=0;
    int n,m,k;
    cin>>n>>m>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a,a+n,cmp);
    for(int i=0;i<min(n,k);i++)sum+=a[i];
    if(sum-n+k<m){
        cout<<"-1";return 0;
    }
    //k=k-min(n,k);
    int ans=0,i=0;
    long int temp=0;
    while(m>k&&i<n){
        /*if(i<n){
            m=m-a[i++];ans++;
        }
        else{
            ans+=min(m,k-n);
        }*/
        if(k>0){
          m=m-a[i++];k--;ans++;
        }
        else{
          m=m-a[i++]+1;ans++;
        }
    }
    if(m>k){
      cout<<"-1";return 0;
    }
    cout<<ans;
    return 0;
}
