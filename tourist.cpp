#include<iostream>
#include<algorithm>
using namespace std;
/*bool cmp(long int a,long int b){
    return a>b;
}*/
long long int hcf(long long int a,long long int b){
    if(a%b==0)return b;
    return hcf(b,a%b);
}
int main(){
    int n;cin>>n;
  long   long int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    long long int ans=0,sleft=0;
    for(int i=0;i<n;i++){
      if(i>0)
      sleft+=a[i-1];
        ans+=2*(i*a[i]-sleft);
        //cout<<ans<<"\n";
    }
    ans+=sleft+a[n-1];
    long long int x=n;
    x=hcf(x,ans);
    cout<<ans/x<<" "<<n/x;
    return 0;
}
