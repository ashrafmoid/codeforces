#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    long long int ans=0;
    int a[n],s[n];
    for(int i=0;i<n;i++){cin>>s[i]>>a[i];}
    ans=s[0];long long int temp=ans;
    for(int i=1;i<n;i++){
      if(ans-s[i]<0){ans=s[i];continue;}
        temp=(ans-s[i])/a[i] +1;
        ans=a[i]*temp+s[i];
    }
    cout<<ans<<"\n";
    return 0;
}
