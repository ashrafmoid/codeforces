#include<bits/stdc++.h>
using namespace std;
long long int a[300001];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long   int n;cin>>n;
    long long int sum=0;
    for(long long int i=0;i<n;i++){
      cin>>a[i];sum+=a[i];
    }
    sort(a,a+n);
    for(long long int i=0;i<n-1;i++){
      sum+=(i+1)*a[i];
    }
    sum+=(n-1)*a[n-1];
    cout<<sum;
    return 0;
}
